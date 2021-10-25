#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <queue>

using namespace std;
/*
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76607/C%2B%2B-O(nlogn)-Time-O(n)-Space-MergeSort-Solution-with-Detail-Explanation :: comments
https://www.geeksforgeeks.org/counting-inversions/ : for understanding inversions
another solution using treees : https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/648902/C%2B%2B-or-Insert-into-BST-or-Easy-to-understand-16ms-Beats-97
 similar problems for this approach : https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/138154/The-C%2B%2B-merge-sort-template-for-pairs-'i'-'j'-problem
 */


//Time: O(n log n) Space: O(n)
vector<int> sol;
void merge(vector<pair<int, int>>& idx, int start, int mid, int end) {
	int i = start, j = mid+1;
	while(i <= mid && j <= end) {
		if(idx[i].first <= idx[j].first) {
			sol[idx[i].second] += (j-mid-1);
			i++;
		} else {
			j++;
		}
	}
	while(i <= mid) {
		sol[idx[i].second] += (j-mid-1);
		i++;
	}
	sort(idx.begin() + start, idx.begin() + end + 1);
}

void mergeSort(vector<pair<int, int>>& idx, int start, int end) {
	if(start >= end) return;
	int mid = start + (end- start)/2;
	mergeSort(idx, start, mid);
	mergeSort(idx, mid+1, end);
	merge(idx, start, mid, end);
}

vector<int> countSmallerAfterSelf(vector<int>& nums) {
	int n = nums.size();
	sol.resize(n, 0);
	vector<pair<int, int>> idx;
	for(int i = 0; i < n; i++)
		idx.push_back({nums[i], i});
	mergeSort(idx, 0, n-1);
	return sol;
}
/*
int main() {
	vector<int> input;
	input.push_back(5);input.push_back(2);input.push_back(6);input.push_back(1);
	countSmallerAfterSelf(input);
	return 0;
}*/
