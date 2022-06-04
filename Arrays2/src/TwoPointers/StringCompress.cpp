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
https://leetcode.com/problems/string-compression/discuss/92559/Simple-Easy-to-Understand-Java-solution
 */
//TC:O(N)
int stringCompress(vector<char>& chars) {
	if(chars.empty()) return 0;
	int n = chars.size();
	int index = 0, ans = 0;

	while(index < n) {
		char curChar = chars[index];
		int count = 0;
		while(index < n && curChar == chars[index]) {
			index++;
			count++;
		}
		chars[ans++] = curChar;
		if(count != 1){
			for(auto d : to_string(count))
				chars[ans++] = d;
		}
	}
	return ans;
}
/*
int main() {
	vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	cout << stringCompress(chars) << endl;

	return 0;
}*/
