/* 
    Problem
     - Sort an integer array

    Approaches
     1. Place the pivot in the last position, swap elements less than the pivot with those greater than the pivot, swap the pivot with the leftmost greater element, and repeat recursively in each partition
      a. Consider that each pivot will be in the correct position after the swap around it

    Data Structures
     - Array
    Algorithms
     - Quick sort

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
private: 
    int medianOfThree(vector<int>& arr, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[lo] > arr[mid]) {
            swap(arr[lo], arr[mid]);
        }
        if (arr[lo] > arr[hi]) {
            swap(arr[lo], arr[hi]);
        }
        if (arr[mid] > arr[hi]) {
            swap(arr[mid], arr[hi]);
        }

        return mid;
    }
    int partition(vector<int>& arr, int lo, int hi) {
        int pivotIdx = medianOfThree(arr, lo, hi);
        int pivot = arr[pivotIdx];
        swap(arr[pivotIdx], arr[hi]); 
        
        int i = lo - 1;
        for (int j = lo; j < hi; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[hi]);

        return i + 1; 
    }
    void quickSort(vector<int>& arr, int lo, int hi) {
        if (lo < hi) {
            int pi = partition(arr, lo, hi);

            quickSort(arr, lo, pi - 1);
            quickSort(arr, pi + 1, hi);
        }
    }
};