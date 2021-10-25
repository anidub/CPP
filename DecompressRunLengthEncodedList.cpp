#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*https://leetcode.com/problems/decompress-run-length-encoded-list/
Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].
Input: nums = [1,1,2,3]
Output: [1,3,3]
*/


vector<int> decompressRLElist(vector<int>& input) {
	vector<int> result;
	if(input.size() == 0)
		return result;

	for(size_t i = 0; i < input.size(); i+=2) {
		int freq = input[i];
		while(freq > 0) {
			result.push_back(input[i+1]);
			freq--;
		}
	}
	for(int i : result)
		cout << i << " ";

	return result;
}

/* this ALSO works. using insert api
 * insert api : insert(where, n, which) : end. how many times, what to insert
 vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> res;
    for (int i=0; i<nums.size(); i+=2)
        res.insert(res.end(), nums[i], nums[i+1]);
    return res;
} */
/*
int main() {

	vector<int> nums;
	nums.push_back(1);nums.push_back(2);
	nums.push_back(3);nums.push_back(4);
	decompressRLElist(nums);
	return 0;
}
*/
