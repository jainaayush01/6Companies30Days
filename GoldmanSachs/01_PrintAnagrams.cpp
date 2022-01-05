// Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // Solution: 
    // To know if two strings are anagrams we need to sort the strings
    // to remember the original string we take a hashmap and store the lexicograpical small anagram
    // as the key and original strings as a vector of strings
   
    vector<vector<string> > Anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ret;
        
        int i = 0;
        for (auto x : arr) {
            sort(x.begin(), x.end());
            mp[x].push_back(arr[i]);
            ++i;
        }

        for(auto x : mp) {
            ret.push_back(x.second);
        }
        return ret;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends