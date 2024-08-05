#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string kthDistinct(vector<string>& arr, int k) {
    
    unordered_map<string , int> strCount;
    int n = arr.size();
    for(int i = 0; i < n ; i++){

        strCount[arr[i]] += 1;

    }

    vector<string> result;

    for(auto &y : arr){
        if(strCount[y] == 1){
            result.push_back(y);
        }
    }

    if(result.size() < k){
        return "";
    }
    else{
        return result[k-1];
    }

}

int main(){
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;

    cout << "The kth distinct letter is: ";
    cout << kthDistinct(arr,k);


    return 0;
}