/* 
    Problem
     - Find all lucky numbers, where a lucky number is an element that is the minimum element in its row and maximum in its column

    Approaches
     1. Locate the minimum element in each row and check if each of these elements is also the maximum element in their respective columns
      a. Consider that if a number is both a minimum and a maximum, then it is considered a lucky number
     2. Locate the minimum element in each row and select the maximum among those elements
      a. Consider that all elements in the matrix are distinct
      b. Consider that there can be no lucky number 
      b. Proof by contradiction that there cannot be more than one lucky number
            Suppose that "x" is a lucky number at row 1 and column 1
            Suppose that "y" is a lucky number at row 2 and column 2
            Then, "x" is minimum in its row and maximum in its column 
            Then, "y" is minimum in its row and maximum in its column 
            Let "a" be an element at row 1 and column 2
            Then, "x" < "a" and "y" > "a"
            Then, "x" < a < "y"
            Thus, "x" < "y"
            Let "b" be an element at row 2 and column 1
            Then, "x" > "b" and "y" < "b" 
            Then, "y" < "b" < "x"
            Thus, "y" < "x"
            However, "x" > "y"
            This shows that "y" is not a lucky number, which contradict the assumption 
            Therefore, there cannot be more than one lucky number
        
    Data Structures
     - Matrix
    Algorithms

    Time Complexity
     - O(m•n) -> m = number of rows, n = number of columns
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        return row < col ? rowHelper(matrix, row, col) : colHelper(matrix, row, col);
    }
private:
    vector<int> rowHelper(vector<vector<int>>& matrix, int row, int col) {
        vector<int> res;
        unordered_set<int> set;
        for (int i = 0; i < row; i++) {
            set.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        for (int i = 0; i < col; i++) {
            auto cmp = [i](const vector<int>& a, const vector<int>& b) { return a[i] < b[i]; };
            int mx = (*max_element(matrix.begin(), matrix.end(), cmp))[i];
            if (set.contains(mx)) {
                res.push_back(mx);
            }
        }
        return res;
    }
    vector<int> colHelper(vector<vector<int>>& matrix, int row, int col) {
        vector<int> res;
        unordered_set<int> set;
        for (int i = 0; i < col; i++) {
            auto cmp = [i](const vector<int>& a, const vector<int>& b) { return a[i] < b[i]; };
            int mx = (*max_element(matrix.begin(), matrix.end(), cmp))[i];
            set.insert(mx);
        }
        for (int i = 0; i < row; ++i) {
            int mn = *min_element(matrix[i].begin(), matrix[i].end());
            if (set.contains(mn)) {
                res.push_back(mn);
            }
        }
        return res;
    }
};

// Solution 2

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int mxRow = 0;
        int mnCol = INT_MAX;

        for (int i = 0; i < row; i++) {
            mxRow = max(mxRow, *min_element(matrix[i].begin(), matrix[i].end()));
        }
        for (int i = 0; i < col; i++) {
            auto cmp = [i](const vector<int>& a, const vector<int>& b) { return a[i] < b[i]; };
            mnCol = min(mnCol, (*max_element(matrix.begin(), matrix.end(), cmp))[i]);
        }

        return mxRow == mnCol ? vector<int>{mxRow} : vector<int>{};
    }
};