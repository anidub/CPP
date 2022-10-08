#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/B1ZW38kXJB2
 * Given an infinite sorted array (or an array with unknown size), find if a given number
 * ‘key’ is present in the array. Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.
 * Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
Output: 6
Explanation: The key is present at index '6' in the array.
 */

class ArrayReader {
public:
	vector<int> arr;
	ArrayReader(const vector<int> &arr) {
		this->arr = arr;
	}
	virtual int get(int index) {
		if(index >= arr.size()) {
			return numeric_limits<int>::max();
		}
		return arr[index];
	}
};

class SearchInfiniteSortedArray {
public:
	//TC:O(LOGN), SC:O(1)
	int search(ArrayReader *reader, int key) {
		int start = 0, end = 1;
		while(key > reader->get(end)) {
			int newStart = end + 1;
			end += (end - start + 1) * 2;
			start = newStart;
		}
		return binarySearch(reader, key, start, end);
	}

	int binarySearch(ArrayReader *reader, int key, int start, int end) {
		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(key > reader->get(mid))
				start = mid + 1;
			else if(key < reader->get(mid))
				end = mid - 1;
			else
				return mid;
		}
		return -1;
	}
};

/*
int main(int argc, char *argv[]) {
	SearchInfiniteSortedArray sira;
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << sira.search(reader, 16) << endl;
  cout << sira.search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << sira.search(reader, 15) << endl;
  cout << sira.search(reader, 200) << endl;
  delete reader;
}*/

