// Link:https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// ### Recursive Approach:
// 1. Find i, j
// 2. Find Base Condition
//     * Think of first invalid Input: (i > j) return 0
// 3. We have to take i and j
// 4. Loop k from i to j then call function on i = i and j = k and 2nd call on i = k+1 j = j
// 5. and then we calcuate ans from tempAns of the each loop

class Solution
{
    int dp[30][30];
    int bracket[30][30];

    int solve(int arr[], int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            if (temp < ans)
            {
                ans = temp;
                bracket[i][j] = k;
            }
        }

        return dp[i][j] = ans;
    }

    void printParenthesis(int i, int j, char &name, string &res)
    {
        if (i == j)
        {
            res += name;
            name++;
            return;
        }
        res += '(';
        printParenthesis(i, bracket[i][j], name, res);
        printParenthesis(bracket[i][j] + 1, j, name, res);
        res += ')';
    }

public:
    string matrixChainOrder(int p[], int n)
    {
        memset(dp, -1, sizeof(dp));
        solve(p, 1, n - 1);
        char ch = 'A';
        string res = "";
        printParenthesis(1, n - 1, ch, res);
        return res;
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
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
} // } Driver Code Ends