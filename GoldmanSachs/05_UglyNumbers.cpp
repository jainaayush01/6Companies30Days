// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    // only prime factors of 2,3,5 should be there
    // so we cant add all mulitples of 2, 3 and5 but only which are combination of 2,3 & 5
    // using set to not allow duplicates

    ull getNthUglyNo(int n)
    {
        // code here
        set<ull> s;
        s.insert(1);
        n--;
        while (n--)
        {
            auto it = s.begin();
            ull x = *it;
            s.erase(it);
            s.insert(x * 2);
            s.insert(x * 3);
            s.insert(x * 5);
        }
        return *s.begin();
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
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends