#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/qA5wW7R8ox7
 * Given an array of numbers sorted in an ascending order, find the ceiling of a given number ‘key’.
 * The ceiling of the ‘key’ will be the smallest element in the given array greater than or equal to the ‘key’.

Write a function to return the index of the ceiling of the ‘key’. If there isn’t any ceiling return -1.
Input: [1, 3, 8, 10, 15], key = 12
Output: 4
Explanation: The smallest number greater than or equal to '12' is '15' having index '4'.

 */
class CeilingOfANumber {
public:
	//TC: O(LOGN), SC:O(1)
	int searchCeilingOfNumber(const vector<int> &arr, int key) {
		if(arr.empty()) return -1;
		int start = 0, end = arr.size() - 1;

		if(key > arr[end]) return -1;

		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(arr[mid] == key) return mid;
			else if(key > arr[mid])
				start = mid + 1;
			else
				end = mid - 1;
		}
		return start;//now start = end + 1 so the next big number will be arr[start]
	}

	int searchFloorOfNumber(const vector<int> &arr, int key) { //floor means greater or equal to
		int start = 0, end = arr.size() - 1;
		if(key < arr[0]) return 0;

		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(arr[mid] == key) return mid;
			else if(key < arr[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		//now start = end + 1 so the next big number will be arr[end]
		return end;
	}
};
/*
int main(int argc, char* argv[]) {
	CeilingOfANumber cn;
  cout << cn.searchCeilingOfNumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << cn.searchCeilingOfNumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << cn.searchCeilingOfNumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << cn.searchCeilingOfNumber(vector<int>{4, 6, 10}, -1) << endl;
}
*/
