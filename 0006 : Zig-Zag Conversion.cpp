/*
    Method : Two Pointers
    Language : C++
    Time Complexity : O(n)
    Space Complexity : O(n)
    Date of Submission : 18/July/2023
*/


class Solution 
{
public:
    string convert(string s, int num) 
    {
        if(num == 1)
        {
            return s;
        }
        else
        {
            int k = 0, x = -1;
            vector<string> arr(num, "");
            for(int i = 0;  i < s.length(); i++)
            {
                arr[k].push_back(s[i]);
                if(k == 0 || k == num-1)
                {
                    x = 0-x;
                }
                if(x == -1)
                {
                    k--;
                }
                else
                {
                    k++;
                }
            }
            string str;
            for(int i = 0; i < arr.size(); i++)
            {
                str += arr[i];
            }
            return str;
        }
    }
};
