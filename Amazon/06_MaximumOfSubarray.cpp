// Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        deque<int> maxValIdx; // front stores the next max value's idx

        int i = 0;
        while (i < n)
        {
            // remove invalid maxValue from front
            while (!maxValIdx.empty() && maxValIdx.front() <= i - k)
            {
                maxValIdx.pop_front();
            }

            // remove values from back less than curr element
            while (!maxValIdx.empty() && arr[maxValIdx.back()] < arr[i])
            {
                maxValIdx.pop_back();
            }

            maxValIdx.push_back(i);

            if (i >= k - 1)
            {
                res.push_back(arr[maxValIdx.front()]);
            }
            ++i;
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

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends