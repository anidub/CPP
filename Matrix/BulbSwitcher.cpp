#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <math.h>       /* sqrt */
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/bulb-switcher/
 * There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off].
So you should return 1 because there is only one bulb is on.

https://www.youtube.com/watch?v=9XQxIvdqIt0 : well explained
https://leetcode.com/problems/bulb-switcher/discuss/77104/Math-solution..
 */
//TC: O(sqrt(N)), SC: O(1)
int bulbSwitch(int n) {
	return sqrt(n);
}
/*https://leetcode.com/problems/bulb-switcher/discuss/77133/My-0-ms-C%2B%2B-solution-with-explanation
 int bulbSwitch(int n) {
    int counts = 0;

    for (int i=1; i*i<=n; ++i) {
        ++ counts;
    }

    return counts;
}
 */
/*
int main () {
	cout << bulbSwitch(10) << endl;

	return 0;
}*/
