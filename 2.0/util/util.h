//
// Created by Simon蔡文光 on 2020/6/5.
//

#ifndef COURSEWORK_UTIL_H
#define COURSEWORK_UTIL_H
#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;
inline void print(Vector &vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<< endl;
    }
    }

inline void print(Matrix &matrix)
{
    for (int i=0; i<matrix.size(); i++)
    {
        for (int j=0; j<matrix[i].size(); j++){cout <<matrix[i][j];}
        cout << endl;
    }
}

inline void Log(Vector &vec, string &name)
{
    ofstream myfile;
    myfile.open ("../log/log"+ name + ".csv");
    myfile << "Strategy return series\n";
    for (double i: vec)
    {
        myfile << i <<"\n";
    }
    myfile.close();
}

inline void LogAllStrat(Matrix &mat)
{
    ofstream myfile;
    myfile.open ("../log/log_all_strat.csv");
    myfile << "Target annual return, Mean return, Std, Sharpe\n";
    for (Vector i: mat)
    {
        for (double ele: i)
        {myfile << ele <<",";}
        myfile << "\n";
    }
    myfile.close();
}
#endif //COURSEWORK_UTIL_H
