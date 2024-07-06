#include <iostream>

using namespace std;

int passThePillow(int n, int time) {
    if ((time / (n-1)) % 2 == 0){
        return 1 + (time % (n-1));
    }
    else{
    return n - (time % (n-1)) ;
    }
}

int main(){
    int n = 4;
    int time = 5;
    cout << "Pillow is on person ";
    cout << passThePillow(n,time) <<endl;
    return 0;
}