#include <iostream>
#include <vector>
using namespace std;

/*
From Good First Issue:

"Given the sizes of both matrices and then their inputs,
a form of matrix multiplication using row by columns will
calculate and output the resulting matrix."

*/

void matrixMultiplication(vector<vector<int>>& Matrix1, vector<vector<int>>& Matrix2, vector<vector<int>>& res) {
    //For rows in Matrix1
    for (int i = 0; i < Matrix1.size(); i++) {
        //For columns in Matrix2
        for (int j = 0; j < Matrix2[0].size(); j++) {
            //For rows in Matrix2
            for (int k = 0; k < Matrix2.size(); k++) {
                res[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    //Print result
    cout << "Matrix Result:" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    //Initialize m rows and n columns

    //First matrix
    int m1;
    int n1;
    vector<vector<int>> Matrix1;

    cout << "Enter number of rows and columns for Matrix 1 separated by a single space:" << endl;
    cin >> m1 >> n1;
    cout << "Rows: " << m1 << " " << "Columns: " << n1 << endl;

    vector<int> tempVector;
    int input;

    //Iterate over rows and columns
    for (int i = 0; i < m1; i++) {
        cout << "Fill out a row in the matrix: " << endl;
        for (int j = 0; j < n1; j++) {
            cin >> input;
            tempVector.push_back(input);
        }
        Matrix1.push_back(tempVector);
        tempVector.clear();
    }

    //Second matrix
    int m2;
    int n2;
    vector<vector<int>> Matrix2;

    cout << "Enter number of rows and columns for Matrix 2 separated by a single space:" << endl;
    cin >> m2 >> n2;
    cout << "Rows: " << m2 << " " << "Columns: " << n2 << endl;

    //Iterate over rows and columns
    for (int i = 0; i < m2; i++) {
        cout << "Fill out a row in the matrix: " << endl;
        for (int j = 0; j < n2; j++) {
            cin >> input;
            tempVector.push_back(input);
        }
        Matrix2.push_back(tempVector);
        tempVector.clear();
    }

    cout << "Matrix 1:" << endl;
    for (int i = 0; i < Matrix1.size(); i++) {
        for (int j = 0; j < Matrix1[i].size(); j++) {
            cout << Matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix 2:" << endl;
    for (int i = 0; i < Matrix2.size(); i++) {
        for (int j = 0; j < Matrix2[i].size(); j++) {
            cout << Matrix2[i][j] << " ";
        }
        cout << endl;
    }

    //For valid multiplication, # cols in first matrix must equal # rows in second
    if (n1 != m2) {
        cout << "Invalid Matrix Dimensions" << endl;
    }
    else {
        //Initialize m1xn2 vector result with all zeros
        vector<vector<int>> res(m1, vector<int>(n2, 0));
        matrixMultiplication(Matrix1, Matrix2, res);
    }

    return 0;
}