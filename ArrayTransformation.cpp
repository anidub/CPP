#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://blog.csdn.net/qq_21201267/article/details/107097416
 * LeetCode 1243. Array Transformation
 * iven an initial array arr, every day you produce a new array using the array of the previous day.
On the i-th day, you do the following operations on the array of day i-1 to produce the array of day i:
If an element is smaller than both its left neighbor and its right neighbor, then this element is incremented.
If an element is bigger than both its left neighbor and its right neighbor, then this element is decremented.
The first and last elements never change.
After some days, the array does not change. Return that final array.
Example 1:
Input: arr = [6,2,3,4]
Output: [6,3,3,4]
Explanation:
On the first day, the array is changed from [6,2,3,4] to [6,3,3,4].
No more operations can be done to this array.
Example 2:
Input: arr = [1,6,3,4,3,5]
Output: [1,4,4,4,4,5]
Explanation:
On the first day, the array is changed from [1,6,3,4,3,5] to [1,5,4,3,4,5].
On the second day, the array is changed from [1,5,4,3,4,5] to [1,4,4,4,4,5].
No more operations can be done to this array.

IMP
https://www.acwing.com/solution/LeetCode/content/5792/

algorithm
(Violent simulation) O ( 100n2)O(100n2)
Violent simulation as described in the title until the array no longer changes.
time complexity
Each number change at most 100times, a total ofnn Numbers, each iteration requires O ( n )O(n) time.
So the time complexity is O ( 100n2)O(100n2).
Space complexity
need O ( n )O(n) The space is used as an auxiliary array.
*/
vector<int> transformArray(vector<int>& arr) {
	vector<int> temp(arr);
	int n = arr.size();

	while(true) {
		for(int i = 1; i < n-1; i++) {
			if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
				temp[i]--;
			else if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
				temp[i]++;
		}
		if(temp == arr)
			break;
		arr = temp;
	}
	for(int i : arr)
		cout << i << " ";
	return arr;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(6);nums.push_back(3);
	nums.push_back(4);nums.push_back(3);nums.push_back(5);
	transformArray(nums);
}*/
