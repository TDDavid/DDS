#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <minmaxlib.h>

using Eigen::MatrixXd;

void skusobnaUloha(){
    MatrixXd A(4,4);
    A <<   3,   4, eps,   8,
           2,   5,   2, eps,
           4,   6,   3,   4,
         eps,   3,   0,   6;

    MatrixXd Apwr(4,4);
    Apwr = maxmul(maxmul(A,A),maxmul(A,A));

    MatrixXd Akon(4,4);
    Akon = -Apwr.transpose();

    MatrixXd c(4,1);
    c(0,0) = 30;
    c(1,0) = 30;
    c(2,0) = 30;
    c(3,0) = 30;

    std::cout << minmul(Akon,c) << std::endl << std::endl;
    std::cout << maxmul(Apwr,minmul(Akon,c)) << std::endl;
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
