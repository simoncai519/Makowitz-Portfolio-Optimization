//
// Created by Simon蔡文光 on 2020/6/8.
//
#include "Matrix.h"
#include <iostream>
#include <cmath>
#include "util.h"
#ifndef INC_2_0_BASIC_FUNCTION_H
#define INC_2_0_BASIC_FUNCTION_H
// return mean of a vector of return
double GetMean(vector<double> &Return);
// return covariance of 2 vectors of return
double GetVariance(Vector &Rt1, Vector &Rt2);
// return mean vector and covariance matrix for a given return matrix
tuple<Vector, Matrix> GetMeanCov(Matrix &ReturnMatrix);
// return x vector that solves Qx = b (a system of equation)
Vector SolveQuaEqua(Matrix &Q, Vector &b, double epsilon);
// return performance stats for return series
Vector Performance(Vector &StratReturn);
#endif //INC_2_0_BASIC_FUNCTION_H
