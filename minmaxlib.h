#ifndef MINMAXLIB_H
#define MINMAXLIB_H

#include <limits>
#include <Eigen/Dense>
using Eigen::MatrixXd;

//Definovane hodnoty: eps = -nekonecno; meps = nekonecno;
#define eps -std::numeric_limits<double>::infinity()
#define meps std::numeric_limits<double>::infinity()


MatrixXd minmul(MatrixXd A, MatrixXd B);
MatrixXd maxmul(MatrixXd A, MatrixXd B);

#endif // MINMAXLIB_H
