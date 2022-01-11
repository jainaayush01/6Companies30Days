// LC: https://leetcode.com/problems/course-schedule/
// GFG: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPossible(int n, vector<pair<int, int>> &p)
    {
        // Code here
        // lets consider pre-req as all the edges and it will represent a directed graph
        // if there is a cylce in graph then it is not possible

        // Typical Topological Sort Question
        // convert into adjacency list and do the top sort

        vector<int> v[n];
        vector<int> in(n, 0);
        int count = 0;
        for (int i = 0; i < p.size(); i++)
        {
            v[p[i].first].push_back(p[i].second);
            in[p[i].second]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (in[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for (int node : v[curr])
            {
                in[node]--;
                if (in[node] == 0)
                    q.push(node);
            }
        }
        return count == n;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends