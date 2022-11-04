#include <iostream>
#include <vector>
#include "Matrix.h"
#include "GuassianElimination.h"
#include "GuassJordon.h"
using namespace std;
int main()
{
    vector<vector<double>> a = {{1,2},{1,2}};
    vector<vector<double>> b = {{1,3},{1,3}};
    Matrix<double> m{ a };
    GuassJordon<double>g2;
    b = g2.echlonForm(m);
    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            cout << b[i][j];
        }
    }
}
