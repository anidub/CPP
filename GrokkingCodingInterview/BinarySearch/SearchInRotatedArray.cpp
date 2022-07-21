#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/N8XZQ1q1O46
 * Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.
Input: [10, 15, 1, 3, 8], key = 15
Output: 1
Explanation: '15' is present in the array at index '1'.
https://www.educative.io/courses/grokking-the-coding-interview/RMPVM2Y4PW0
 */
class SearchRotatedArray {
public:
	//TC:O(LOGN), SC:O(1)
	int search(const vector<int>& arr, int key) {
		int start = 0, end = arr.size() - 1;

		while(start <= end) {
			int mid = start + (end - start) / 2;

			if(key == arr[mid])
				return mid;

			if(arr[start] <= arr[mid]) { // left side is sorted in ascending order
				if(key < arr[mid] && key >= arr[start])
					end = mid - 1;
				else// key > arr[mid]
					start = mid + 1;
			} else { // right side is sorted in ascending order
				if(key > arr[mid] && key <= arr[end])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}

	//https://www.educative.io/courses/grokking-the-coding-interview/RMPVM2Y4PW0
//with duplicates, same as above except two lines with all are same. mentioned below
	int searchWithDuplicates(const vector<int>& arr, int key) {
		int start = 0, end = arr.size() - 1;

		while(start <= end) {
			int mid = start + (end - start) / 2;

			if(key == arr[mid])
				return mid;

			 // the only difference from the previous solution,
		      // if numbers at indexes start, mid, and end are same, we can't choose a side
		      // the best we can do, is to skip one number from both ends as key != arr[mid]
			if( (arr[start] == arr[mid]) && (arr[mid] == arr[end])) {
				start++;
				end--;
			}
			else if(arr[start] <= arr[mid]) { // left side is sorted in ascending order
				if(key < arr[mid] && key >= arr[start])
					end = mid - 1;
				else// key > arr[mid]
					start = mid + 1;
			} else { // right side is sorted in ascending order
				if(key > arr[mid] && key <= arr[end])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}
};
/*
int main(int argc, char* argv[]) {
	SearchRotatedArray sra;
  cout << sra.search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << sra.search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}*/
