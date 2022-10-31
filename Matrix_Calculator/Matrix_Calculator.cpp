#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;
int main()
{
    vector<vector<double>> a = {{1,2},{1,2}};
    vector<vector<double>> b = {{1,3},{1,3}};
    Matrix<double> m{ a };
    Matrix<double> m2{ b };
    Matrix<double> c = m * m2;
    c.print();
}
