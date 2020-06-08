//
// Created by Simon蔡文光 on 2020/6/8.
//
#include "basic_function.h"
#ifndef INC_2_0_BACKTEST_CLASS_H
#define INC_2_0_BACKTEST_CLASS_H
class BackTestWindow
{
private:
    // Q matrix constructed with look-back return matrix, used to feed Markowitz model

    Matrix GenerateQ(Matrix &ReturnMatrix);
public:
    Matrix TradeReturnMatrix;
    Matrix LookBackQ;
    BackTestWindow(Matrix &LookBackReturnMatrix, Matrix &TradeReturnMatrix_)
    {LookBackQ = GenerateQ(LookBackReturnMatrix); TradeReturnMatrix = TradeReturnMatrix_;}
    Vector TradeWindowEvaluation(Vector &PortWeight);
};

class BackTestObject
{
private:
    double epsilon;
    Matrix ReturnMatrix;
    vector<BackTestWindow> BackTestWindows;
    int numberAsset;
public:
    BackTestObject(double epsilon_, Matrix &ReturnMatrix_)
    {ReturnMatrix=ReturnMatrix_; epsilon=epsilon_; numberAsset = ReturnMatrix.size();}
    void GenerateBackTestWindow(int LookBack, int TradeWindow);
    Vector RunBackTest(double TargetReturn);

};
#endif //INC_2_0_BACKTEST_CLASS_H
