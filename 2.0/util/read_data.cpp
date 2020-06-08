//g++ -c read_data.cpp
// g++ -c csv.cpp
// g++ -o portfolioSolver csv.o read_data.o
// ./portfolioSolver
/*
import numpy as np
A = np.array([[1., 2.], [3., 4.]])
b = np.array([[5],[6]])
x = np.linalg.solve(A,b)
*/
#include "read_data.h"
Matrix ReadData ()
{
    
    int numberAssets=83;
    int numberReturns=700;
    // dynamic memory allocation
	double **returnMatrix=new double*[numberAssets]; // a matrix to store the return data
    //allocate memory for return data
    for(int i=0;i<numberAssets;i++)
		returnMatrix[i]=new double[numberReturns];
	
    //read the data from the file and store it into the return matrix
    string fileName="../asset_returns.csv";
	readData(returnMatrix,fileName);
	// returnMatrix[i][j] stores the asset i, return j value
	
    //example on how to calculate the average return
    double mean=0;
    for(int i=0;i<numberAssets;i++){
        mean=0;
        for(int j=0;j<numberReturns;j++)
    {
        double temp=returnMatrix[i][j];
        //cout << "Asset " << assetNo << ", Return "<<i<<"="<< temp<<"\n";
        mean=mean+temp/numberReturns;
    }
    }

    Matrix output(numberAssets);

    for(int i=0;i<numberAssets;i++)
    {
        output[i].resize(numberReturns);
        output[i].assign(returnMatrix[i], returnMatrix[i] + numberReturns);
        delete[] returnMatrix[i];
    }
	delete[] returnMatrix;
	return output;
}


double string_to_double( const std::string& s )
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
} 

void readData(double **data,string fileName)
{
	char tmp[20];
	ifstream file (strcpy(tmp, fileName.c_str()));
	Csv csv(file);
	string line;
	if (file.is_open())
	{
		int i=0;
		while (csv.getline(line) != 0) {
         	for (int j = 0; j < csv.getnfield(); j++)
            {
               double temp=string_to_double(csv.getfield(j));
               //cout << "Asset " << j << ", Return "<<i<<"="<< temp<<"\n";
               data[j][i]=temp;
            }
            i++;
		}
		
		file.close();
	}
	else {cout <<fileName <<" missing\n";exit(0);}
                                                                 }
                                                                    
