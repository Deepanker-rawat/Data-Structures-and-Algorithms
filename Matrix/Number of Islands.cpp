// Problem link: https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    void solve(vector<vector<char>>& grid, int i, int j) {

        int m = grid.size();
        int n = grid[0].size();

        // base case
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        // recursive case
        solve(grid, i + 1, j);
        solve(grid, i - 1, j);
        solve(grid, i, j + 1);
        solve(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    solve(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
