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
/*https://leetcode.com/problems/reverse-bits/
 * Reverse bits of a given 32 bits unsigned integer.
 * Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
so return 964176192 which its binary representation is 00111001011110000010100101000000.

https://www.youtube.com/watch?v=ZW7st_pN05w : well explained
https://leetcode.com/problems/reverse-bits/discuss/54738/Sharing-my-2ms-Java-Solution-with-Explanation : used
 */
class ReverseBits {
public:
	uint32_t reverseBits(uint32_t n) {
		int result = 0;

		for(int i = 0; i < 32; i++) {
			result <<= 1;
			if( (n & 1) == 1) result++;
			n >>= 1;
		}
		return result;
	}
};
/*
int main() {
	ReverseBits rb;
	cout << rb.reverseBits(00000010100101000001111010011100) << endl;
}
*/
