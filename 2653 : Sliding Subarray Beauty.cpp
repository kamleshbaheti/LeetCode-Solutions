/*
  Algorithm : Iteration
  Language : C++
  Time Complexity : O(n * 101)
  Space Complexity : O(101)
  Date of Submission : 25/April/2023
*/


class Solution 
{
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        vector<int> arr1(101, 0);
        vector<int> arr2(nums.size()-k+1);
        int index = 0, count = 0, temp = 0;
        for(int i = 0; i < k-1; i++)
        {
            arr1[nums[i] + 50]++;
        }
        for(int i = k-1; i < nums.size(); i++)
        {
            arr1[nums[i] + 50]++;
            for(int j = 0; j <= 100; j++)
            {
                count += arr1[j];
                if(x <= count)
                {
                    temp = j - 50;
                    if(temp > 0)
                    {
                        arr2[index++] = 0;
                        break;
                    }
                    else
                    {
                        arr2[index++] = temp;
                        break;
                    }
                }
            }
            count = 0;
            arr1[nums[i-k+1] + 50]--;
        }
        return arr2;
    }
};

// Solution Link: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/solutions/3611276/c-proper-explaination-using-formula/
