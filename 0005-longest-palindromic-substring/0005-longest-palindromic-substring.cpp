#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     int longestPalindromeSubseq(string s)
//     {
//         int size = INT_MIN;
//         string str = "";
//         for (int i = 0; i < s.size(); i++)
//         {
//             for (int k = 1; k = s.size() - i; k++)
//             {
//                 str = s.substr(i, k);
//                 string str2 = str;
//                 reverse(str.begin(), str.end());
//                 if (str == str2)
//                     size = max((int)size, (int)str.size());
//             }
//         }
//         return size
//     }
// };

class Solution
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int k = i; k < s.size(); k++)
            {
                if (isPalindrome(s, i, k))
                {
                    string t = s.substr(i, k - i + 1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};