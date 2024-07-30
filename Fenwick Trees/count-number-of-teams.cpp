/* 
    Problem
     - Find the number of teams, where a team is a group of 3 soldiers (i, j, k) with i < j < k, and the ratings of the soldiers are strictly decreasing or strictly increasing

    Approaches
     1. Count the smaller soldiers on the left and larger soldiers on the right, as well as the larger soldiers on the left and smaller soldiers on the right for each soldier, then use these counts to calculate the team that can be formed

    Data Structures
     - Fenwick tree
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;

        for (int i = 1; i < rating.size() - 1; i++) {
            int leftSmaller = 0;
            int rightLarger = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    leftSmaller++;
                }
            }
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] > rating[i]) {
                    rightLarger++;
                }
            }

            ans += leftSmaller * rightLarger;

            int leftLarger = i - leftSmaller;
            int rightSmaller = (rating.size() - 1 - i) - rightLarger;

            ans += leftLarger * rightSmaller;
        }

        return ans; 
    }
};

// Solution 1.1

class FenwickTree {
public:
    FenwickTree(int size) { 
        tree.resize(size, 0); 
    }
    FenwickTree(const vector<int>& a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++) {
            tree[i] += a[i];
            int r = i | (i + 1);
            if (r < a.size()) {
                tree[r] += tree[i];
            }
        }
    }
    void update(int i, int delta) {
        while (i < tree.size()) {
            tree[i] += delta;        
            i = i | (i + 1);         
        }
    }
    int query(int i) {
        int sum = 0;
        while (i >= 0) {
            sum += tree[i];         
            i = (i & (i + 1)) - 1; 
        }
        return sum;
    }
    int rangeQuery(int i, int j) {
        return query(j) - query(i - 1);
    }
private:
    vector<int> tree;
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        vector<pair<int, int>> soldiers(n);
        for (int i = 0; i < n; i++) {
            soldiers[i] = {rating[i], i};
        }   

        sort(soldiers.begin(), soldiers.end());
        for (int i = 0; i < n; i++) {
            rating[soldiers[i].second] = i;
        }
        
        FenwickTree leftFt(n);
        FenwickTree rightFt(vector<int>(n, 1));
        
        int ans = 0;

        for (int r : rating) {
            rightFt.update(r, -1);

            int leftSmaller = leftFt.query(r - 1);
            int rightLarger = rightFt.rangeQuery(r, n - 1);

            ans += leftSmaller * rightLarger;

            int leftLarger = r - leftSmaller;
            int rightSmaller = (rating.size() - 1 - r) - rightLarger;

            ans += leftLarger * rightSmaller;

            leftFt.update(r, 1);
        }

        return ans;
    }
};