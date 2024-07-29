#include <iostream>
#include <vector>

using namespace std;

int numTeams(vector<int>& rating) {
    int count = 0;
    for(int i = 0 ; i < rating.size()-1; i++){
        int CountBig_L = 0;
        int CountSmall_R = 0;
        int CountBig_R = 0;
        int CountSmall_L = 0;

        for(int j = 0; j < i ; j++){
            if (rating[j] < rating[i]){
                CountSmall_L += 1;
            }
            else{
                CountBig_L += 1;
            }
        }
        for (int k = i+1; k < rating.size() ; k++){
            if (rating[k] < rating[i]){
                CountSmall_R += 1;
            }
            else{
                CountBig_R += 1;
            }
        }
        int count_inc = CountSmall_L * CountBig_R;
        int count_dec = CountBig_L * CountSmall_R;
        count = count + count_inc + count_dec;
    }

    return count;
}

int main(){

    vector<int> ratings = {2,5,3,4,1};

    cout << "Num of teams you can form is: ";
    cout << numTeams(ratings);

    return 0;
}