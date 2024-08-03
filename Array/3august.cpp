#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int,int> array;
    unordered_map<int,int> tar;

    for(int i = 0; i < target.size() ; i++){

        array[arr[i]] += 1;
        tar[target[i]] += 1;

    }

    for(auto &x : array){
        if (tar[x.first] == x.second){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

int main(){


    return 0;
}