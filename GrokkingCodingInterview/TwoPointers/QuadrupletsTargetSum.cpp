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
/*https://www.educative.io/courses/grokking-the-coding-interview/gxDOJJ7xAJl
 * Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.
 * Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
 */
void searchQuadrupletsTargetPairHelper(vector<int> &arr, int first, int second, int target, vector<vector<int>> &quadruplets);

//TC: O(N^3)
vector<vector<int>> searchQuadrupletsTargetSum(vector<int> &arr, int target) {
	if(arr.empty()) return {};
	vector<vector<int>> quadruplets;
	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size() - 3; i++) {
		if(i > 0 && arr[i] == arr[i-1]) continue;

		for(int j = i + 1; j < arr.size() - 2; j++) {
			if(j > i + 1 && arr[j] == arr[j - 1]) continue;
			searchQuadrupletsTargetPairHelper(arr, i, j, target, quadruplets);
		}
	}
	return quadruplets;
}

void searchQuadrupletsTargetPairHelper(vector<int> &arr, int first, int second, int target, vector<vector<int>> &quadruplets) {
	int left = second + 1, right = arr.size() - 1;

	while(left < right) {
		int sum = arr[left] + arr[right] + arr[first] + arr[second];
		if(sum == target) {
			quadruplets.push_back({arr[left] , arr[right] , arr[first] , arr[second]});
			left++;
			right--;
			while(left < right && arr[left] == arr[left - 1]) left++;
			while(left < right && arr[right] == arr[right + 1]) right--;
		} else if(sum < target) left++;
		else right--;
	}
}

/*
int main() {
	  vector<int> vec = {4, 1, 2, -1, 1, -3};
	  auto result = searchQuadrupletsTargetSum(vec, 1);
	  for (auto vec : result) {
	    cout << "[";
	    for (auto num : vec) {
	      cout << num << " ";
	    }
	    cout << "]";
	  }
	  cout << endl;

	  vec = {2, 0, -1, 1, -2, 2};
	  result = searchQuadrupletsTargetSum(vec, 2);
	  for (auto vec : result) {
	    cout << "[";
	    for (auto num : vec) {
	      cout << num << " ";
	    }
	    cout << "]";
	  }
}*/
