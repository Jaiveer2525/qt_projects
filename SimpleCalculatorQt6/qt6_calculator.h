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

    void on_num_0_clicked();

    void on_num_1_clicked();

    void on_num_2_clicked();

    void on_num_3_clicked();

    void on_num_4_clicked();

    void on_num_5_clicked();

    void on_num_6_clicked();

    void on_num_7_clicked();

    void on_num_8_clicked();

    void on_num_9_clicked();

    void on_sym_plus_clicked();

    void on_sym_minus_clicked();

    void on_sym_multiply_clicked();

    void on_sym_division_clicked();

private:
    Ui::Qt6_Calculator *ui;
};
#endif // QT6_CALCULATOR_H
