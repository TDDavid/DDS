#include <minmaxlib.h>
#include <iostream>
#include <math.h>     /* abs */

//Funkcia vypocita sucin matic lubovolnych rozmerov v minplus algebre
MatrixXd minmul(MatrixXd A, MatrixXd B){
    MatrixXd C(A.rows(),B.cols());
    float a_mulVal [A.cols()];
    float valA, valB, extremeVal;

    //vyber riadku
    for (int riad=0; riad<A.rows(); riad++){
        //vyber stlpca
        for (int stlp=0; stlp<B.cols(); stlp++){
            //vypocet suctov dvojic prvkov
            for (int numMul=0; numMul<B.rows(); numMul++){
                valA = A(riad,numMul);
                valB = B(numMul,stlp);
                /*if ( fabsf(valA-meps) <= std::numeric_limits<float>::lowest() * fmaxf(fabsf(valA), fabsf(meps))){
                    a_mulVal[numMul] = meps;
                } else if ( fabsf(valB-meps) <= std::numeric_limits<float>::lowest() * fmaxf(fabsf(valB), fabsf(meps))){
                    a_mulVal[numMul] = meps;
                } else */
                    a_mulVal[numMul] = valA + valB;
            }
            //najdenie minima zo suctov
            extremeVal = a_mulVal[0];
            for (int i=0; i<sizeof(a_mulVal)/sizeof(a_mulVal[0]); i++){
                if (a_mulVal[i] < extremeVal)
                    extremeVal=a_mulVal[i];
            }
            C(riad,stlp) = extremeVal;
        }
    }
    return C;
}

//Funkcia vypocita sucin matic lubovolnych rozmerov v maxplus algebre
MatrixXd maxmul(MatrixXd A, MatrixXd B){
    MatrixXd C(A.rows(),B.cols());
    float a_mulVal [A.cols()];
    float extremeVal;

    //vyber riadku
    for (int riad=0; riad<A.rows(); riad++){
        //vyber stlpca
        for (int stlp=0; stlp<B.cols(); stlp++){
            //vypocet suctov dvojic prvkov
            for (int numMul=0; numMul<B.rows(); numMul++){
                a_mulVal[numMul] = A(riad,numMul) + B(numMul,stlp);
            }
            //najdenie maxima zo suctov
            extremeVal = a_mulVal[0];
            for (int i=0; i<sizeof(a_mulVal)/sizeof(a_mulVal[0]); i++){
                if (a_mulVal[i] > extremeVal)
                    extremeVal=a_mulVal[i];
            }
            C(riad,stlp) = extremeVal;
        }
    }
    return C;
}
