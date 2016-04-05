#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MatrixXd m(2,2);
    /*m(0,0) = 1;
    m(1,0) = 3;
    m(0,1) = 2;
    m(1,1) = 4;*/
    m = {(1,2),(3,4)};
    MatrixXd n(2,1);
    n(0,0) = 0;
    n(1,0) = 1;
    std::cout << m << std::endl;
    std::cout << m.inverse() << std::endl;
    std::cout << -m.transpose() << std::endl;
    std::cout << n << std::endl;
    std::cout << m*n << std::endl;


}

MainWindow::~MainWindow()
{
    delete ui;
}
