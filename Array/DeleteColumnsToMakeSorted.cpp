#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>

using namespace std;
/*
 * https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
 * You are given an array of n strings strs, all of the same length.
We may choose any deletion indices, and we delete all the characters in those indices for each string.
For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.
Example 1:
Input: strs = ["ca","bb","ac"]
Output: 1
Explanation:
After deleting the first column, strs = ["a", "b", "c"].
Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
We require at least 1 deletion since initially strs was not in lexicographic order, so the answer is 1.
https://leetcode.com/problems/delete-columns-to-make-sorted-ii/discuss/203171/C%2B%2B-12-ms-brute-force

 */
// O (n * c * c)) : n = input size, c = string size
int minDeletionSize(vector<string>& strs) {
	if(strs.size()) return 0;
	unordered_set<int> dict;

	for(int i = 1; i < strs.size(); i++) {
		for(int j = 0; j < strs[i].size(); j++) {
			if(dict.count(j) > 0 || strs[i-1][j] == strs[i][j]) continue;
			if(strs[i-1][j] > strs[i][j]){
				dict.insert(j);
				i = 0;
			}
			break;
		}
	}
	return dict.size();
}
/*
int main() {
	vector<string> strs;
	strs.push_back("ca");strs.push_back("bb");strs.push_back("ac");
	cout << minDeletionSize(strs) << endl;

	return 0;
}*/
