//
// Created by Simon蔡文光 on 2020/6/4.
//

#include "B.h"
#include <iostream>
using namespace std;
// checked
Vector PortOptimize(Matrix &ReturnMatrix, double TargetReturn, double epsilon)
{
    //convert to target daily return
    TargetReturn = TargetReturn / 250.0;
    int numberAsset = ReturnMatrix.size();
    auto temp = GetMeanCov(ReturnMatrix);
    Vector MeanReturn = get<0>(temp);
    Matrix Cov = get<1>(temp);
    // print(MeanReturn);
    // print(Cov);
    Matrix Q(numberAsset);
    Vector x;
    Vector b(numberAsset+2,0.0);
    Vector NewRow(numberAsset+2,0.0);
    Vector NewRow2(numberAsset+2,0.0);
    for (int i=0;i<numberAsset;i++)
    {
        Q[i].resize(numberAsset);
        Q[i]=Cov[i];
        Q[i].push_back(-MeanReturn[i]);
        Q[i].push_back(-1.0);
        NewRow[i]=-MeanReturn[i];
        NewRow2[i]=-1.0;
    }

    Q.push_back(NewRow);
    Q.push_back(NewRow2);

    b[numberAsset] = -TargetReturn;
    b[numberAsset+1] = -1.0;

    x = SolveQuaEqua(Q, b, epsilon);
    x.resize(MeanReturn.size());
    auto a = Q*x;
    // print(a);
    return x;
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