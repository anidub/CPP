#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/longest-repeating-character-replacement/
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase
 * English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91271/Java-12-lines-O(n)-sliding-window-solution-with-explanation
https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
 */
class LongestRepeatingCharReplacement {
public:
	//TC:0(N), SC:O(N)
    int characterReplacement(string s, int k) {
    	if(s.empty()) return 0;
    	int start = 0, maxCount = 0, maxLength = 0;
    	vector<int> count(26, 0);

    	for(int end = 0; end < s.length(); end++) {
    		count[s[end] - 'A']++;
    		maxCount = max(maxCount, count[s[end] - 'A']);
    		while(end - start + 1 - maxCount > k) {
    			count[s[start] - 'A']--;
    			start++;
    		}
    		maxLength = max(maxLength, end - start + 1);
    	}
    	return maxLength;
    }
};
/*
int main() {
	LongestRepeatingCharReplacement lrcr;
	cout << lrcr.characterReplacement("ABAB", 3);
}*/
