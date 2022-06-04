#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/YQQwQMWLx80
 *Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
 */
//TC: O(N)The outer for loop runs for all characters, and the inner while loop processes each character only once; therefore, the time complexity of the algorithm will be O(N+N)
// which is asymptotically equivalent to O(N)
// SC: O(K)
int findMaxLengthKDistinct(const string& str, int k) {
	if(str.empty()) return 0;
	int maxLength = 0; unordered_map<char, int> charFreq;
	int windowStart = 0;

	for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
		charFreq[str[windowEnd]]++;

		while(charFreq.size() > k) {
			int leftChar = str[windowStart];
			charFreq[leftChar]--;

			if(charFreq[leftChar] == 0) charFreq.erase(leftChar);
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}
/*
int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << findMaxLengthKDistinct("araaci", 2) << endl;
  cout << "Length of the longest substring: " << findMaxLengthKDistinct("araaci", 1) << endl;
  cout << "Length of the longest substring: " << findMaxLengthKDistinct("cbbebi", 3) << endl;
}*/
