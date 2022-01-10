// Link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];

        for (int i = 0; i < 26; ++i)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insertword(string word, TrieNode *node)
    {
        if (word.size() == 0)
        {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (node->children[index] != NULL)
        {
            child = node->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        insertword(word.substr(1), child);
    }

    // bool search(string word, TrieNode *node){
    //     if(word.size()==0){
    //         return node->isTerminal;
    //     }
    //     int index=word[0]-'a';
    //     TrieNode *child=node->children[index];
    //     if(child==NULL){
    //         return false;
    //     }
    //     else{
    //         return search(word.substr(1),child);
    //     }
    // }

    void removeWord(string word, TrieNode *node)
    {
        if (word.size() == 0)
        {
            node->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child = node->children[index];
        if (child == NULL)
        { // word not found
            return;
        }
        else
        {
            removeWord(word.substr(1), child);
        }

        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void printTrie(TrieNode *node, char str[], int level)
    {
        if (node->isTerminal)
        {
            str[level] = '\0';
            cout << str << endl;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (node->children[i])
            {
                str[level] = 'a' + i;
                printTrie(node->children[i], str, level + 1);
            }
        }
    }

public:
    void insertword(string word)
    {
        insertword(word, root);
    }

    // bool search(string word){
    //     return search(word, root);
    // }
    void searchUtil(TrieNode *node, string pre, vector<string> &preRes)
    {
        if (node->isTerminal)
        {
            preRes.push_back(pre);
            // return;
        }
        for (int i = 0; i < 26; ++i)
        {
            TrieNode *child = node->children[i];
            if (child != NULL)
            {
                // cout << child->data;
                searchUtil(child, pre + char('a' + i), preRes);
            }
        }
    }

    void search(string word, vector<vector<string>> &res, int m)
    {
        string pre = "";
        TrieNode *prev = this->root;

        for (int i = 0; i < m; ++i)
        {
            pre += word[i];
            TrieNode *curr = prev->children[word[i] - 'a'];
            if (curr != NULL)
            {
                vector<string> preRes;
                searchUtil(curr, pre, preRes);
                // cout << preRes.size();
                // for(auto x : preRes) {
                //     for(auto y:x) {
                //         cout << y << " ";
                //     }
                //     cout << endl;
                // }
                res.push_back(preRes);
            }
            else
            {
                while (i < m)
                {
                    res.push_back({"0"});
                    ++i;
                }
            }
            prev = curr;
        }
    }

    void removeWord(string word)
    {
        removeWord(word, root);
    }

    void printTrie()
    {
        char str[50];
        printTrie(root, str, 0);
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie t;
        for (int i = 0; i < n; ++i)
        {
            t.insertword(contact[i]);
        }

        // t.printTrie();
        // cout << s << s.size();

        int m = s.size();
        vector<vector<string>> res;
        t.search(s, res, m);
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
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends