// Link: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // We will use quick sort
    // where we will find the actual position of nuts using pivot element of bolts
    // and then we will use the char at that position in nuts nad partion it accordingly
    int partition(char array[], int low, int high, char pivot)
    {
        int i = low;
        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
                swap(array[i++], array[j]);
            else if (array[j] == pivot)
                swap(array[j--], array[high]);
        }
        swap(array[i], array[high]);
        return i;
    }

    void quicksort(char nuts[], char bolts[], int l, int h)
    {
        if (l >= h)
            return;
        int pos = partition(nuts, l, h, bolts[h]); // main logic
        partition(bolts, l, h, nuts[pos]);         // main logic
        quicksort(nuts, bolts, l, pos - 1);
        quicksort(nuts, bolts, pos + 1, h);
    }
    void matchPairs(char nuts[], char bolts[], int n)
    {
        quicksort(nuts, bolts, 0, n - 1);
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
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++)
        {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends