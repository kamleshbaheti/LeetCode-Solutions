/*
    Algorithm : Iteration
    Language : C++
    Time Complexity : O(logn)
    Space Complexity : O(n)
    Date of Submission : 18/July/2023
*/


class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string s;
        while(n)
        {
            n = n-1;
            s.push_back(n%26 + 'A');
            n = n/26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
