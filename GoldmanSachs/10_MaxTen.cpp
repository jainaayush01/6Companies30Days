class Solution
{
    vector<int> maxTenNumbers(vector<int> &a, int n)
    {
        // Q: Find Max Ten Numbers in a Million Entries Given.
        // A: Keep Priority Queue(Min Heap) of 10 numbers
        // remove min number when a bigger number is found
        vector<int> maxTen;

        // declaring a minheap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < 10; i++)
        {
            minHeap.push(a[i]);
        }

        for (int i = 10; i < n; i++)
        {
            if (arr[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(a[i]);
            }
        }

        while (!minHeap.empty())
        {
            maxTen.push_back(minHeap.top());
            minHeap.pop();
        }
        return maxTen;
    }
};