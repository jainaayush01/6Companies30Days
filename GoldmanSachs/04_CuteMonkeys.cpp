// Link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this function */

// simple
// no explaination needed i guess
string encode(string src)
{
    //Your code here
    int n = src.size();
    string newstr = "";
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (src[i] == src[j])
        {
            j++;
        }
        newstr += src[i] + to_string(j - i);
        i = j;
    }
    return newstr;
}
