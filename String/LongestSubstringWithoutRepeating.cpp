#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Given a string s, find the length of the longest substring without repeating characters.
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

 https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/376363/CPP-Solution-for-beginners-or-O(n)-time-or-Longest-Substring-without-repeating-characters
 */
int lengthOfLongestSubstringWithoutRepeating(string s) {
	/*if(s.empty()) return 0;
    unordered_set<char> set;

    int i = 0, j = 0, n = s.size(), maxsize = 0;
    int istart = 0, iend = 0; //to print those chars
    while(i < n && j < n) {
        if(set.count(s[j]) == 0) {
            set.insert(s[j]);
            j++;
           // maxsize = max(maxsize, j-i);
            if( (j-i)  >= maxsize) {
                istart = i;
                iend = j;
                maxsize = j-i;
            }
        } else {
            set.erase(s[i]); i++;
        }
    }
    string an = "";
    for(int i = istart; i < iend; i++)
        an += s[i];
    cout << an << endl;
    return maxsize; */
	if(s.empty()) return 0; //GTCI
	unordered_map<char, int> mp;
	int longest = 0, windowStart = 0;
	for(int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
		char rightChar = s[windowEnd];
		if(mp.find(rightChar) != mp.end()) {
			windowStart = max(windowStart, mp[rightChar] + 1);
		}
		mp[rightChar] = windowEnd;;
		longest = max(longest, windowEnd - windowStart + 1);
	}
	return longest;
}
/*
int main() {
	cout << lengthOfLongestSubstringWithoutRepeating("pwwkew") << endl;

	return 0;
}*/
