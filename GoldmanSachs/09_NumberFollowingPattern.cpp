// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Decrement easily (add it to stack and empty when incrementing taking care we add a number before empyting stack so that next element is already incremented)
    // all logic goes on increment side...
    string printMinNumberForPattern(string S)
    {
        // code here
        string ans = "";
        stack<int> stk;
        int num = 1, n = S.size();
        for (int i = 0; i < n; ++i)
        {
            if (S[i] == 'D')
            {
                stk.push(num++);
            }
            else
            {
                stk.push(num++);
                while (!stk.empty())
                {
                    ans += to_string(stk.top());
                    stk.pop();
                }
            }
        }
        stk.push(num++);
        while (!stk.empty())
        {
            ans += to_string(stk.top());
            stk.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
// } Driver Code Ends