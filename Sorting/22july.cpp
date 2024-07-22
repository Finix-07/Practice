#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<int> idx;
    vector<string> result;

    for(int i = 0; i < names.size(); i++){
        idx.push_back(i);
    }

    auto lambda = [&](int &i, int &j){
        return heights[i] > heights[j];
    };

    sort(idx.begin(), idx.end(),lambda);

    for( int x : idx){
        result.push_back(names[x]);
    }

    return result;
}



int main(){
    vector<string> names = {"Mary","John","Emma"} ;
    vector<int> heights = {180,165,170};

    names = sortPeople(names,heights);

    for(string x : names){
        cout << x << endl;
    }

    return 0;
}