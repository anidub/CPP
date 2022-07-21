#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/7nPmB8mZ6vj
 * Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

 * Input: [10, 15, 1, 3, 8]
Output: 2
Explanation: The array has been rotated 2 times.

 *
 */
class RotationCountOfRotatedArray {
public:
	//TC:O(LOGN), SC:O(1)
	int countRotations(const vector<int>& arr) {
		int start = 0, end = arr.size() - 1;

		while(start < end) {
			int mid = start + (end - start) / 2;

			if(mid < end && arr[mid] > arr[mid + 1]) // if mid is greater than the next element
				return mid + 1;

			if(mid > start && arr[mid - 1] > arr[mid])// if mid is smaller than the previous element
				return mid;

			if(arr[start] < arr[mid])// left side is sorted, so the pivot is on right side
				start = mid + 1;
			else // right side is sorted, so the pivot is on the left side
				end = mid - 1;
		}
		return 0;// the array has not been rotated
	}


//https://www.educative.io/courses/grokking-the-coding-interview/R1v4P0R7VZw
	int countRotationsWithDuplicates(const vector<int>& arr) {
		int start = 0, end = arr.size() - 1;

		while(start < end) {
			int mid = start  + (end - start) / 2;

			if(mid < end && arr[mid] > arr[mid + 1])
				return mid + 1;

			if(mid > start && arr[mid - 1] > arr[mid])
				return mid;

			 //if numbers at indices start, mid, and end are same, we can't choose a side
			 // the best we can do is to skip one number from both ends if they are not the smallest number
			if(arr[start] == arr[mid] && arr[mid] == arr[end]) {
				if(arr[start] > arr[start + 1]) {// if element at start+1 is not the smallest
					return start + 1;
				}
				start++;
				if(arr[end - 1] > arr[end]) {// if the element at end is not the smallest
					return end;
				}
				end--;
				// left side is sorted, so the pivot is on right side
			} else if( arr[start] < arr[mid] || (arr[start] == arr[end] && arr[mid] > arr[end]) )
				start = mid + 1;
			else// right side is sorted, so the pivot is on the left side
				end = mid - 1;
		}
		return 0;
	}
};
/*
int main(int argc, char* argv[]) {
	RotationCountOfRotatedArray rcra;
  cout << rcra.countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << rcra.countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << rcra.countRotations(vector<int>{1, 3, 8, 10}) << endl;

  cout << rcra.countRotationsWithDuplicates(vector<int>{3, 3, 7, 3}) << endl;
}
*/
