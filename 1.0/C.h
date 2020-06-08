//
// Created by Simon蔡文光 on 2020/6/4.
//

#ifndef COURSEWORK_C_H
#define COURSEWORK_C_H
#include "B.h"
#include <fstream>
void BackTest (Matrix &ReturnMatrix, double TargetReturn, int LookBack, int TradeWindow,
               double epsilon);
void Performance(Vector &StratReturn);
void Log(Vector &vec);

class BackTestObject
{
private:
    double epsilon;
    Matrix ReturnMatrix;
public:
    BackTestObject(double epsilon_, Matrix &ReturnMatrix_){epsilon=epsilon_; ReturnMatrix=ReturnMatrix_;}
};
#endif //COURSEWORK_C_H
