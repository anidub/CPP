#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-window-substring/
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s
 * such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 *
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
https://leetcode.com/problems/minimum-window-substring/discuss/483132/C%2B%2B-Short-Sliding-Window-Solution-with-Explanation : comments
 */
class MinimumWindowSubstring {
public:
	//TC:O(N + M), SC:O(N + M)
	string minWindow(string s, string t) {
	    // Store the counts of characters in 't'
	    unordered_map<char, int> letters;
	    for(auto c : t) letters[c]++;

	    int count = 0; // Number of valid letters in the current window
	    int low = 0; // Stores the position of the first character in window
	    // Stores location and length of best substring
	    int min_length = INT_MAX, min_start = 0;

	    // Iterate over 's'
	    for(int high = 0; high<s.length(); high++) {
	        // If this character is required, then update count (Add it to the window)
	        if(letters[s[high]] > 0) count++;
	        // Reduce the count for this character (since we have added this to the window)
	        letters[s[high]]--;
	        // If we have all the valid characters, update substring
	        if(count == t.length()) {
	            // What exactly are we doing in the loop below?
	            //  This piece of code basically makes sure that letters[s[low]] is not negative
	            //  Because if it is negative, than that means we have more s[low]s than required.
	            //  So we have to remove such characters
	            while(low < high && letters[s[low]] < 0){
	                letters[s[low]]++; // Remove character from window, update count
	                low++; // Update substring window start
	            }
	            // Update substring
	            if(min_length > (high - low + 1)){
	                min_start = low; // Set start
	                min_length = high - low + 1; // Set length
	            }
	        }
	    }

	    // No substring satisfies 't'
	    if(min_length == INT_MAX) return "";

	    // Return the best substring
	    return s.substr(min_start, min_length);
	}
};
/*
int main() {
	MinimumWindowSubstring mws;
	cout << mws.minWindow("ADOBECODEBANC", "ABC") << endl;
}
*/
