#include <bits/stdc++.h>

using namespace std;

int largestPerimeter(vector<int> &arr)
{
    int n = arr.size();
    sort(begin(arr), end(arr));

    for (int i = n - 3; i >= 0; i--)
    {
        if (arr[i] + arr[i + 1] > arr[i + 2])
        {
            return arr[i] + arr[i + 1] + arr[i + 2];
        }
    }
    return 0;
}