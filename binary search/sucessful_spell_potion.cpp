class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        int n = spells.size();
        sort(begin(potions),end(potions));
        vector<int> result;
        for(auto &x: spells){
            int l = 0, r = m - 1;

            while (l < r){
                int mid = l + (r - l) / 2;
                
                if ( ((long long) potions[mid] * x) >= success){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            if (l == m-1 &&  ((long long)potions[l]*x) < success){
                result.push_back(0);
            }
            else{
                result.push_back(m - l);
            }
        }

        return result;
    }
};