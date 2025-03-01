class Solution {
public:
    bool formula(int n, int index, int maxSum, int mid){
        long long l_count = min(index, mid - 1);
        long long r_count = min(n-index-1, mid - 1);
        long long l_sum = (l_count*mid) - (l_count*(l_count+1)/2);
        l_sum += max(0, index - (mid - 1));
        long long r_sum = r_count*mid - (r_count*(r_count+1)/2);
        r_sum += max(0, n-index - 1 - (mid - 1));
        
        if (l_sum + r_sum + mid <= maxSum){
            return true;
        }
        else{
            return false;
        }

    }
    int maxValue(int n, int index, int maxSum) {
        long long l = 1, r = maxSum;
        long long result;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if (formula(n, index, maxSum, mid)){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        return result;
    }
};
