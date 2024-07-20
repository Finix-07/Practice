#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> result(m, vector<int> (n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int value = min(rowSum[i], colSum[j]);
            result[i][j] = value;
            rowSum[i] -= value;
            colSum[j] -= value;
        }
    }


    return result;
}

int main(){
    vector<int> rowSum = {3, 8};
    vector<int> colSum = {4, 7};
    vector<vector<int>> matrix = restoreMatrix(rowSum, colSum);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}