#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <minmaxlib.h>

using Eigen::MatrixXd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MatrixXd A(2,2);
    A << 2, meps,
         meps, 3;

    MatrixXd B(2,2);
    B = A;

    MatrixXd c(4,1);
    c(0,0) = 50;
    c(1,0) = 50;
    c(2,0) = 50;
    c(3,0) = 50;

    std::cout << minmul(A,B) << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
