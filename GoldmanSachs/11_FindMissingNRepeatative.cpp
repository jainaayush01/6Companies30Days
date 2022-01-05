// Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // Solution:
        // since no num is negative whenever you visit a number
        // mark that locaiton in array as negative
        // if you visit the location and if it is negative it is the repetative num
        // after visiting whole array
        // revisi and if finding a location positive then it is missing number
        // handle case for negative indexes
        int *a = new int[2];
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] < 0)
                a[0] = abs(arr[i]);

            else
                arr[abs(arr[i]) - 1] *= -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                a[1] = i + 1;
        }

        return a;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends