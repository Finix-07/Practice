#include <bits/stdc++.h>

using namespace std;

bool zero_count(vector<int> letter_count){
    for(auto &x : letter_count){
        if (x != 0){
            return false;
        }
    }

    return true;
}

int search(string pat, string txt) {
	    
	    // code here
	    
	    int n = pat.size();
        int length = txt.size();
	    int l = 0 , r = 1, result = 0;
        
	    vector<int> letter_count (26,0);

        for(auto &x : pat){
            letter_count[x - 'a'] += 1;
        }
        

        if (n > length) return result;
        
        letter_count[txt[r] - 'a'] -= 1;
        letter_count[txt[l] - 'a'] -= 1;
        
        while(r < length){
                       
            
            if ( r - l + 1 == n){
            
                if (zero_count(letter_count)){
                    result += 1;
                }
                r++;
                if (r < length) 
                    letter_count[txt[r] - 'a'] -= 1;
                
            
            }
            
            else if (r - l + 1 < n){
            
                r++;
                if (r < length) 
                    letter_count[txt[r] - 'a'] -= 1;
        
            
            }

            else if (r - l + 1 > n){
                letter_count[txt[l] - 'a'] += 1;
                l++;

            }
            
        }
	    
        return result;
	    
	    
}


    int main(){

        string txt = "forxxorfxdofr";
        string pat = "for";

        cout << "count: " << search(pat, txt) ;        

        return 0;
    }