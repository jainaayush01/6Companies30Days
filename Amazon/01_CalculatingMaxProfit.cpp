// Link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxProfit(int K, int N, int a[])
    {
        // looks like DP problem as We can do multiple trades but only after one is finished
        // so we have multiple choices between where to make the trades.
        // whenever we make a trade we take maximum value from all previous values
        // making sure we do trades after one other and having the maximum profit
        vector<vector<int>> dp(K + 1, vector<int>(N, 0));
        for (int i = 1; i <= K; ++i)
        {
            int mx = INT_MIN;
            for (int j = 1; j < N; ++j)
            {
                mx = max(mx, dp[i - 1][j - 1] - a[j - 1]);
                dp[i][j] = max(dp[i][j - 1], mx + a[j]);
            }
        }
        return dp[K][N - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} // } Driver Code Ends