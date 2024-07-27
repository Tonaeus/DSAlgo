/* 
    Problem 
     - Sort an array into 3 partitions

    Approaches
     1. Swap the current element with the element to the right of the left partition or to the left of the right partition if it does not belong to the middle partition

    Data Structures
     - Array
    Algorithms
     - Dutch flag

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
