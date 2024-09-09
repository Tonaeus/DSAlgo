/* 
    Problem
     - Find the modified image by applying a flood fill starting at the specified pixel, where all pixels connected 4-directionally with the same colour are replaced by the specified colour

    Approaches
     1. Check if the current pixel is valid, and if it is, update its colour, and then repeat the step for the horizontally and vertically connected pixels

    Data Structures
     - Matrix
    Algorithms
     - Flood fill

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        dfs(image, sr, sc, m, n, image[sr][sc], color);

        return image;
    }

private: 
    void dfs(vector<vector<int>>& image, int i, int j, int m, int n, int oColor, int nColor) {
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != oColor || image[i][j] == nColor) {
            return;
        }

        image[i][j] = nColor;

        dfs(image, i - 1, j, m, n, oColor, nColor);
        dfs(image, i + 1, j, m, n, oColor, nColor);
        dfs(image, i, j - 1, m, n, oColor, nColor);
        dfs(image, i, j + 1, m, n, oColor, nColor);
    }
};
