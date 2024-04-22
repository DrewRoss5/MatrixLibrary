#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "matrix.h"

using namespace std;

int main(int argc, char** argv){
    srand(time(0));
    vector<vector<double>> v1 = {{2, 3, 4}, {6, 2, 8}};
    vector<vector<double>> v2 = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    vector<vector<double>> v3 = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
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
    m1.switch_row(0, 1);
    cout << "M1 switch row 0 and 1;\n" << m1 << endl;
    cout << "M2 + M3:\n" << m2 + m3 << endl;
    // multiplication 
    Matrix product = m2 * m3;
    cout << "M2 * M3:\n" << product << endl;
    product.switch_col(0, 2);
    cout << "M2 * M3 Switch column 0 and 2:\n" << product << endl;
    // identity matrix
    cout << "50x50 Identity Matrix:\n" << Matrix::identiyMatrix(50) << endl;

}