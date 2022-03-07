#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good. */

//explaination : https://www.youtube.com/watch?v=qvQSvQaY9KI

//O(n)

int numGoodPairs(vector<int>& nums){
	int n = nums.size();
	int total = 0;
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		total += mp[nums[i]];//0 //1 // 3 // 6
		mp[nums[i]]++;//1 // 2 // 3 // 4
	}
	cout << "total:"  << total << endl;
	return total;
}


/*int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(1);nums.push_back(1);nums.push_back(3);
	numGoodPairs(nums);
	return 0;
} */
