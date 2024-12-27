#include "qt6_calculator.h"
#include "./ui_qt6_calculator.h"
#include <QPushButton>
#include <QLineEdit>

Qt6_Calculator::Qt6_Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt6_Calculator)
{
    ui->setupUi(this);
}

Qt6_Calculator::~Qt6_Calculator()
{
    delete ui;
}

QString currentExpression;

void Qt6_Calculator::on_sym_clear_clicked()
{
    currentExpression.clear();
    ui->lineEdit->clear();
}


void Qt6_Calculator::on_sym_equal_clicked()
{
    QString result = "8989";
    ui->lineEdit->setText(result);
    currentExpression = result;
}

