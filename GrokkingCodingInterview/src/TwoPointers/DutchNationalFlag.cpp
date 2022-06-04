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

/*https://www.educative.io/courses/grokking-the-coding-interview/RMBxV6jz6Q0
 * Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.
 */

void swap(vector<int> &arr, int t1, int t2);
//TC: O(N), SC: O(1)
void dutchNationalFlag(vector<int> &arr) {
	int low = 0, high = arr.size() - 1;

	for(int i = 0; i <= high;) {
		if(arr[i] == 0) {
			swap(arr, i, low);
			i++;
			low++;
		} else if(arr[i] == 1)
			i++;
		else {
			swap(arr, i, high);
			high--;
		}
	}
}

void swap(vector<int> &arr, int t1, int t2) {
	int temp = arr[t1];
	arr[t1] = arr[t2];
	arr[t2] = temp;
}
/*
int main() {
	  vector<int> arr = {1, 0, 2, 1, 0};
	  dutchNationalFlag(arr);
	  for (auto num : arr) {
	    cout << num << " ";
	  }
	  cout << endl;

	  arr = vector<int>{2, 2, 0, 1, 2, 0};
	  dutchNationalFlag(arr);
	  for (auto num : arr) {
	    cout << num << " ";
	  }
}*/
