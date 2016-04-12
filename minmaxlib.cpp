#include <minmaxlib.h>

//Funkcia vypocita konjugovany sucin matic lubovolnych rozmerov
MatrixXd minmul(MatrixXd A, MatrixXd B){
    MatrixXd C(A.rows(),B.cols());
    float a_mulVal [A.cols()];
    float minVal;
    for (int riad=0; riad<A.rows(); riad++){
        for (int stlp=0; stlp<B.cols(); stlp++){
            for (int numMul=0; numMul<B.rows(); numMul++){
                a_mulVal[numMul] = A(riad,numMul) + B(numMul,stlp);
            }
            minVal = a_mulVal[0];
            for (int i=0; i<sizeof(a_mulVal)/sizeof(a_mulVal[0]); i++){
                if (a_mulVal[i] < minVal)
                    minVal=a_mulVal[i];
            }
            C(riad,stlp) = minVal;
        }
    }
    return C;
}
