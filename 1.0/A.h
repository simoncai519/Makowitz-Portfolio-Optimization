//
// Created by Simon蔡文光 on 2020/6/4.
//
#include <vector>
#include "Matrix.h"
using namespace std;

#ifndef COURSEWORK_1_A_H
#define COURSEWORK_1_A_H
double GetMean(vector<double> &Return);
double GetVariance(Vector &Rt1, Vector &Rt2);
tuple<Vector, Matrix> GetMeanCov(Matrix &ReturnMatrix);
#endif //COURSEWORK_1_A_H
