// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // Solution:
        // str1 + str2 == str2 + str1 as gcd divides equally
        // size of gcd string can be found by finding gcd of the numbers
        if (str1 + str2 != str2 + str1)
            return "";

        return str1.substr(0, __gcd(str1.length(), str2.length()));
    }
};