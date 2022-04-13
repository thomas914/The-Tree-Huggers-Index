#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent* event);

private slots:
    // override
    //checked parameter is only useful for checkable QAction
    void on_actionNew_Profile_triggered(bool checked = false);
    void on_actionLoad_Profile_triggered(bool checked = false);
    void on_actionSave_Profile_triggered(bool checked = false);
    void on_actionHome_triggered(bool checked = false);
    void on_actionExit_triggered(bool checked = false);

private:
    // Control Components show up related function
    void showBackground(bool isShow = true);

    // Private variables
    Ui::MainWindow *ui;
    QPixmap bg_pic;

    bool isShowBackground; // control if the background tree pic should show up

};
#endif // MAINWINDOW_H
