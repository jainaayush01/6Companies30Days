// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Just go and do as told - keep pointers to row begin and end, & col beg and end
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int m, int n)
    {
        vector<int> vec;
        int i = 0, l = 0, r = n - 1, u = 0, d = m - 1;
        while (l <= r && u <= d)
        {
            for (int j = l; j <= r; ++j)
            {
                vec.push_back(matrix[u][j]);
            }
            u++;

            for (int j = u; j <= d; ++j)
            {
                vec.push_back(matrix[j][r]);
            }
            r--;

            if (l <= r && u <= d)
            {
                for (int j = r; j >= l; --j)
                {
                    vec.push_back(matrix[d][j]);
                }
            }
            d--;

            if (u <= d && l <= r)
            {
                for (int j = d; j >= u; --j)
                {
                    vec.push_back(matrix[j][l]);
                }
            }
            l++;
            // ++l; --r;
            // ++u; --d;
        }
        return vec;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends