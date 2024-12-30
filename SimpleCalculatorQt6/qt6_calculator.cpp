#include "qt6_calculator.h"
#include "./ui_qt6_calculator.h"
#include <QPushButton>
#include <QLineEdit>

Qt6_Calculator::Qt6_Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt6_Calculator)
{
    ui->setupUi(this);
    ui->lineEdit->setAlignment(Qt::AlignRight);
}

Qt6_Calculator::~Qt6_Calculator()
{
    delete ui;
}

/// Function to split expression
std::string* splitExpression(const QString& expression, int& size) {
    int max_size = expression.length();  // Maximum possible size (worst case: each character is a number/operator)
    std::string* result = new std::string[max_size];
    int index = 0;

    std::string currentNumber = "";

    // Iterate through each character in the expression
    for (QChar ch : expression) {
        if (ch.isDigit()) {
            // If the character is a digit, build the number string
            currentNumber += ch.toLatin1();
        } else if (ch == '+' || ch == '-' || ch == 'x' || ch == '/' || ch == '^') {
            // If it's an operator, push the current number and operator to the result
            if (!currentNumber.empty()) {
                result[index++] = currentNumber;
                currentNumber.clear();
            }
            result[index++] = std::string(1, ch.toLatin1());  // Store the operator as a string
        }
    }

    // If there is a number left at the end, add it to the result
    if (!currentNumber.empty()) {
        result[index++] = currentNumber;
    }

    // Set the size to the actual number of elements in the result array
    size = index;

    return result;
}

QString currentExpression;

// Function to evaluate the expression
double evaluateExpression(std::string* result, int size) {
    double currentResult = std::stod(result[0]);  // Start with the first number
    for (int i = 1; i < size; i += 2) {
        std::string op = result[i];  // Operator
        double nextNumber = std::stod(result[i + 1]);  // Next number

        if (op == "+") {
            currentResult += nextNumber;
        } else if (op == "-") {
            currentResult -= nextNumber;
        } else if (op == "x") {
            currentResult *= nextNumber;
        } else if (op == "/") {
            if (nextNumber != 0) {
                currentResult /= nextNumber;
            } else {
                throw std::invalid_argument("Division by zero");
            }
        } else if (op == "^") {
            currentResult = std::pow(currentResult, nextNumber);
        }
    }

    return currentResult;
}

//Clear the lineEdit box, all data is lost
void Qt6_Calculator::on_sym_clear_clicked()
{
    currentExpression.clear();
    ui->lineEdit->clear();
}

//testing
void Qt6_Calculator::on_sym_equal_clicked()
{
    int size = 0;

    // Get the current expression as a QString
    currentExpression = ui->lineEdit->text();

    // Split the expression into numbers and operators using the splitExpression function
    std::string* result = splitExpression(currentExpression, size);

    double evaluatedResult = 0;
    try {
        evaluatedResult = evaluateExpression(result, size);
    } catch (const std::invalid_argument& e) {
        // Handle error if division by zero occurs or any invalid argument
        ui->lineEdit->setText("Error");
        delete[] result;
        return;
    }

    ui->lineEdit->setText(QString::number(evaluatedResult));

    // Free dynamically allocated memory
    delete[] result;
}
//a bunch of functions only for input, i wonder if theres a generic prog to this
void Qt6_Calculator::on_num_0_clicked()
{
    ui->lineEdit->insert("0");
}

void Qt6_Calculator::on_num_1_clicked()
{
    ui->lineEdit->insert("1");
}

void Qt6_Calculator::on_num_2_clicked()
{
    ui->lineEdit->insert("2");
}

void Qt6_Calculator::on_num_3_clicked()
{
    ui->lineEdit->insert("3");
}

void Qt6_Calculator::on_num_4_clicked()
{
    ui->lineEdit->insert("4");
}

void Qt6_Calculator::on_num_5_clicked()
{
    ui->lineEdit->insert("5");
}

void Qt6_Calculator::on_num_6_clicked()
{
    ui->lineEdit->insert("6");
}

void Qt6_Calculator::on_num_7_clicked()
{
    ui->lineEdit->insert("7");
}

void Qt6_Calculator::on_num_8_clicked()
{
    ui->lineEdit->insert("8");
}

void Qt6_Calculator::on_num_9_clicked()
{
    ui->lineEdit->insert("9");
}



void Qt6_Calculator::on_sym_plus_clicked()
{
    ui->lineEdit->insert("+");
}


void Qt6_Calculator::on_sym_minus_clicked()
{
    ui->lineEdit->insert("-");
}


void Qt6_Calculator::on_sym_multiply_clicked()
{
    ui->lineEdit->insert("x");
}


void Qt6_Calculator::on_sym_division_clicked()
{
    ui->lineEdit->insert("/");
}


