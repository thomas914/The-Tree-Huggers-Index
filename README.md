# The-Tree-Huggers-Index

## Authors
- Thomas, LI Ka Chun
- Tim, TSE Wai Chung
- Tony, XU Baixuan

## User Guide
The source code in this repository consists of two components: **Python** and **GUI**.

Under `src/Python` is a collection of python programs that we designed and used to train our model. 
To run the source code, please ensure that `PyTorch`, `NumPy` and `pandas` are installed.

Install pytorch: https://pytorch.org/get-started/locally/<br>
Install pandas: https://pandas.pydata.org/docs/getting_started/install.html<br>
Install numpy: https://numpy.org/install/<br>



Under `src/TheTreeHuggerIndex` is a Qt-based desktop GUI. It takes input from the client and feed it to the trained model. 
The result (an ESG score) is then presented to the user. To construct the source code locally, open the `TheTreeHuggersIndex.pro` file 
(located in `src/TheTreeHuggerIndex`) with QT creator.

Install Qt: https://www.qt.io/download
