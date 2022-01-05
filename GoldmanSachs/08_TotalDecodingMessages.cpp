// Link:https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int M = 1e9 + 7;
    int CountWays(string str)
    {
        int n = str.length();
        if (str[0] == '0')
            return 0;
        if (n == 1)
            return 1;

        int dp[n + 1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (str[i - 1] != '0')
            {
                dp[i] = (dp[i] + dp[i - 1]) % M;
            }
            if (str[i - 2] != '0')
            {
                if ((str[i - 2] - '0') * 10 + (str[i - 1] - '0') <= 26)
                {
                    dp[i] += dp[i - 2] % M;
                }
            }
        }
        return dp[n] % M;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends