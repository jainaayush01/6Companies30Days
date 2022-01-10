// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long countWays(int m)
    {
        return (long long)(m / 2) + 1;
    }
};

// { Driver Code Starts.
int main()
{
    // taking count of testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
} // } Driver Code Ends