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
/*https://leetcode.com/problems/number-of-1-bits/
 * Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
https://leetcode.com/problems/number-of-1-bits/discuss/55255/C%2B%2B-Solution%3A-n-and-(n-1) : well explained
n & (n - 1) drops the lowest set bit. It's a neat little bit trick.

Let's use n = 00101100 as an example. This binary representation has three 1s.

If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.

If n = 00101000, then n - 1 = 00100111, so n & (n - 1) = 00101000 & 00100111 = 00100000. Count = 2.

If n = 00100000, then n - 1 = 00011111, so n & (n - 1) = 00100000 & 00011111 = 00000000. Count = 3.

n is now zero, so the while loop ends, and the final count (the numbers of set bits) is returned.

 */
class NumberOfSetBits {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;

		while(n) {
			n &= (n - 1);
			count++;
		}
		return count;
	}
};
/*
int main() {
	NumberOfSetBits nsb;
	cout << nsb.hammingWeight(00000000000000000000000000001011) << endl;

}*/
