#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*https://blog.csdn.net/MrJustin/article/details/106324914
 * https://blog.csdn.net/qq_46105170/article/details/106355054
 * LeetCode 1426 Counting Elements
 * Given an integer array arr, count element x such that x + 1 is also in arr.
If there’re duplicates in arr, count them seperately.
Example 1:
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.

 */

int countElements(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	unordered_map<int, int> map;
	int result = 0;

	for(int i : nums) {
		map[i]++;
	}

	for(int i : nums) {
		if(map.count(i+1))
			result++;
	}

	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(2);nums.push_back(1);nums.push_back(3);
	nums.push_back(5);nums.push_back(0);

	cout << countElements(nums) << endl;
	return 0;
}*/
