/*
  Algorithm : Iteration - Tree
  Language : C++
  Time Complexity : O(log2(label))
  Space Complexity : O(No. of Valid Parents) / Constant
  Date of Submission : 08/June/2023
*/



class Solution {
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int> arr;
        int height = log2(label);
        arr.push_back(label);
        int parent = label/2;
        while(height)
        {
            int min_node = pow(2, height-1);
            int max_node = pow(2, height)-1;
            int current_parent = min_node + max_node - parent;
            arr.push_back(current_parent);
            parent = current_parent/2;
            height--;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};
