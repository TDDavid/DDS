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

    MatrixXd A(4,4);
    A << -16, meps, meps, meps,
         -26, -30, -26, -29,
         -32, -36, -32, -35,
         -33, -37, -33, -36;
    MatrixXd c(4,1);
    c(0,0) = 50;
    c(1,0) = 50;
    c(2,0) = 50;
    c(3,0) = 50;
    std::cout << minmul(A,c);


}

MainWindow::~MainWindow()
{
    delete ui;
}
