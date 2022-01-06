// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Solution:
    // Store the ending of the brackets using stack
    // now decode the string normally
    unordered_map<int, int> idx;
    string decode(string s, int i, int j)
    {
        string ret = "";
        stack<int> stk;
        int product = 0;

        while (i <= j)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                product = product * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                string midAns = decode(s, i + 1, idx[i] - 1);
                for (int k = 0; k < product; ++k)
                {
                    ret += midAns;
                }
                product = 0;
                i = idx[i];
            }
            else
            {
                ret += s[i];
            }
            ++i;
        }
        return ret;
    }

    string decodedString(string s)
    {
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
            {
                stk.push(i);
            }
            else if (s[i] == ']')
            {
                idx[stk.top()] = i;
                stk.pop();
            }
        }
        return decode(s, 0, n - 1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
} // } Driver Code Ends