/*
    Algorithm : Depth-First Search (DFS)
    Language : C++
    Time Complexity : O(m*n)
    Space Complexity : O(m*n)
    Date of Submission : 24/June/2023
*/



class Solution
{
private:
    bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &visit, int row, int col)
    {
        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] != 0 && visit[row][col] == false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void dfs_func(vector<vector<int>> &grid, vector<vector<bool>> &visit, int row, int col, int &temp)
    {
        if(!isValid(grid, visit, row, col))
        {
            return;
        }
        else
        {
            visit[row][col] = true;
            temp += grid[row][col];
            if(isValid(grid, visit, row+1, col))
            {
                dfs_func(grid, visit, row+1, col, temp);
            }
            if(isValid(grid, visit, row-1, col))
            {
                dfs_func(grid, visit, row-1, col, temp);
            }
            if(isValid(grid, visit, row, col+1))
            {
                dfs_func(grid, visit, row, col+1, temp);
            }
            if(isValid(grid, visit, row, col-1))
            {
                dfs_func(grid, visit, row, col-1, temp);
            }
            return;
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int temp = 0, count = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool> (grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] > 0 && visit[i][j] == false)
                {
                    temp = 0;
                    dfs_func(grid, visit, i, j, temp);
                    count = max(temp, count);
                }
            }
        }
        return count;
    }
};


// Auxilary : Space Complexity can be reduced to Constant-Space if grid elements are replaced with (-1) instead of updating Visited array. No need to make Visit array in this case.
// Solution Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/solutions/3677816/faster-c-dfs-easy-solution
