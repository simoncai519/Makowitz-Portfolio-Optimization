//
// Created by Simon蔡文光 on 2020/6/8.
//

#include "basic_function.h"
using namespace std;

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

Vector SolveQuaEqua(Matrix &Q, Vector &b, double epsilon)
{
    double alpha, beta;
    Vector s, s_, p;
    double x_init;
    if(b.size()>2){x_init = 1.0/(b.size()-2.0);}
    else{x_init = 1.0;};
    Vector x(b.size(), x_init);
    s=b-Q*x;
    p=s;
    while((s^s) > epsilon)
    {
        alpha = (s^s) / (p^(Q*p));
        x = x+alpha*p;
        s_ = s-alpha*(Q*p);
        beta = (s_^s_) / (s^s);
        p = s_+beta*p;
        s = s_;
    }
    return x;

}

Vector Performance(Vector &StratReturn)
{
    double Mean = GetMean(StratReturn)*250.0;
    double Std = sqrt(GetVariance(StratReturn, StratReturn) * 250.0);
    double Sharpe = Mean / Std;
    Vector result(4);
    result[1] = Mean; result[2] = Std; result[3] = Sharpe;
    cout << "Annual return: " << Mean << endl;
    cout << "Annual std: " << Std << endl;
    cout << "Sharpe: " << Sharpe << endl;
    return result;
}