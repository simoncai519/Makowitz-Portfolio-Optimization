//
// Created by Simon蔡文光 on 2020/6/8.
//

#include "backtest_class.h"
using namespace std;

Matrix BackTestWindow::GenerateQ(Matrix &ReturnMatrix) {
    int numberAsset = ReturnMatrix.size();
    auto temp = GetMeanCov(ReturnMatrix);
    Vector MeanReturn = get<0>(temp);
    Matrix Cov = get<1>(temp);
    Matrix Q(numberAsset);
    Vector x;
    Vector b(numberAsset+2,0.0);
    Vector NewRow(numberAsset+2,0.0);
    Vector NewRow2(numberAsset+2,0.0);
    for (int i=0;i<numberAsset;i++)
    {
        Q[i].resize(numberAsset);
        Q[i]=Cov[i];
        Q[i].push_back(-MeanReturn[i]);
        Q[i].push_back(-1.0);
        NewRow[i]=-MeanReturn[i];
        NewRow2[i]=-1.0;
    }

    Q.push_back(NewRow);
    Q.push_back(NewRow2);
    return Q;
}

Vector BackTestWindow::TradeWindowEvaluation(Vector &PortWeight) {
    Vector thisPeriodReturn = PortWeight * TradeReturnMatrix;
    return thisPeriodReturn;
}

void BackTestObject::GenerateBackTestWindow(int LookBack, int TradeWindow) {
    int numberReturn = ReturnMatrix[0].size();
    for (int day = 0; (day + TradeWindow + LookBack) <= numberReturn; day += TradeWindow) {
        Matrix LookBackReturnMatrix(numberAsset);
        Matrix TradeReturnMatrix(numberAsset);
        for (int i = 0; i < numberAsset; i++) {
            LookBackReturnMatrix[i].resize(LookBack);
            TradeReturnMatrix[i].resize(TradeWindow);
            for (int j = 0; j < LookBack; j++) {
                LookBackReturnMatrix[i][j] = ReturnMatrix[i][j + day];
            }
            for (int j = 0; j < TradeWindow; j++) {
                TradeReturnMatrix[i][j] = ReturnMatrix[i][j + day + LookBack];
            }
        }
        BackTestWindow ThisWindow(LookBackReturnMatrix, TradeReturnMatrix);
        BackTestWindows.push_back(ThisWindow);
    }
}

Vector BackTestObject::RunBackTest(double TargetAnnualReturn) {
    cout << "running backtest for target annual return of " << TargetAnnualReturn << endl;
    Vector StratReturn;
    // set up b vector, which is same for each backtest window
    double TargetReturn = TargetAnnualReturn / 250.0;
    Vector b(numberAsset+2,0.0);
    b[numberAsset] = -TargetReturn;
    b[numberAsset+1] = -1.0;
    Vector PortWeight;
    Vector thisPeriodReturn;
    for (BackTestWindow ThisWindow: BackTestWindows)
    {
        PortWeight = SolveQuaEqua(ThisWindow.LookBackQ, b, epsilon);
        PortWeight.resize(numberAsset); // drop last two element
        thisPeriodReturn = ThisWindow.TradeWindowEvaluation(PortWeight);
        StratReturn.insert(StratReturn.end(), thisPeriodReturn.begin(), thisPeriodReturn.end());
    }
    string filename = to_string(round(TargetAnnualReturn*100.0)/100.0);
    Log(StratReturn, filename);
    auto thisPerformance = Performance(StratReturn);
    return thisPerformance;
}
