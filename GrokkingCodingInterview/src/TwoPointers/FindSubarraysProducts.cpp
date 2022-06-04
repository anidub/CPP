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
/*https://www.educative.io/courses/grokking-the-coding-interview/RMV1GV1yPYz
 * Given an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.
 Input: [2, 5, 3, 10], target=30
Output: [2], [5], [2, 5], [3], [5, 3], [10]
Explanation: There are six contiguous subarrays whose product is less than the target.
 */
//TC:O(N^3), SC: O(1)
vector<vector<int>> findSubarraysProducts(const vector<int>& arr, int target) {
	if(arr.empty()) return {};
	int product = 1, left = 0;
	vector<vector<int>> result;

	for(int right = 0; right < arr.size(); right++) {
		product *= arr[right];
		while(product >= target && left < arr.size()) {
			product /= arr[left++];
		}

		vector<int> temp;
		for(int i = right; i >= left; i--) {
			temp.push_back(arr[i]);
			result.push_back(temp);
		}
	}
	return result;
}
/*
int main() {
	  auto result = findSubarraysProducts(vector<int>{2, 5, 3, 10}, 30);
	  for (auto vec : result) {
	    cout << "[";
	    for (auto num : vec) {
	      cout << num << " ";
	    }
	    cout << "]";
	  }
	  cout << endl;

	  result = findSubarraysProducts(vector<int>{8, 2, 6, 5}, 50);
	  for (auto vec : result) {
	    cout << "[";
	    for (auto num : vec) {
	      cout << num << " ";
	    }
	    cout << "]";
	  }
}*/
