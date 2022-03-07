#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/number-of-equivalent-domino-pairs/
 *Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.
Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

https://leetcode.com/problems/number-of-equivalent-domino-pairs/discuss/340022/JavaC%2B%2BPython-Easy-and-Concise
 */
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
	if(dominoes.empty()) return 0;
	unordered_map<int, int> count;
	int res = 0;
	for (auto& d : dominoes) {
		int k = min(d[0], d[1]) * 10 + max(d[0], d[1]);
	    cout << count[k] << endl;
	    res += count[k]++;
	    cout << "k: " << k <<  " count[k]: " << count[k] << " res : " << res << endl;
	 }

	 for(const auto &p : count ){
		 cout << p.first << '\t' << p.second << std::endl;
	 }
	 return res;
}
/*
int main() {
	vector<vector<int>> dominoes;
	vector<int> nums1; nums1.push_back(1);nums1.push_back(1);
	vector<int> nums2; nums2.push_back(2);nums2.push_back(2);
	vector<int> nums3; nums3.push_back(1);nums3.push_back(1);
	vector<int> nums4; nums4.push_back(1);nums4.push_back(2);
	vector<int> nums5; nums5.push_back(1);nums5.push_back(2);
	vector<int> nums6; nums6.push_back(1);nums6.push_back(1);
	dominoes.push_back(nums1);dominoes.push_back(nums2);dominoes.push_back(nums3);
	dominoes.push_back(nums4);dominoes.push_back(nums5);dominoes.push_back(nums6);

	cout << numEquivDominoPairs(dominoes) << endl;
}*/
