//
// Created by Simon蔡文光 on 2020/6/8.
//
#include "read_data.h"
#include "backtest_class.h"
using namespace std;

int  main ()
{
    // read data
    Matrix ReturnMatrix = ReadData();

    // execute back test
    BackTestObject BackTest(pow(10,-36), ReturnMatrix);
    BackTest.GenerateBackTestWindow(100,12);
    Matrix Result(20);
    for (int i=1; i<21; i++)
    {
        double TargetReturn = static_cast<double>(i)/20.0;
        Result[i-1] = BackTest.RunBackTest(TargetReturn);
        Result[i-1][0] = TargetReturn;
    }
    LogAllStrat(Result);


    return 0;
}
