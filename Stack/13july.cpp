#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

    int n = positions.size();
    vector<int> result;

    vector<int> actual_idx;
    
    for (int i = 0 ; i < n ; i++){
        actual_idx.push_back(i);
    }

    auto lambda = [&](int &i , int &j){ // [&] allows it to access outer function variables.
        return positions[i] < positions[j];
    };

    sort(actual_idx.begin(),actual_idx.end(), lambda);

    stack<int> st;
    for(int &curr_idx : actual_idx){
        if (directions[curr_idx] == 'R'){
            st.push(curr_idx);
        }
        else{ // if its L
            int top_idx = st.top();
            st.pop();

            while(!st.empty() && healths[curr_idx] > 0){
                if (healths[top_idx] > healths[curr_idx]){
                    healths[top_idx] -= 1;
                    healths[curr_idx] = 0;
                    st.push(top_idx);
                }
                else if (healths[top_idx] < healths[curr_idx]){
                    healths[top_idx] = 0;
                    healths[curr_idx] -= 1;
                }
                else{
                    healths[top_idx] = 0;
                    healths[curr_idx] = 0;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if (healths[i] > 0){ 
            result.push_back(healths[i]);
        }
    }


    return result;
        
}

int main() {

    vector<int> positions = {1, 3, 2, 5};
    vector<int> healths = {5, 10, 2, 4};
    string directions = "RLRL";
    
    vector<int> result = survivedRobotsHealths(positions, healths, directions);
    
    cout << "Survived robots healths: ";
    for (int health : result) {
        cout << health << " | ";
    }
    cout << endl;

    return 0;
}