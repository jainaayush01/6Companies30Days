// Link: https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // Solution: 
        // x11 = L1[0] x12 = R1[0], y11 = R1[1], y12 = L1[1]
        // x21 = L2[0] x22 = R2[0], y21 = R2[1], y22 = L2[1]
        // not overlapping cases:
        
        // x11 > x22 || x21 > x12
        // y21 > y12 || y11 > y22
        
        if (L1[0] > R2[0] || L2[0] > R1[0])
            return false;

        if (L1[1] < R2[1] || L2[1] < R1[1])
            return false;

        return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends