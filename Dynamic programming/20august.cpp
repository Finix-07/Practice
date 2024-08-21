#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int t[1001][1001];

int solve(int currA, int clipA, int n){



    if (currA == n){
        return 0;
    }


    if (currA > n){
        return 100000; // do any big number, int max give error in addition so dont use that
    }

    if(t[currA][clipA] != -1 ){
        return t[currA][clipA];
    }

    int copyAllPaste = 1 + 1 + solve(currA * 2, currA , n);

    int Paste = 1 + solve(currA + clipA , clipA , n);

    return t[currA][clipA] = min(copyAllPaste, Paste);


}



int minSteps(int n){

    if(n == 1){
        return 0;
    }

    memset(t , -1 , sizeof(t));

    return 1 + solve(1,1,n);


}

int main(){


    return 0;
}