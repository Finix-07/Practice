#include <iostream>

using namespace std;

int numWaterBottles(int (numBottles), int numExchange) {

    int extrabottles = 0;
    int result = (numBottles+extrabottles);
    while ((numBottles + extrabottles) > (numExchange - 1)){
        numBottles += extrabottles;
        extrabottles = numBottles % numExchange;
        (numBottles) /= numExchange;
        result += (numBottles);
    }

    return result;
    
}

int main(){
    int nb = 15;
    int ne = 4;
    cout << "Max bottles you can drink is " ;
    cout << numWaterBottles(nb, ne);
    return 0;
}