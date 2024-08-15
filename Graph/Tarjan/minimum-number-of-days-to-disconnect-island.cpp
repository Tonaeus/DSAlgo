/* 
    Problem
     - Find the minimum number of days to disconnect a grid by changing any single land cell to a water cell at most once a day, where an island is a horizontally and vertically connected group of "1"s, and a grid is disconnected if it does not contain exactly 1 island

    Approaches
     1. Determine the number of islands, and if there is only one island, also determine whether it is of size 1 or 2 and whether there are any articulation points
      a. Consider that if there are no islands, then no change is needed
      b. Consider that if there is more than 1 island, then no change is needed
      e. Consider that if there is exactly 1 island of size 1 or 2, then change all land cells in that island to water cells
      c. Consider that if there is exactly 1 island with no articulation points, then 2 changes are needed
      d. Consider that if there is exactly 1 island with any articulation points, then 1 change is needed

    Data Structures
     - Graph 
    Algorithms
     - Tarjan

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(m•n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> disc(m, vector<int>(n, -1));
        vector<vector<int>> low(m, vector<int>(n, -1));
        vector<vector<bool>> ap(m, vector<bool>(n, false));
        int t = 0;

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int islandCnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && disc[i][j] == -1) {
                    ap[i][j] = dfs(i, j, -1, -1, grid, disc, low, ap, t, dir) > 1;
                    islandCnt++;
                }
            }
        }

        if (islandCnt == 0 || islandCnt > 1) return 0;

        if (t == 1) return 1;
        if (t == 2) return 2;

        int apCnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ap[i][j] == true) {
                    apCnt++;
                }
            }
        }

        return apCnt ? 1 : 2;
    }

private:
    int dfs(int i, int j, int pi, int pj, vector<vector<int>>& grid, vector<vector<int>>& disc, vector<vector<int>>& low, vector<vector<bool>>& ap, int& t, vector<vector<int>>& dir) {
        int m = grid.size();
        int n = grid[0].size();
        
        disc[i][j] = low[i][j] = t++;
        int chdCnt = 0;
        
        for (auto d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if ((ni < 0 || ni >= m || nj < 0 || nj >= n) || (ni == pi && nj == pj) || (grid[ni][nj] == 0)) {
                continue;
            }

            if (disc[ni][nj] == -1) {
                chdCnt++;
                dfs(ni, nj, i, j, grid, disc, low, ap, t, dir);
                if (disc[i][j] <= low[ni][nj]) {
                    ap[i][j] = true;
                }
                low[i][j] = min(low[i][j], low[ni][nj]);
            }
            else {
                low[i][j] = min(low[i][j], disc[ni][nj]);
            }
        }

        return chdCnt;
    }
};