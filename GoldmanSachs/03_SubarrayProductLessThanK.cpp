// Link: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
  // Solution: 
  // Sliding Window would be a way to go as we need contiguous subsets
  // Case1: lets say we arrive at a num if it is less than k then we increment ans
  // we multiply it with previous product and 
  // (Case1.1) if it still remains less than k 
  // we increment ans by (size of window excluding curr num)
  // (Case 1.2) else we move left side of window until product is less than k
  // and wherever we stop we increment ans by (size of window excluding curr num)
  // move forward to next num
  // Case 2: if it is greater than k we can start with a new window (we dont want to waste time)
  
  
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        int ans = 0, i = 0, j = 0;
        long long int product = 1;
        while(j < n) {
            if(arr[j] > k) {
                j++;
                i=j;
                product = 1;
                continue;
            }
            product *= arr[j];
            while(i < n && product >= k) {
                product /= arr[i];
                ++i;
            }
            if(product < k) {
                ans += j - i + 1;
            }
            ++j;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends