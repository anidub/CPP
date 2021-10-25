#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/duplicate-zeros/
 *Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function
Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

https://leetcode.com/problems/duplicate-zeros/discuss/369747/Simple-C%2B%2B-(98.28-100)-inplace
https://leetcode.com/problems/duplicate-zeros/discuss/312743/JavaC%2B%2B-O(n)-or-O(1)
 */

void duplicateZeros(vector<int>& arr) {
	if(arr.size() == 0) return;
	int countZeros = 0; int n = arr.size();
	for(int i = 0; i < arr.size(); i++) {
		countZeros += arr[i] == 0 ? 1 : 0;
	}

	int newLength = n + countZeros - 1;
	cout << newLength << endl;

	for(int i = n-1; i >= 0; i--) {
		if(arr[i] == 0){
			if(newLength < n)
				arr[newLength] = 0;
			newLength--;
			if(newLength < n)
				arr[newLength] = 0;
			newLength--;
		} else {
			if(newLength < n)
				arr[newLength] = arr[i];
			newLength--;
		}
	}
	for(int i : arr)
		cout << i << "-";
}

/*
int main() {
	vector<int> arr;
	arr.push_back(1);arr.push_back(0);arr.push_back(2);arr.push_back(3);arr.push_back(0);
	arr.push_back(4);arr.push_back(5);arr.push_back(0);
	duplicateZeros(arr);

	return 0;
}*/
