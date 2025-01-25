class Solution {
public:
    bool SatisfyTotal(vector<int>& time, int totalTrips, long long currTime){
        long long actualTrips = 0;
        for( auto &x : time){
            actualTrips = actualTrips + (currTime / x);
        }

        if (actualTrips >= totalTrips){
            return true;
        }
        else{
            return false;
        }
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        int n = time.size();

        long long l = 1;
        long long r = (long long) *min_element(begin(time),end(time)) * totalTrips;
        
        while(l < r){
            
            long long mid_time = l + (r-l)/2;

            if (SatisfyTotal(time, totalTrips, mid_time)){
                r = mid_time;
            }
            else{
                l = mid_time + 1;
            }
        }

        return l;
    }
};