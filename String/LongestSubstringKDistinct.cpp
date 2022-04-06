#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 * Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters
 * Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/discuss/80108/C%2B%2B-two-concise-solutions%3A-hash-%2B-two-pointers-for-short-string-and-hash-for-super-long-string
 */
// TC: O(NK) : the worst case of N distinct characters in the string.
//SC : O(k): for map
int lengthOfLongestSubstringKDistinct(string s, int k) {
	if(s.empty()) return 0;
	int ans = 0, left = 0, right = 0;
	unordered_map<char, int> freq;

	for(; right < s.length(); right++) {
		freq[s[right]]++;
		if(freq.size() > k) {
			ans = max(ans, right - left);

			while(freq.size() > k) {
				freq[s[left]]--;
				if(freq[s[left++]] == 0)
					freq.erase(s[left - 1]);
			}
		}
	}
	return max(ans, right - left);
}
/*
int main() {
	cout << lengthOfLongestSubstringKDistinct("eceba", 2) << endl;

	return 0;
}*/
