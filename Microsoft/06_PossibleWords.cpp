// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Solution:
    // store the digit - char mapping and we do a dfs traversal
    // and whenever a digit is traversed we go through each char in a digit
    // and pop it when the char is traversed
    void getWords(int arr[], int i, int &N, string &str, vector<string> &res, string mp[])
    {
        if (i == N)
        {
            res.push_back(str);
            return;
        }

        for (char ch : mp[arr[i]])
        {
            str.push_back(ch);
            getWords(arr, i + 1, N, str, res, mp);
            str.pop_back();
        }
    }

    vector<string> possibleWords(int arr[], int N)
    {
        string str = "";
        vector<string> res;
        string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        getWords(arr, 0, N, str, res, mp);
        return res;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends