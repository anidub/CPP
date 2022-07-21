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
/*https://www.educative.io/courses/grokking-the-coding-interview/3jY0GKpPDxr
 * We are given an array containing positive and negative numbers. Suppose the array contains a number ‘M’ at a particular index. Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is negative move backwards ‘M’ indices. You should assume that the array is circular which means two things:

If, while moving forward, we reach the end of the array, we will jump to the first element to continue the movement.
If, while moving backward, we reach the beginning of the array, we will jump to the last element to continue the movement.
Write a method to determine if the array has a cycle. The cycle should have more than one element and should follow one direction which means the cycle should not contain both forward and backward movements.
Input: [1, 2, -1, 2, 2]
Output: true
Explanation: The array has a cycle among indices: 0 -> 1 -> 3 -> 0

https://leetcode.com/problems/circular-array-loop/
 */
int findNextIndex(const vector<int> &arr, bool forward, int currentIndex);

//TC:O(N^2), SC: O(1)
bool loopExists(const vector<int> &arr) {
	int n = arr.size();
	if(arr.empty()) return false;

	for(int i = 0; i < n; i++) {
		bool isForward = arr[i] >= 0;
		int slow = i;
		int fast = i;

		do{
	        slow = findNextIndex(arr, isForward, slow);  // move one step for slow pointer
	        fast = findNextIndex(arr, isForward, fast);  // move one step for fast pointer
			if(fast != -1)
				fast = findNextIndex(arr, isForward, fast);  // move one step for fast pointer
		} while(slow != -1 && fast != -1 && slow != fast);

		if(slow != -1 && slow == fast)
			return true;
	}
	return false;
}

int findNextIndex(const vector<int> &arr, bool forward, int currentIndex) {
	int direction = arr[currentIndex] >= 0;
	if(direction != forward) return -1;
	int n = arr.size();

	int nextIndex = (currentIndex + arr[currentIndex]) % n;
	if(nextIndex < 0) nextIndex += n;

	if(nextIndex == currentIndex)
		nextIndex = -1;
	return nextIndex;
}
/*
int main(int argc, char *argv[]) {
  cout << loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
  cout << loopExists(vector<int>{2, 2, -1, 2}) << endl;
  cout << loopExists(vector<int>{2, 1, -1, -2}) << endl;
}
*/
