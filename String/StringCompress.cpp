#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/string-compression/
 * Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
https://leetcode.com/problems/string-compression/discuss/323715/C%2B%2B-Concise-Two-Pointer-Solution
 */
//TC:O(N)
int stringCompress(vector<char>& chars) {
	if(chars.empty()) return 0;
	int i = 0, count = 1;

	for(int j = 1; j <= chars.size(); j++) {
		if(j == chars.size() || chars[j] != chars[j-1]) {
			chars[i++] = chars[j-1];
			if(count >= 2) {
				for(char digit : to_string(count))
					chars[i++] = digit;
			}
			count = 0;
		}
		count++;
	}
	return i;
}
/*
int main() {
	vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	cout << stringCompress(chars) << endl;

	return 0;
}*/
