#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //pre-load the bg_pic in the constructor
    bg_pic = QPixmap(":/cover/res/cover_pic.jpg");
    showBackground();
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
