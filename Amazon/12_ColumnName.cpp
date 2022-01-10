// Link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string colName(long long int n)
    {
        string res = "";
        while (n > 0)
        {
            int tmp = (n - 1) % 26;
            char ch = ('A' + tmp);
            res = ch + res;
            n = (n - 1) / 26;
        }
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
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}
// } Driver Code Ends