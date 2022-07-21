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
/*https://www.educative.io/courses/grokking-the-coding-interview/mElknO5OKBO
 * Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.
 */
//TC : O(N^2), SC: O(1)
int countTripletsWithSmallerSum(vector<int> &arr, int target) {
	if(arr.empty()) return 0;
	int count = 0;
	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++) {
		int left = i + 1, right = arr.size() - 1;
		while(left < right) {
			int sum = arr[i] + arr[left] + arr[right];
			if(sum < target) {
				count += (right - left);
				left++;
			} else
				right--;
		}
	}
	return count;
}

void searchTripletsSmallerSumHelper(vector<int> &arr, int targetSum, int first, vector<vector<int>> &triplets);
//TC: O(N^3)
vector<vector<int>> searchTripletsSmallerSum(vector<int> &arr, int target) {
	if(arr.empty()) return {};
	vector<vector<int>> triplets;
	sort(arr.begin(), arr.end());

	for(int i = 0;i < arr.size(); i++) {
		searchTripletsSmallerSumHelper(arr, target - arr[i], i, triplets);
	}
	return triplets;
}

void searchTripletsSmallerSumHelper(vector<int> &arr, int targetSum, int first, vector<vector<int>> &triplets) {
	int left = first + 1, right = arr.size() - 1;
	while(left < right) {
		if(arr[left] + arr[right] < targetSum) {
			for(int i = right; i > left; i--){
				triplets.push_back({arr[first], arr[left], arr[i]});
			}
			left++;
		} else
			right--;
	}
}

/*
int main() {
	  vector<int> vec = {-1, 0, 2, 3};
	  cout << countTripletsWithSmallerSum(vec, 3) << endl;
	  vec = {-1, 4, 2, 1, 3};
	  cout << countTripletsWithSmallerSum(vec, 5) << endl;
}*/
