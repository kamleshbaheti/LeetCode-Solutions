/*
    Algorithm : Depth-First Search (DFS)
    Language : C++
    Time Complexity : O(m*n)
    Space Complexity : O(m*n)
    Date of Submission : 21/June/2023
*/



class Solution 
{
private:
    bool isValid(vector<vector<int>> &land, int row, int col, vector<vector<bool>> &visit)
    {
        if(row >= 0 && row < land.size() && col >= 0 && col < land[0].size() && land[row][col] == 1 && visit[row][col] == false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void dfs_func(vector<vector<int>> &land, vector<vector<bool>> &visit, int row, int col, vector<int> &arr)
    {
        if(!isValid(land, row, col, visit))
        {
            return;
        }
        else
        {
            visit[row][col] = true;
            arr[2] = max(arr[2], row);
            arr[3] = max(arr[3], col);
            if(isValid(land, row+1, col, visit))
            {
                dfs_func(land, visit, row+1, col, arr);
            }
            if(isValid(land, row-1, col, visit))
            {
                dfs_func(land, visit, row-1, col, arr);
            }
            if(isValid(land, row, col+1, visit))
            {
                dfs_func(land, visit, row, col+1, arr);
            }
            if(isValid(land, row, col-1, visit))
            {
                dfs_func(land, visit, row, col-1, arr);
            }
            return;
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<bool>> visited(land.size(), vector<bool> (land[0].size(), false));
        vector<vector<int>> ans;
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[0].size(); j++)
            {
                if(land[i][j] == 1 && visited[i][j] == false)
                {
                    vector<int> arr(4, 0);
                    arr[0] = i;
                    arr[1] = j;
                    dfs_func(land, visited, i, j, arr);
                    ans.push_back(arr);
                }
            }
        }
        return ans;
    }
};


// Solution Link: https://leetcode.com/problems/find-all-groups-of-farmland/solutions/3666697/faster-than-902-c-dfs-easy-solution
