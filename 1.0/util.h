//
// Created by Simon蔡文光 on 2020/6/5.
//

#ifndef COURSEWORK_UTIL_H
#define COURSEWORK_UTIL_H
#include <iostream>
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
#endif //COURSEWORK_UTIL_H
