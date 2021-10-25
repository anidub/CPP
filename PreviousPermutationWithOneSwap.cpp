#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/previous-permutation-with-one-swap/
 * Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap (A swap exchanges the positions of two numbers arr[i] and arr[j]). If it cannot be done, then return the same array.
Example 1:
Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.
Example 2:

Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.
https://www.youtube.com/watch?v=x_y3nIsbENM
https://leetcode.com/problems/previous-permutation-with-one-swap/discuss/573616/C%2B%2B-Simple-approach
 */

void swapValues(vector<int>& arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
vector<int> prevPermutationOneSwap(vector<int>& arr) {
	if(arr.empty() || arr.size() < 2) return arr;
	int transitPoint = -1;
	for(int i = arr.size() - 1; i > 0 ; i--) {
		if(arr[i-1] > arr[i]) {
			transitPoint = i-1;
			break;
		}
	}

    if(transitPoint == -1) return arr;
    int maxPos = transitPoint + 1;

    for(int i = transitPoint + 1; i < arr.size(); i++) {
        if(arr[i] >= arr[transitPoint])
            break;
        if(arr[i] > arr[maxPos])
            maxPos = i;
    }
    swapValues(arr, maxPos, transitPoint);
    return arr;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(9);nums.push_back(4);nums.push_back(6);nums.push_back(7);
	prevPermutationOneSwap(nums);

	return 0;
}
*/
