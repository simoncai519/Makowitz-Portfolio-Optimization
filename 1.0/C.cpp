//
// Created by Simon蔡文光 on 2020/6/4.
//
#include "C.h"
//checked
void BackTest (Matrix &ReturnMatrix, double TargetReturn, int LookBack, int TradeWindow,
        double epsilon)
{
    int numberAsset = ReturnMatrix.size();
    int numberReturn = ReturnMatrix[0].size();
    Vector StratReturn;
    for (int day = 0; (day+TradeWindow+LookBack)<=numberReturn ; day+=TradeWindow)
    {
        Matrix LookBackReturnMatrix(numberAsset);
        Matrix TradeReturnMatrix(numberAsset);
        for (int i=0;i<numberAsset;i++)
        {
            LookBackReturnMatrix[i].resize(LookBack);
            TradeReturnMatrix[i].resize(TradeWindow);
            for (int j=0; j<LookBack; j++)
            {
                LookBackReturnMatrix[i][j] = ReturnMatrix[i][j+day];
            }
            for (int j=0; j<TradeWindow;j++)
            {
                TradeReturnMatrix[i][j] = ReturnMatrix[i][j+day+LookBack];
            }
        }
        Vector PortWeight = PortOptimize(LookBackReturnMatrix, TargetReturn, epsilon);
        // print(PortWeight);
        auto thisPeriodReturn = PortWeight * TradeReturnMatrix;
        for (int i=0;i<thisPeriodReturn.size();i++)
        {
            StratReturn.push_back(thisPeriodReturn[i]);
        }

    }
    Log(StratReturn);
    Performance(StratReturn);
    return;
}

void Performance(Vector &StratReturn)
{
    cout << "Annual return: " << GetMean(StratReturn)*250.0 << endl;
    cout << "Annual std: " << sqrt(GetVariance(StratReturn, StratReturn) * 250.0) << endl;
    double Sharpe = GetMean(StratReturn) / sqrt(GetVariance(StratReturn, StratReturn));
    cout << "Sharpe: " << Sharpe << endl;
}

void Log(Vector &vec)
{
    ofstream myfile;
    myfile.open ("log.csv");
    myfile << "Strategy return series\n";
    for (double i: vec)
    {
        myfile << i <<"\n";
    }
    myfile.close();
}