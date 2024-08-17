#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {\
        int min_no = arrays[0].front();
        int max_no = arrays[0].back();
        int result = 0;
        for(int i = 1; i < arrays.size(); i++){

            result = max({abs(result), abs(max_no - arrays[i].front()), abs(arrays[i].back() - min_no)});

            max_no = max(max_no, arrays[i].back());
            min_no = min(min_no, arrays[i].front());

        }

        return result;
    
    }
};

int main(){
    return 0;
}