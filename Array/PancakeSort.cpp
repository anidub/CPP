#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/pancake-sorting/
 * Given an array of integers arr, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 1 <= k <= arr.length.
Reverse the sub-array arr[0...k-1] (0-indexed).
For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
Example 1:
Input: arr = [3,2,4,1]
Output: [4,2,4,3]
Explanation:
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: arr = [3, 2, 4, 1]
After 1st flip (k = 4): arr = [1, 4, 2, 3]
After 2nd flip (k = 2): arr = [4, 1, 2, 3]
After 3rd flip (k = 4): arr = [3, 2, 1, 4]
After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted

https://leetcode.com/problems/pancake-sorting/discuss/214213/JavaC%2B%2BPython-Straight-Forward
Time Complexity:
O(N^2)
 */

void print(vector<int>& v) {
    cout << "----" << endl;
    for(int i : v)
        cout << i << " ";
    cout << endl;
}

vector<int> pancakeSort(vector<int>& A) {
	if(A.size() == 0) return {};
	int maxnum = INT_MIN;
	int maxindex = -1;
	vector<int> result;
	int size = A.size();

	while(size > 2) {
		maxindex=-1, maxnum=INT_MIN;
		for(int i = 0; i < size; i++) {
			if(A[i] > maxnum) {
				maxnum = A[i];
				maxindex = i;
			}
		}
        cout << "maxindex:" << maxindex << endl;
		result.push_back(maxindex+1);
		result.push_back(size);
		reverse(A.begin(), A.begin() + maxindex+1);
		print(A);
		reverse(A.begin(), A.begin() + size);
		print(A);
		size--;
	}

	if(size == 2 && A[0] > A[1])
		result.push_back(2);
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(2);nums.push_back(4);nums.push_back(1);
	pancakeSort(nums);
	return 0;
}*/
