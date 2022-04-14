#include "resultdialog.h"
#include <QWidget>
#include <QLabel>

ResultDialog::ResultDialog(QWidget* parent)
{
    lb_result = new QLabel(this);

}

void ResultDialog::showResult(double result)
{
    lb_result->setText(QString("TTHI: %1").arg(QString::number(result)));
    show();
}
