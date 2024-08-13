#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minimumPushes(string word) {
    
    //Generic solution
    vector<int> mp(26, 0);
    for(char &ch: word)
        mp[ch - 'a']++; //Mentioned in qn, all letters will be distinct

    sort(begin(mp), end(mp), greater<int>()); //descending order of frequency
    
    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans += mp[i]*((i/8) + 1);
    }
    return ans;
}

int main(){

    string word = "aabbccddeeffgghhiiiiii";

    cout << "The min pushes are: ";
    cout << minimumPushes(word);


    return 0;
}