// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int subsetSum(int arr[], int n, int targetSum)
    {
        // Dynamic Programming
        // 01 knapsack problem
        // choice: select the number or do not select the number
        int dp[n + 1][targetSum + 1];
        // dp[i][j] = displays is sum=j possible from
        // subset of the first i elements of arr

        // iniitalization:
        for (int j = 1; j <= targetSum; ++j)
        {
            dp[0][j] = 0; // sum=1...sum not possible from first 0 elements
        }
        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = 1; // sum=0 possible for first i=0...N by using empty subset
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= targetSum; ++j)
            {
                if (j >= arr[i - 1])
                {
                    // if sum was possible from i-1 elements
                    // if not then if sum=j-arr[i-1] was possible from 0-1 elements
                    // dp[i-1][j] tells if the subset was formed without arr[i-1] or not
                    // so basially dp[N][sum] tells us by going through all the subsets
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                { // if greater than the curr ans = previous ans
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        // for(int i = 0; i <= n; ++i) {
        //     for(int j = 0; j <= targetSum; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int j = targetSum; j >= 0; --j)
        {
            if (dp[n][j])
            {
                return j;
            }
        }
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here
        // dynamic programming - subset sum similar problem
        int totalSum = 0;
        for (int i = 0; i < n; ++i)
        {
            totalSum += arr[i];
        }
        int foundSum = subsetSum(arr, n, totalSum / 2);
        return totalSum - 2 * foundSum;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends