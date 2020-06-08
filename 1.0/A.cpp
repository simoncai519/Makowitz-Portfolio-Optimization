//
// Created by Simon蔡文光 on 2020/6/4.
//
#include "A.h"
#include "Matrix.h"
// #include <vector>
// using namespace std;
double GetMean(Vector &Return)
{
    double mean = 0.0;
    for (int i=0;i<Return.size();i++)
    {
        mean = (i*mean + Return[i]) / (i+1);
    }
    return mean;
}

double GetVariance(Vector &Rt1, Vector &Rt2)
{
    double Rt1_mean = GetMean(Rt1);
    double Rt2_mean = GetMean(Rt2);
    double Variance = 0.0;
    for (int i=0;i<Rt1.size();i++)
    {
        Variance += (Rt1[i]-Rt1_mean) * (Rt2[i]-Rt2_mean);
    }
    Variance /= (Rt1.size()-1);
    return Variance;
}

// checked by python script
tuple<Vector, Matrix> GetMeanCov(Matrix &ReturnMatrix)
{
    int numberAssets = ReturnMatrix.size();
    Vector MeanReturn(numberAssets);
    Matrix Cov(numberAssets);
    Vector SingleReturn;
    Vector SecondReturn;
    for (int i=0;i<numberAssets;i++)
    {
        SingleReturn=ReturnMatrix[i];
        MeanReturn[i] = GetMean(SingleReturn);
        Cov[i].resize(numberAssets);
        for (int j=0;j<numberAssets;j++)
        {
            SecondReturn=ReturnMatrix[j];
            Cov[i][j] = GetVariance(SingleReturn, SecondReturn);
        }
    }
    return {MeanReturn, Cov};
}