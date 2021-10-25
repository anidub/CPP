#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>

using namespace std;
/*
 * https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
 * We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with speed 1 unit per second. Some of the ants move to the left, the other move to the right.
When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions doesn't take any additional time.
When an ant reaches one end of the plank at a time t, it falls out of the plank imediately.
Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right. Return the moment when the last ant(s) fall out of the plank.
Input: n = 4, left = [4,3], right = [0,1]
Output: 4
Explanation: In the image above:
-The ant at index 0 is named A and going to the right.
-The ant at index 1 is named B and going to the right.
-The ant at index 3 is named C and going to the left.
-The ant at index 4 is named D and going to the left.
Note that the last moment when an ant was on the plank is t = 4 second, after that it falls imediately out of the plank. (i.e. We can say that at t = 4.0000000001, there is no ants on the plank).

 https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/discuss/720189/JavaC%2B%2BPython-Ants-Keep-Walking-O(N)
 Explanation
For ants in direction of left, the leaving time is left[i]
For ants in direction of right, the leaving time is n - right[i]
 */

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
	if(left.empty() && right.empty()) return 0;
	int result = 0;
	for(int i : left)
		result = max(result, i);
	for(int j : right)
		result = max(result, n - j);

	return result;
}
/*
int main() {
	vector<int> left;
	left.push_back(4);left.push_back(3);
	vector<int> right;
	right.push_back(0);right.push_back(1);
	cout << getLastMoment(4, left, right) << endl;

	return 0;
}
*/
