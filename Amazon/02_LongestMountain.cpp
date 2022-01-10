// Link: https://leetcode.com/problems/longest-mountain-in-array/
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        // 1 Key Observation to Note:
        // When you see that when you are counting length of downhill then
        // if ai < aj (;i > j) then it will obviously going to be included in
        // counting of uphill length so you dont need to worry about it.

        // Solution:
        // Store max downhill length and uphill length for each element
        // return max of all elements at peak.

        int N = arr.size(), res = 0;
        vector<int> up(N, 0), down(N, 0);

        for (int i = N - 2; i >= 0; --i)
        {
            if (arr[i] > arr[i + 1])
            { // downhill length
                down[i] = down[i + 1] + 1;
            }
        }

        for (int i = 0; i < N; ++i)
        {
            if (i > 0 && arr[i] > arr[i - 1])
            { // uphill length
                up[i] = up[i - 1] + 1;
            }

            if (up[i] && down[i])
            { // condition to check peak of mountain
                res = max(res, up[i] + down[i] + 1);
            }
        }

        return res;
    }
};