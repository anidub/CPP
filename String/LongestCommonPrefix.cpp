#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/longest-common-prefix/
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
Input: strs = ["flower","flow","flight"]
Output: "fl"
https://leetcode.com/problems/longest-common-prefix/discuss/587345/C%2B%2B-Easy-solution-4ms
 */
//Time: O(S) , where S is the sum of all characters in all strings. Space complexity : O(1)
string longestCommonPrefix(vector<string>& strs) {
	if(strs.empty()) return "";
	int len = strs[0].length();

	for(string& s : strs) {
		if(len > s.length())
			len = s.length();
	}

	string result = "";
	int index = 0;
	for(char c : strs[0]) {
		for(int i = 1; i < strs.size(); i++) {
			if(strs[i][index] != c || index > len)
				return result;
		}
		result += c;
		index++;
	}
	return result;
}
/*https://leetcode.com/problems/longest-common-prefix/discuss/178187/C%2B%2B-using-binary-search-0ms
 * https://leetcode.com/problems/longest-common-prefix/solution/
 * Time complexity : O(S⋅logm), where S is the sum of all characters in all strings.

Space complexity : O(1). We only used constant extra space
 */

bool isCommonPrefix(vector<string>& strs, int len);
string longestCommonPrefixOptimal(vector<string>& strs) {
	if(strs.empty()) return "";
	int min_size = INT_MAX;
	for(string &s : strs) {
		if(min_size > s.size())
			min_size = s.size();
	}
	if(min_size == 0 || min_size == SIZE_MAX) return "";

	int low = 1, high = min_size;
	while(low <= high) {
		int mid = (low + high)/2;
		if(isCommonPrefix(strs, mid))
			low = mid+1;
		else
			high = mid-1;
	}
	return strs[0].substr(0, (low+high)/2);
}

bool isCommonPrefix(vector<string> &strs, int len) {
	for(int i = 1; i < strs.size(); i++) {
		if(strs[i].substr(0, len) != strs[0].substr(0, len))
			return false;
	}
	return true;
}

/*
int main() {
	vector<string> strs = {"flower","flow","flight"};
	cout << longestCommonPrefix(strs) << endl;
	cout << longestCommonPrefixOptimal(strs) << endl;
	return 0;
}
*/
