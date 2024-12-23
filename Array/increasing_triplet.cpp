#include <bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int>& arr) {
        
    int num1 = INT_MAX, num2 = INT_MAX;
    
    for (auto &x : arr){
        if (x <= num1){
            num1 = x;
        }
        else if (x <= num2){
            num2 = x;
        }
        else{
            return true;
        }
    }

    return false;
}

    