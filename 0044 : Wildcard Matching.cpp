/*
      Algorithm : Two Pointers
      Language : C++
      Time Complexity : O(n)
      Space Complexity : O(1)
      Date of Submission : 16/July/2023
*/


class Solution 
{
public:
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0, a = -1, b = -1;
        while(i < s.length())
        {
            if(j < p.length() && (s[i] == p[j] || p[j] == '?'))
            {
                i++;
                j++;
            }
            else if(j < p.length() && p[j] == '*')
            {
                a = i;
                b = j;
                j++;
            }
            else
            {
                if(b >= 0)
                {
                    i = a+1;
                    j = b+1;
                    a++;
                }
                else
                {
                    return false;
                }
            }
        }
        while(j < p.length() && p[j] == '*')
        {
            j++;
        }
        return j == p.length();
    }
};
