// Link:https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/
// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findPosition(int N, int M, int K)
    {
        // code here
        // cases: add K , modulo N, and check for 0
        if (N == 1)
            return 1;
        int m = ((M % N) + K - 1) % N;

        return m == 0 ? N : m;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, K;

        cin >> N >> M >> K;

        Solution ob;
        cout << ob.findPosition(N, M, K) << endl;
    }
    return 0;
} // } Driver Code Ends