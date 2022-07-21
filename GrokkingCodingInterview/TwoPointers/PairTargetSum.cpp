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
/*https://www.educative.io/courses/grokking-the-coding-interview/xog6q15W9GP
 * Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.
 */
//TC: O(N), SC: O(1)
pair<int, int> pairTargetSumSearch(const vector<int>& arr, int targetSum) {
	if(arr.empty()) return {};
	int left = 0, right = arr.size() - 1;

	while(left <= right) {
		int sum = arr[left] + arr[right];
		if(sum == targetSum) return make_pair(left, right);
		else if(sum < targetSum)
			left++;
		else
			right--;
	}
	return make_pair(-1, -1);
}

pair<int, int> pairTargetSumSearchMap(const vector<int>& arr, int targetSum) {
    unordered_map<int, int> nums;  // to store number and its index
    for (int i = 0; i < arr.size(); i++) {
      if (nums.find(targetSum - arr[i]) != nums.end()) {
        return make_pair(nums[targetSum - arr[i]], i);
      } else {
        nums[arr[i]] = i;  // put the number and its index in the map
      }
    }
    return make_pair(-1, -1);  // pair not found
  }

/*
int main(int argc, char *argv[]) {
  auto result = pairTargetSumSearch(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = pairTargetSumSearch(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}*/
