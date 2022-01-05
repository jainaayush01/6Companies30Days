// Link:https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        vector<int> rem(k, 0);
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int rmd = nums[i] % k;
            if (rmd < 0)
            {
                rmd += k;
            }
            rem[rmd]++;
        }
        for (int i = 1; i < k; ++i)
        {
            if (rem[i] != rem[k - i])
            {
                return false;
            }
        }
        return rem[0] % 2 == 0;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} // } Driver Code Ends