// Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Question: Iterate throught the string and for every element output the
    // first element in the string which haven't been repeated yet.
    // So to remember first non-repeated element we will use a queue.
    // Once the frequency of element at front > 1 then we remove it from queue.
    // if queue is empty we output '#' otherwise element at front.
public:
    string FirstNonRepeating(string A)
    {
        int freq[26] = {0};
        queue<char> q;
        string ans = "";
        for (char &ch : A)
        {
            freq[ch - 'a']++;

            if (freq[ch - 'a'] == 1)
            {
                q.push(ch);
            }

            while (!q.empty() && freq[q.front() - 'a'] != 1)
            {
                q.pop();
            }

            char op = q.empty() ? '#' : q.front();
            ans += op;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends