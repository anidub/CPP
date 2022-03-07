#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*O(N3)
https://leetcode.com/problems/count-good-triplets/
Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.
*/


int coutGoodTriplets(vector<int>& arr, int a, int b, int c) {
	if(arr.size() == 0) return 0;
	int n = arr.size();
	int count = 0;

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(abs(arr[i] - arr[j]) > a) continue;
			for(int k = j+1; k < n; k++) {
				if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
					count++;
			}
		}
	}
	cout << count ;
	return count;
}

/*int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(0);
	nums.push_back(1);nums.push_back(1);nums.push_back(9);nums.push_back(7);
	coutGoodTriplets(nums,7,2,3);
	return 0;

}*/
