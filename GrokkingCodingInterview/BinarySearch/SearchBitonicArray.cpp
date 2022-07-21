#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/mEGORlpZYJE
 * Given a Bitonic array, find if a given ‘key’ is present in it. An array is considered bitonic
 *  if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or
 *   decreasing means that for any index i in the array arr[i] != arr[i+1].

Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1.
Input: [1, 3, 8, 4, 3], key=4
Output: 3
 */
class SearchBitonicArray {
 public:
	//TC: LOGN , SC: O(1)
  int search(const vector<int> &arr, int key) {
	 if(arr.empty()) return -1;
	 int maxIndex = findMaxIndex(arr);

	 int keyIndex = binarySearchIndex(arr, key, 0, maxIndex);
	 if(keyIndex != -1)
		 return keyIndex;
    return binarySearchIndex(arr, key, maxIndex + 1, arr.size() - 1);
  }

  // find index of the maximum value in a bitonic array
  int findMaxIndex(const vector<int> &arr) {
	  int start = 0, end = arr.size() - 1;
	  while(start < end) {
		  int mid = start + (end - start) / 2;
		  if(arr[mid] > arr[mid + 1])
			  end = mid - 1;
		  else
			  start = mid + 1;
	  }

	  return end; // at the end of the while loop, 'start == end'
  }
private:
  // order-agnostic binary search
  int binarySearchIndex(const vector<int> &arr, int key, int start, int end) {
	  while(start <= end) {
		  int mid = start + (end - start) / 2;

		  if(key == arr[mid])
			  return mid;

		  if(arr[start] < arr[end]) { // descending order
			  if(key > arr[mid])
				  start = mid + 1;
			  else
				  end =  mid - 1;
		  } else {// descending order
			  if(key > arr[mid])
				  end = mid - 1;
			  else
				  start = mid + 1;
		  }
	  }
	  return -1;// element is not found */
  }
};

/*
int main(int argc, char *argv[]) {
	SearchBitonicArray sba;
  cout << sba.search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << sba.search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << sba.search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << sba.search(vector<int>{10, 9, 8}, 10) << endl;
}

*/
