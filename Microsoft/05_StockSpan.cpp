// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Solution: create a stack and store the pair of element and its stock span
    // while traversing a element pop all elements with lesser price and add their
    // stock span to calculate the stock span at that day
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> res;
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; ++i)
        {
            int tmp = 1;
            while (!stk.empty() && stk.top().first <= price[i])
            {
                tmp += stk.top().second;
                stk.pop();
            }
            stk.push({price[i], tmp});
            res.push_back(tmp);
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
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends