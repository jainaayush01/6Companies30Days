// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minLen = INT_MAX, n = nums.size();
        int sum = 0, i = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += nums[j];
            while (sum >= target)
            {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                ++i;
            }
        }
        return minLen != INT_MAX ? minLen : 0;
    }
};