// Link:https://practice.geeksforgeeks.org/problems/burning-tree/1/#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // max distance between the target node and leaf
    int ans = 0;
    pair<int, bool> dfs(Node *root, int target)
    {
        if (root == NULL)
        {
            return {0, false};
        }

        if (root->data == target)
        {
            ans = max(dfs(root->left, target).first, dfs(root->right, target).first);
            return {1, true};
        }

        pair<int, bool> left = dfs(root->left, target);
        pair<int, bool> right = dfs(root->right, target);

        if (left.second)
        {
            ans = max(ans, right.first + left.first);
            return {left.first + 1, true};
        }
        else if (right.second)
        {
            ans = max(ans, right.first + left.first);
            return {right.first + 1, true};
        }
        else
        {
            return {max(left.first, right.first) + 1, false};
        }
    }

    int minTime(Node *root, int target)
    {
        dfs(root, target);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}
// } Driver Code Ends