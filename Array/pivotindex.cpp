#include <bits/stdc++.h>

using namespace std;

int pivotIndex(vector<int>& arr) {
    int lsum = 0, rsum = 0;
    int n = arr.size();

    for(int & x: arr){
        rsum += x;
    }  

    for (int i = 0 ; i < n ; i++){
        rsum -= arr[i];
        if (rsum == lsum){
            return i;
        }
        
        lsum += arr[i];
    }


    return -1;
}