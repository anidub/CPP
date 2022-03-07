#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
 * https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
Given an array nums of integers, return how many of them contain an even number of digits.
Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
		12 contains 2 digits (even number of digits).
		345 contains 3 digits (odd number of digits).
		2 contains 1 digit (odd number of digits).
		6 contains 1 digit (odd number of digits).
		7896 contains 4 digits (even number of digits).

		*/
int findNumbers(vector<int>& nums){
	int n = nums.size();
	if(n == 0) return 0;
	int counter = 0;
	for(auto i: nums){
		if(to_string(i).length() % 2 == 0)
			counter++;
	}
	cout << counter;
	return counter;
}

int count(int num) {
	int count = 0;
	cout << "num:" << num << endl;
	while(num) {
		count++;
		num = num/10;
	}
	cout << "num:" << num << endl;
	return count;
}

int findNumberDivide(vector<int>& nums) {
	int n = nums.size();
	if(n == 0) return 0;
	int counter = 0;

	for(int i : nums) {
		if(count(i) % 2 == 0)
			counter++;
	}
	cout << counter;
	return counter;
}

/*int main() {
	vector<int> nums;
	nums.push_back(12);nums.push_back(345);
	nums.push_back(2);nums.push_back(6);nums.push_back(7896);
	findNumberDivide(nums);

	return 0;
} */
