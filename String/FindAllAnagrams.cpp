#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 * Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

 *https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/1738073/Short-and-simple-C%2B%2B-sliding-window-solution : used
 *https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92027/C%2B%2B-O(n)-sliding-window-concise-solution-with-explanation
 */
//TC: O(N), SC:O(26) = O(1)
vector<int> findAnagrams(string s, string t) {
	vector<int> ans;
	int s_len = s.length(), t_len = t.length();
	if(s_len < t_len) return ans;

	vector<int> freq_t(26, 0);
	vector<int> window(26, 0);

	for(int i = 0; i < t_len; i++) { // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
		freq_t[t[i] - 'a']++;
		window[s[i] - 'a']++;
	}

	if(freq_t == window) ans.push_back(0);

	 //here window is moving from left to right across the string. window size is p.size(), so s.size()-p.size() moves are made
	for(int i = t_len; i < s_len; i++) {
		window[s[i] - 'a']++;// window extends one step to the right. counter for s[i] is incremented

		window[s[i - t_len] - 'a']--;   // since we added one element to the right, one element to the left should be discarded. counter for s[i-p.size()] is decremented

		if(freq_t == window) ans.push_back(i - t_len + 1);// this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
	}
	return ans;
}
//https://www.educative.io/courses/grokking-the-coding-interview/YQ8N2OZq0VM USED!
vector<int> findAnagramsPattern(string s, string t) {
	unordered_map<char, int> charFreq;
	int matched = 0, windowStart = 0;
	vector<int> result;
	for(char &c : t) {
		charFreq[c]++;
	}

	for(int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
		char rightChar = s[windowEnd];
		if(charFreq.find(rightChar) != charFreq.end()) {
			charFreq[rightChar]--;
			if(charFreq[rightChar] == 0) matched++;
		}
		if(matched == charFreq.size()) result.push_back(windowStart);

		if(windowEnd >= t.length() - 1) {
			char leftChar = s[windowStart++];
			if(charFreq.find(leftChar) != charFreq.end()) {
				if(charFreq[leftChar] == 0) matched--;
				charFreq[leftChar]++;
			}
		}
	}
	return result;
}

/*
int main() {
	findAnagrams("cbaebabacd", "abc");

	return 0;
}*/
