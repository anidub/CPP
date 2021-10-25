#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * https://leetcode.com/problems/1-bit-and-2-bit-characters/
 * We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
Example 1:
Input:
bits = [1, 0, 0]
Output: True
Explanation:
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

https://www.youtube.com/watch?v=WFx9H8QSV4s
https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/693741/C%2B%2B-solution
https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/744719/C%2B%2B-oror-Brute-Force-Approach-oror-8-ms

 */

bool isOneBitCharacter(vector<int>& bits) {
	if(bits.empty())
		return false;
	int i = 0;
	while(i < bits.size()) {
		if(bits[i] = 1)
			i++;
		i++;
	}
	return i != bits.size();
}

/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(1);nums.push_back(1);nums.push_back(0);
	cout << isOneBitCharacter(nums) << endl;
	return 0;
}
*/
