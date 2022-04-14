# The-Tree-Huggers-Index

## User Guide
The source code in this repository consists of two components: **Python** and **GUI**.

Under `src/Python` is a collection of python programs that we designed and used to train our model. 
In which `Model.py` is the python program that loads data and train the model. `Dataset.csv` is the dataset we collected to train the model.
To run the source code, please ensure that `PyTorch`, `NumPy` and `pandas` are installed. AND, `Dataset.csv` and `Model.py` must be placed in the same directory.

Install pytorch: https://pytorch.org/get-started/locally/<br>
Install pandas: https://pandas.pydata.org/docs/getting_started/install.html<br>
Install numpy: https://numpy.org/install/<br>



Under `src/TheTreeHuggerIndex` is a Qt-based desktop GUI. It takes input from the client and feed it to the trained model. 
The result (an ESG score) is then presented to the user. To construct the source code locally, open the `TheTreeHuggersIndex.pro` file 
(located in `src/TheTreeHuggerIndex`) with QT creator.

Install Qt: https://www.qt.io/download
