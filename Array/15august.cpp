#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int , int > change;
        for(int i = 0 ; i < bills.size() ; i++){
            
            if(bills[i] == 5){
                change[5]++;
                continue;
            }

            else if(bills[i] == 10){
                if(change[5] > 0){
                    change[10]++;
                    change[5]--;
                    continue;
                }
                else{
                    return false;
                }
            }

            else if(bills[i] == 20){
                if((change[10] > 0 && change[5] > 0)){
                    change[10]--;
                    change[5]--;
                    continue;
                }
                else if (change[5] >= 3){
                    change[5] -= 3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){


    return 0;
}