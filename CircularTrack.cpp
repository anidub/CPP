#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
 * Given an integer n and an integer array rounds. We have a circular track which consists of n sectors labeled from 1 to n. A marathon will be held on this track, the marathon consists of m rounds. The ith round starts at sector rounds[i - 1] and ends at sector rounds[i]. For example, round 1 starts at sector rounds[0] and ends at sector rounds[1]

Return an array of the most visited sectors sorted in ascending order.
Input: n = 4, rounds = [1,3,1,2]
Output: [1,2]
Explanation: The marathon starts at sector 1. The order of the visited sectors is as follows:
1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 (end of round 3 and the marathon)
We can see that both sectors 1 and 2 are visited twice and they are the most visited sectors. Sectors 3 and 4 are visited only once.
https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/807526/C%2B%2B-Solution-Explained-First-and-Last-Element
https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/807014/C%2B%2B-O(n)
https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/806814/JavaC%2B%2BPython-From-Start-to-End
 *
 */

vector<int> mostVisited(int n, vector<int>& rounds) {
	vector<int> result;
	int size = rounds.size();

	if(rounds[0] <= rounds[size - 1]){
		for(int i = rounds[0]; i <= rounds[size - 1]; i++)
			result.push_back(i);
	} else {
		for(int i = 1; i <= rounds[size - 1]; i++) {
			result.push_back(i);
		}
		for(int i = rounds[0];i <= n; i++) {
			result.push_back(i);
		}
	}
	return result;
}

/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(3);nums.push_back(1);nums.push_back(2);
	mostVisited(4, nums);
	return 0;
}
*/
