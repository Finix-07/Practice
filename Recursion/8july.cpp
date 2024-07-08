#include <iostream>

using namespace std;

int indexOfWinner(int n , int k){

    if (n == 1){
        return 0;
    }

    int idx = indexOfWinner(n-1 , k);
    idx += k;
    idx %= n;

    return idx;


}


int findTheWinner(int n, int k) {
    
    int result_idx = indexOfWinner(n , k);

    return result_idx;
    
}


int main(){
    int NoPeople = 5;
    int gap = 2;


    cout << "The Winner is ";
    cout << findTheWinner(NoPeople, gap) + 1 << endl;
    return 0;
}