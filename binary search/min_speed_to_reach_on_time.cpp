class Solution {
public:
    bool canComplete(vector<int>& dist, double hour, int speed){
        double hr_taken = 0.0;
        int n = dist.size();
        for(int i = 0; i < n - 1; i++){
            double time = (double)dist[i]/(double)speed;
            hr_taken += ceil(time);
        }

        hr_taken += double(dist[n-1])/(double)speed;

        if (hr_taken <= hour){
            return true;
        }
        else{
            return false;
        }
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int l = 1, r = 1e7;
        
        // t = d/v;
        int result = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if (canComplete(dist,hour,mid)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }
};