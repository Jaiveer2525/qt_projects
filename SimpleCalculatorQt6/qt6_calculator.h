#ifndef QT6_CALCULATOR_H
#define QT6_CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Qt6_Calculator;
}
QT_END_NAMESPACE

class Qt6_Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Qt6_Calculator(QWidget *parent = nullptr);
    ~Qt6_Calculator();

private slots:
    void on_sym_clear_clicked();

    void on_sym_equal_clicked();

private:
    Ui::Qt6_Calculator *ui;
};
#endif // QT6_CALCULATOR_H
