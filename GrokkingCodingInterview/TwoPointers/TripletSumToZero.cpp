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
/*https://www.educative.io/courses/grokking-the-coding-interview/gxk639mrr5r
 * Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
 * Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
 */
void searchPairs(vector<int> &arr, int targetSum, int left, vector<vector<int>> &triplets);
//TC: O(N^2), SC: O(N)
vector<vector<int>> searchTriplets(vector<int> &arr) {
	if(arr.empty()) return {};
	sort(arr.begin(), arr.end());
	vector<vector<int>> triplets;

	for(int i = 0; i < arr.size() - 2; i++) {
		if(i > 0 && arr[i] == arr[i-1]) continue;
		searchPairs(arr, -arr[i], i+1, triplets);
	}
	return triplets;
}

void searchPairs(vector<int> &arr, int targetSum, int left, vector<vector<int>> &triplets) {
	int right = arr.size() - 1;
    while (left < right) {
    	int currentSum = arr[left] + arr[right];
    	if (currentSum == targetSum) { // found the pair
    		triplets.push_back({-targetSum, arr[left], arr[right]});
    		left++;
    		right--;
    		while (left < right && arr[left] == arr[left - 1]) {
    			left++; // skip same element to avoid duplicate triplets
    		}
    		while (left < right && arr[right] == arr[right + 1]) {
    			right--; // skip same element to avoid duplicate triplets
    		}
    	} else if (targetSum > currentSum) {
    		left++; // we need a pair with a bigger sum
    	} else {
    		right--; // we need a pair with a smaller sum
    	}
    }
}

/*
int main() {
	  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
	  auto result = searchTriplets(vec);
	  for (auto vec : result) {
	    cout << "[";
	    for (auto num : vec) {
	      cout << num << " ";
	    }
	    cout << "]";
	  }
	  cout << endl;

	  vec = {-5, 2, -1, -2, 3};
	  result = searchTriplets(vec);
	  for (auto vec : result) {
	    cout << "[";
	    for (auto num : vec) {
	      cout << num << " ";
	    }
	    cout << "]";
	  }

	return 0;
}*/
