#include <iostream>
#include <vector>

using namespace std;

double averageWaitingTime(vector<vector<int>>& customers) {
    double WaitTime = 0;
    int TimeElapsed = 0;
    for (vector<int>& x : customers){
        if (TimeElapsed < x[0]){
            TimeElapsed = x[0];
        }

        TimeElapsed += x[1];
        int diff = TimeElapsed - x[0];
        WaitTime += diff;
    }
    double result = WaitTime / customers.size();
    return result;
    
}

int main(){

    vector<vector<int>> customers = {{5,2},{5,4},{10,3},{20,1}};
    
    cout << "The AVG wait time is ";
    cout << averageWaitingTime(customers) << endl;

    return 0;
}