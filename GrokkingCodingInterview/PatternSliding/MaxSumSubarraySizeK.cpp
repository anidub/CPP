#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/JPKr0kqLGNP
 *Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
 */
//TC: O(N)
int findMaxSumSubArray(int k, const vector<int>& arr) {//[2,1,5,1,3,2]
    int maxSum = 0;
    int curSum  = 0; int start = 0;
    for(int i = 0; i < arr.size(); i++) {
        curSum += arr[i];
        if(i >= k - 1) {
            maxSum = max(maxSum, curSum);
            curSum -= arr[start];
            start++;
        }
    }
    return maxSum;
}
/*
int main() {
	cout << findMaxSumSubArray(3, {2, 1, 5, 1, 3 ,2}) << endl;
}*/
