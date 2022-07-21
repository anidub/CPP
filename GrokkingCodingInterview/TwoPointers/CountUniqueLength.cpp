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
/*https://www.educative.io/courses/grokking-the-coding-interview/mEEA22L5mNA
 * Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the length of the subarray that has no duplicate in it.
 Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
 */
//TC: O(N), SC: O(1)
int countUniqueLength(vector<int> &arr) {
	if(arr.empty()) return 0;
	int result = 0;
	int right = 1;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] != arr[right]) {
			result++;
		}
		right++;
	}
	return result;
}
/*
 *  Given an unsorted array of numbers and a target ‘key’, remove all instances of ‘key’ in-place and return the new length of the array.
 */
//TC: O(N), SC: O(1)
int countLengthUnsortedNonKey(vector<int> &arr, int key) {
	if(arr.empty()) return 0;
	int nextElement = 0;
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] != key) {
			arr[nextElement] = arr[i];
			nextElement++;
		}
	}
	return nextElement;
}

/*
int main() {
	  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
	  cout << "Array new length: " << countUniqueLength(arr) << endl;

	  arr = vector<int>{2, 2, 2, 11};
	  cout << "Array new length: " << countUniqueLength(arr) << endl;

	return 0;
}*/
