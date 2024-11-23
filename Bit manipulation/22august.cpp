#include <iostream>
#include <cstring>

using namespace std;

int findComplement(int num) {
    int i = 0, ans = 0;
    while (num) {
        // If the current bit is 0, set the corresponding bit in ans to 1
        if (!(num & 1))
            ans |= (1 << i);
        num >>= 1;
        i++;
    }
    return ans;
}


int main(){


    return 0;
}