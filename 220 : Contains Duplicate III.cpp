/*
  Algorithm : Binary Search
  Language : C++
  Time Complexity : O(n2)
  Space Complexity : O(n)
  Date of Submission : 13/May/2023
*/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
    {
        vector<pair<int, int>> vp(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            vp[i].first = nums[i];
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        for(int i = 0; i < vp.size()-1; i++)
        {
            for(int j = i+1; j < vp.size(); j++)
            {
                if(abs(vp[i].first - vp[j].first) <= valueDiff)
                {
                    if(abs(vp[i].second - vp[j].second) <= indexDiff)
                    {
                        return true;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }
};

// Solution Link : https://leetcode.com/problems/contains-duplicate-iii/solutions/3520890/c-beginner-approach-easy-solution/
