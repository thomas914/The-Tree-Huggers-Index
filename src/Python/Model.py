import torch
from torch.utils.data import Dataset
from torch.utils.data import DataLoader
import pandas as pd


class MBDataset(Dataset):
    def __init__(self, csv_dir):
        df = pd.read_csv(csv_dir)
        self.x_data = df[['Number Of Employees', 'Market Value',
                          'PE Ratio', 'Consumer Services']].values
        self.mean = self.x_data.mean(axis = 0)
        self.std = self.x_data.std(axis = 0)
        self.x_data = (self.x_data - self.x_data.mean(axis=0)) / self.x_data.std(axis=0)
        self.y_data = df[['ESG Score']].values

    def __len__(self):
        return len(self.y_data)

    def __getitem__(self, idx):
        return self.x_data[idx], self.y_data[idx]
    def Norm(self):
        return self.x_data.mean(axis = 0),self.x_data.std(axis = 0)


def get_data_loader(csv_dir):
    dataset = MBDataset(csv_dir)
    data_loader = DataLoader(dataset=dataset,
                             batch_size=51,
                             shuffle=True,
                             num_workers=0)
    return dataset.mean,dataset.std,data_loader


Mean,Std,Dataset = get_data_loader("Dataset.csv")
Mean = torch.from_numpy(Mean)
Std = torch.from_numpy(Std)
for i in Dataset:
    i[0] = i[0].to(torch.float32)
    i[1] = i[1].to(torch.float32)

from torch import nn
class Model(nn.Module):
    def __init__(self):
        super(Model,self).__init__()
        self.model = nn.Sequential(
        nn.Linear(4,3),
        nn.LeakyReLU(negative_slope=0.0001),
        nn.Linear(3,3),
        nn.LeakyReLU(negative_slope=0.0001),
        nn.Linear(3,1))
    def forward(self,data):
        data = self.model(data)
        return data

from torch import optim
Model = Model()
Optimizer = optim.SGD(Model.parameters(),lr = 0.01)
Loss_Func = nn.MSELoss()

def Training(Model,Loss_Func,Optim,Train_Dataset):
    Loss = 0
    for epoches in range(100):
        for data in Train_Dataset:
            for idx in range(len(data[0])):
                Data = data[0][idx].to(torch.float32)
                ESGscore = data[1][idx].to(torch.float32)
                print(Data)
                print(ESGscore)
                Data_Processed = Model(Data)
                print(Data_Processed)
                Loss = Loss_Func(Data_Processed,ESGscore)
        
                Optim.zero_grad()
                Loss.backward()
                Optim.step()
        return Loss

Training_Loss = Training(Model,Loss_Func,Optimizer,Dataset)
print(Training_Loss)

def Normalize(data):
    for i in range(4):
        data[i] = (data[i]-Mean[i])/Std[i]
    #data = torch.tensor(data,requires_grad = True).to(torch.float32)
    return data.to(torch.float32)

def ESGSCORE(data,model):#function print the answer and return
    #print(model(Normalize(data)))
    return model(Normalize(data))
