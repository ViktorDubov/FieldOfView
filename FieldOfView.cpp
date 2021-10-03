#include <iostream>
#include <fstream>
#include "Mathf.h"
#include "Vector2.h"
#include "Soldier.h"
#include "Battlefield.h"

#include <map>
#include <ctime>

using namespace std;

using namespace MathOFVector;
using namespace FieldOfView;

int main()
{
    int start = clock();
    Battlefield battlefield = Battlefield(100, 100, 100);
    int finishGenerate = clock();
    cout << "timeGenerate " << (finishGenerate - start)  << endl; // CLOCKS_PER_SEC
    
    battlefield.calculateFieldsOfViewForAllSoldier();
    int finishCalculate = clock();
    cout << "timeCalculate " << (finishCalculate - finishGenerate) << endl;


    string path = ".\\battlefield1.txt";
    fstream fs;
    fs.open(path, fstream::out | fstream::trunc);
    if (!fs.is_open())
    {
        throw new exception("Error of open file");
    }
    else
    {
        fs << battlefield;
    }
    fs.close();
    int finishWriting = clock();
    cout << "timeWriting " << (finishWriting - finishCalculate) << endl;
    
}

