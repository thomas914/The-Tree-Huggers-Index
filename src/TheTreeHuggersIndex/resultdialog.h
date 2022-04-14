#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>
#include <QObject>
#include <QLabel>

class ResultDialog : public QDialog
{
    Q_OBJECT
public:
    ResultDialog(QWidget *parent = nullptr);

public slots:
    void showResult(double result);

private:
    QLabel* lb_result;
};

#endif // RESULTDIALOG_H
