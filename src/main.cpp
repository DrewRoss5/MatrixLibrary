#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "matrix.h"

using namespace std;

int main(int argc, char** argv){
    srand(time(0));
    vector<vector<double>> v1 = {{2, 3, 4}, {6, 2, 8}};
    vector<vector<double>> v2 = {{3, 7}, {6, 3}, {8, 2}};
    vector<vector<double>> v3 = {{1, 2, 3}, {4, 5, 6}};
    Matrix m1(v1);
    Matrix m2(v2);
    Matrix m3(v3);
    // display the original matricies
    cout << "M1:" << endl;
    m1.display(cout);
    cout << "M2:" << endl;
    m2.display(cout);
    cout << "M3:" << endl;
    m3.display(cout);
    // display the results of opperations
    cout << "M1 + M3:\n" << m1 + m3 << std::endl;
    // multiplication 
    cout << "M1 * M2:\n" << m1 * m2 << std::endl;
}