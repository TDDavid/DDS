#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <minmaxlib.h>

using Eigen::MatrixXd;

void skusobnaUloha(){
    MatrixXd A(4,4);
    A <<   4,   5,   2, eps,
         eps,   5, eps,  10,
         eps,   3,   7,   6,
         eps, eps,   8,   9;
    MatrixXd Apwr(4,4);
    Apwr = maxmul(maxmul(A,A),maxmul(A,A));

    MatrixXd Akon(4,4);
    Akon = -Apwr.transpose();

    MatrixXd c(4,1);
    c(0,0) = 50;
    c(1,0) = 50;
    c(2,0) = 50;
    c(3,0) = 50;

    std::cout << minmul(Akon,c) << std::endl;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    skusobnaUloha();
}



MainWindow::~MainWindow()
{
    delete ui;
}
