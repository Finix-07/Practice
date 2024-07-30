#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minimumDeletions(string s)
{
    int n = s.size();
    int right_a = 0;
    int left_b = 0;
    int deletions = INT_MAX;

    if (n < 2)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            right_a += 1;
        }
    }
    if (right_a == 0)
    {
        return 0;
    }
    for (auto &x : s)
    {
        if (x == 'a')
        {
            right_a -= 1;
        }
        
        deletions = min(deletions, right_a + left_b);


        if (x == 'b')
        {
            left_b += 1;
        }
    }

    return deletions;
}

int main()
{
    string s = "b";

    cout << "The number of deletions are: ";
    cout << minimumDeletions(s);

    return 0;
}