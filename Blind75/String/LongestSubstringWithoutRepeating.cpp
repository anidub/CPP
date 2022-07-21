#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Given a string s, find the length of the longest substring without repeating characters.
 * Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
 */
class LongestSubstringNonRepeating{
public:
	//TC:O(N), SC:O(N)
	int lengthOfLongestSubstring(string s) {
		if(s.empty()) return 0;
		unordered_map<char, int> mp;
		int longest = 0, windowStart = 0;

		for(int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
			char rightChar = s[windowEnd];
			if(mp.find(rightChar) != mp.end())
				windowStart = max(windowStart, mp[rightChar] + 1);

			mp[rightChar] = windowEnd;
			longest = max(longest, windowEnd - windowStart + 1);
		}
		return longest;
	}

	//TC:O(N), SC:O(N)
	int lengthOfLongestSubstringSlidingWindow(string s) {
		unordered_set<char> st;
		int left = 0, right = 0, n = s.length(), maxsize = 0;
		int istart = 0, iend= 0;

		while(left < n && right < n) {
			if(st.count(s[right]) == 0) {
				st.insert(s[right]);
				right++;
				if(right - left >= maxsize) {
					maxsize = right - left;
					istart = left;
					iend = right;
				}
			} else{
				st.erase(s[left]);
				left++;
			}
		}

		string ans = "";
		for(int i = istart; i < iend; i++) {
			ans += s[i];
		}
		cout << ans << endl;
		return maxsize;
	}
};
/*
int main() {
	LongestSubstringNonRepeating ls;
	cout << ls.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << ls.lengthOfLongestSubstringSlidingWindow("abcabcbb") << endl;
}*/
