#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/height-checker/
Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.

Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students remain on their seats.

Example 1:
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
Current array : [1,1,4,2,1,3]
Target array  : [1,1,1,2,3,4]
On index 2 (0-based) we have 4 vs 1 so we have to move this student.
On index 4 (0-based) we have 1 vs 3 so we have to move this student.
On index 5 (0-based) we have 3 vs 4 so we have to move this student.

soln : https://leetcode.com/problems/height-checker/discuss/687737/C%2B%2B-O(n)

Other easy solution: sort array and compare with original..if mismatch, increment result by 1;
https://leetcode.com/problems/height-checker/discuss/721867/C%2B%2B
*/

int heightChecker(vector<int>& heights) {
	if(heights.size() == 0) return 0;

	vector<int> count(101); //101 since its the same given in question
	for(int height : heights)
		count[height]++;

	int cur = 0;
	int result = 0;
	for(int i = 0; i < heights.size(); i++) {
		while(count[cur] == 0)
			cur++;
		if(cur != heights[i])
			result++;
		count[cur]--;
	}
	cout << result;
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(1);nums.push_back(4);nums.push_back(2);nums.push_back(1);nums.push_back(3);
	heightChecker(nums);

	return 0;
}
*/
