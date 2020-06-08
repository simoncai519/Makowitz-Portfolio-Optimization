
//
// Created by Simon蔡文光 on 2020/6/7.
//

#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "csv.h"
#include "Matrix.h"
#ifndef COURSEWORK_READ_DATA_H
#define COURSEWORK_READ_DATA_H
Matrix ReadData ();
double string_to_double( const std::string& s );
void readData(double **data,string fileName);
#endif //COURSEWORK_READ_DATA_H
