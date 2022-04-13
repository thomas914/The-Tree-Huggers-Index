#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include "resultdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //pre-load the bg_pic in the constructor
    bg_pic = QPixmap(":/cover/res/cover_pic.jpg");
    showBackground();

    resultDialog = new ResultDialog(this);

    connect(this, &MainWindow::showResult, resultDialog, &ResultDialog::showResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    if(isShowBackground) // show the background
    {
        p.setCompositionMode(QPainter::CompositionMode_SourceOver);
        p.drawPixmap(0, 0, width(), height(), bg_pic);
    }
    else // clear the background
    {
        p.setCompositionMode(QPainter::CompositionMode_Clear);
        p.drawRect(0, 0, width(), height());

    }
}

void MainWindow::on_actionNew_Profile_triggered(bool checked)
{
    // show input block
    showBackground(false);
}

void MainWindow::on_actionLoad_Profile_triggered(bool checked)
{
    // TODO: react to load profile for users
}

void MainWindow::on_actionSave_Profile_triggered(bool checked)
{

}

void MainWindow::on_actionHome_triggered(bool checked)
{
    showBackground();
}

void MainWindow::on_actionExit_triggered(bool checked)
{
    close();
}

// default value for isShow = true
void MainWindow::showBackground(bool isShow)
{
    if(isShow)
    {
        isShowBackground = true;

        //hide all input components
        ui->inputBlock->setVisible(false);
        ui->buttonBlock->setVisible(false);
    }
    else
    {
        isShowBackground = false;

        //show all input components
        ui->inputBlock->setVisible(true);
        ui->buttonBlock->setVisible(true);
    }


    update();
}

double MainWindow::leakyRelu(double x)
{
    if(x > 0)	return x;
    return 0.0001 * x;
}

double MainWindow::getESGScore(double x1, double x2, double x3, double x4)
{
    x1 = (x1 - 163460.941) / 379449.442;
    x2 = (x2 - 2795.14804) / 5500.91802;
    x3 = (x3 - 8.58921569) / 55.0834142;
    x4 = (x4 - 0.396582822) / 0.262649178;

    double n11 = leakyRelu(1.0135033*x1 + 1.2345738*x2 - 6.452141*x3 + 4.5648273*x4 - 5.4859514);
    double n12 = leakyRelu(0.31725503*x1 + 2.1164956*x2 - 14.882733*x3 + 9.181947*x4 - 12.591677);
    double n13 = leakyRelu(0.847759*x1 + 0.8036155*x2 - 5.4198184 *x3 + 3.3207757*x4 - 4.5928507);

    double n21 = leakyRelu(-0.2458616*n11 - 0.03026359*n12 + 0.11779974*n13 - 0.36948147);
    double n22 = leakyRelu(-15.652485*n11 - 20.366306*n12 - 3.7568526 *n13 - 2.2243917);
    double n23 = leakyRelu(-14.719395*n11 - 18.694027 *n12 - 3.8506098*n13 - 2.2988038);

    double result = -0.5320807 * n21 - 20.618141 * n22 - 20.632715 * n23 + 24.21233;
    return result;
}

void MainWindow::on_pb_create_clicked()
{
    double x1 = ui->dsb_numOfEmp->value();
    double x2 = ui->dsb_marketValue->value();
    double x3 = ui->dsb_peRatio->value();
    double x4 = ui->dsb_ranking->value();

    emit showResult(getESGScore(x1, x2, x3, x4));
}

