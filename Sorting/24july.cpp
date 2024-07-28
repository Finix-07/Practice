#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums){
    vector<pair<int, int>> mappedno;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        int map_value = 0;
        int num = nums[i];
        int place = 1;

        if (num == 0)
        {
            mappedno.push_back({mapping[0], i});
            continue;
        }

        while (num > 0)
        {
            int digit = mapping[num % 10];
            map_value += digit * place;
            num /= 10;
            place *= 10;
        }

        mappedno.push_back({map_value, i});
    }

    sort(mappedno.begin(), mappedno.end());

    for (auto &x : mappedno)
    {
        int index = x.second;
        result.push_back(nums[index]);
    }

    return result;
}

int main(){
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums = {991, 338, 38};

    vector<int> result = sortJumbled(mapping, nums);
    for (auto &x : result)
    {
        cout << x << ",";
    }
    return 0;
}