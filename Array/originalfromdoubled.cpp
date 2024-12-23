#include <bits/stdc++.h>

using namespace std;

vector<int> findOriginalArray(vector<int> &changed)
{
    vector<int> res;
    int n = changed.size();

    if (n % 2 != 0)
    {
        return {};
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[changed[i]]++;
    }

    sort(changed.begin(), changed.end());

    for (int i = 0; i < n; i++)
    {
        if (mp[changed[i]] == 0)
        {
            continue;
        }
        int result = changed[i] * 2;

        if (mp[result] == 0)
        {
            return {};
        }

        else
        {
            res.push_back(changed[i]);
            mp[changed[i]]--;
            mp[result]--;
        }
    }

    return res;
}
int main()
{

    return 0;
}