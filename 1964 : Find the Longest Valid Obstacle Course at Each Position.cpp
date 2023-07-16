/*
    Algorithm : Iteration
    Language : C++
    Time Complexity : O(n2)
    Space Complexity : O(n)
    Date of Submission : 07/May/2023
*/


class Solution 
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> arr1, arr2;
        for(int i : obstacles)
        {
            if(arr1.empty() || i >= arr1.back())
            {
                arr1.push_back(i);
                arr2.push_back(arr1.size());
            }
            else
            {
                int index = upper_bound(arr1.begin(), arr1.end(), i) - arr1.begin();
                arr1[index] = i;
                arr2.push_back(index + 1);
            }
        }
        return arr2;
    }
};

// Solution Link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/solutions/3496710/c-simple-solution-easiest-approach/
