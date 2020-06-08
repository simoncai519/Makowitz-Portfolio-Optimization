#include <cmath>
#include "read_data.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "Matrix.h"
using namespace std;


int  main (int  argc, char  *argv[])
{

    int numberAssets=83;
    int numberReturns=700;
    // read data
    Matrix ReturnMatrix = ReadData();

    // execute back test
    BackTest (ReturnMatrix, 0.02, 100, 12,
            pow(10,-36));

    return 0;
}
