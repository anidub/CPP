#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/R8LzZQlj8lO
 * Given a sorted array of numbers, find if a given number ‘key’ is present in the array.
 * Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order.
 *  You should assume that the array can have duplicates.
 *  Input: [1, 2, 3, 4, 5, 6, 7], key = 5
Output: 4
 *
 */
class OrderAgnosticBS{
public:
	//TC:O(LOGN), SC:O(1)
	int search(const vector<int> &arr, int key) {
		if(arr.empty()) return -1;
		int start = 0, end = arr.size() - 1;
		bool isAscending = arr[start] < arr[end];

		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(arr[mid] == key) return mid;

			if(isAscending) {
				if(key < arr[mid])
					end = mid - 1;
				else
					start = mid + 1;
			} else {
				if(key > arr[mid])
					end = mid - 1;
				else
					start = mid + 1;
			}
		}
		return -1;
	}
};

/*
int main(int argc, char* argv[]) {
	OrderAgnosticBS os;
	cout << os.search(vector<int>{4, 6, 10}, 10) << endl;
	cout << os.search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
	cout << os.search(vector<int>{10, 6, 4}, 10) << endl;
	cout << os.search(vector<int>{10, 6, 4}, 4) << endl;
}*/
