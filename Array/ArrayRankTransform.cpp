#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;

/*
 * https://leetcode.com/problems/rank-transform-of-an-array/
 *Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.

Example 1:
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

 https://leetcode.com/problems/rank-transform-of-an-array/discuss/522049/C%2B%2B-Hashing%3A-Memory-Efficient-greater-100
 https://leetcode.com/problems/rank-transform-of-an-array/discuss/700776/C%2B%2B-and-Python-solutions
 */

vector<int> arrayRankTransform(vector<int>& arr) {
	if(arr.size() == 0) return arr;

	set<int> arrSet(arr.begin(), arr.end());
	int position = 1;
	unordered_map<int, int> map;

	for(int i : arrSet) {
		map[i] = position;
		position++;
	}

	for(auto& num : arr) {
		num = map[num];
	}
	return arr;
}

vector<int> arrayRankTransformSort(vector<int>& arr) {
	if(arr.size() == 0) return arr;

	vector<int> nums = arr;
	sort(nums.begin(), nums.end());
	unordered_map<int, int> map;

	for(int i = 0; i < nums.size(); i++) {
		if(!map.count(nums[i])) {
			map[nums[i]] = map.size() + 1;
		}
	}

	for(int i = 0; i < arr.size(); i++) {
		arr[i] = map[arr[i]];
	}
	return arr;
}
/*

int main() {
	vector<int> prices;
	prices.push_back(40);prices.push_back(10);prices.push_back(20);prices.push_back(30);

	arrayRankTransform(prices);
	return 0;
}*/
