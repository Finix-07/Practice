class Solution {
public:
    bool EatAll(vector<int> piles, int h , int count){
        int actualhours = 0;
        
        for(auto &x: piles){
            actualhours += x/count;

            if (x%count != 0){
                actualhours++;
            }
        }
        if (actualhours <= h){
            return true;
        }
        else{
            return false;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(begin(piles),end(piles));

        while (l < r){
            int mid = l + (r - l)/2;

            if(EatAll(piles, h, mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        
        }

        return l;

    }
};