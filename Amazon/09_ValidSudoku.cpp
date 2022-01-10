// Link: https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Bruteforce no magic
class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        int row[10][10] = {0};
        int col[10][10] = {0};
        int grid[10][10] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int num = mat[i][j];
                if (num == 0)
                    continue;

                int grid_idx = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || grid[grid_idx][num])
                {
                    return 0;
                }
                row[i][num] = col[j][num] = grid[grid_idx][num] = 1;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
} // } Driver Code Ends