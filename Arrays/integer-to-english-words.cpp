/* 
    Problem
     - Find the English word representation of a non-negative integer

    Approaches
     1. Convert the integer to words in groups of 1000, starting with the hundreds, tens, and ones places, and then the thousands place for each group
      a. Consider 0
      b. Consider multiples of 1000

    Data Structures
     - Array
    Algorithms

    Time Complexity
     - O(log(n)) -> n = number, k = average length of each word
    Space Complexity
     - O(log(n)•k) 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> ones = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        vector<string> tens = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        vector<string> thousands = {"", "Thousand ", "Million ", "Billion "};

        string ans;
        int grpCnt = 0; 

        while (num > 0) {
            int group = num % 1000;
            if (group > 0) {
                string res;

                if (group >= 100) {
                    res += ones[group / 100] + "Hundred ";
                    group %= 100;
                }
                if (group >= 20) {
                    res += tens[group / 10];
                    group %= 10;
                }
                if (group > 0) {
                    res += ones[group];
                }

                res += thousands[grpCnt];

                ans = res + ans;
            }
            num /= 1000;
            grpCnt++;
        }

        ans.pop_back();
        return ans;
    }
};