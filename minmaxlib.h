#ifndef MINMAXLIB_H
#define MINMAXLIB_H

#include <Eigen/Dense>
using Eigen::MatrixXd;

//Hodnoty minus nekonecno a plus nekonecno su predstavovane hodnotami meps a eps
#define meps 1.17549e-038
#define eps 1.17549e+038


MatrixXd minmul(MatrixXd A, MatrixXd B);

#endif // MINMAXLIB_H
