/*
    Algorithm : Depth-First Search (DFS)
    Language : C++
    Time Complexity : O(m*n)
    Space Complexity : O(1)
    Date of Submission : 22/June/2023
*/



class Solution
{
private:
    bool dfs_func(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int row, int col)
    {
        if(row < 0 || col < 0 || row >= grid2.size() || col >= grid2[0].size() || grid2[row][col] != 1)
        {
            return true;
        }
        if(grid1[row][col] == 0)
        {
            return false;
        }
        grid2[row][col] = 2;
        bool w = dfs_func(grid1, grid2, row+1, col);
        bool x = dfs_func(grid1, grid2, row-1, col);
        bool y = dfs_func(grid1, grid2, row, col+1);
        bool z = dfs_func(grid1, grid2, row, col-1);
        return (w && x && y && z);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int count = 0;
        for(int i = 0; i < grid2.size(); i++)
        {
            for(int j = 0; j < grid2[0].size(); j++)
            {
                if(grid2[i][j] == 1 && dfs_func(grid1, grid2, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};


// Solution Link: https://leetcode.com/problems/count-sub-islands/submissions/977225604
