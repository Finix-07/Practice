#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> result;

    unordered_map<string, vector<string>> mp;

    int n = strs.size();

    // approach 1: sorting based

    // for(int i = 0; i < n ; i++){
    //     string temp = strs[i];
    //     // sort as anagrams have same sorted arrangement so we can map all anagrams to sorted form.
    //     sort(temp.begin(),temp.end());

    //     mp[temp].push_back(strs[i]);

    // }
    // approach 2: No Sorting
    vector<int> letters(26,0);
    for (int i = 0; i < n; i++){
        for (int k = 0; k < strs[i].size(); k++){
            letters[strs[i][k] - 'a'] += 1;
        }
        string temp = "";

        for (int j = 0; j < 26; j++){
            while(letters[j] != 0){
                temp.push_back(j + 'a');
                letters[j]--;
            }
        }
        mp[temp].push_back(strs[i]);
    }
    
    for (auto x : mp){
        result.push_back(x.second);
    }

    return result;

}

int main(){


    return 0;
}