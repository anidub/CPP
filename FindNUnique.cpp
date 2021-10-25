#include <iostream>
#include <vector>

using namespace std;

/*https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/discuss/464344/Trivial-PythonRubyJavaC%2B%2B
Given an integer n, return any array containing n unique integers such that they add up to 0.
Example 1:
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
*/
vector<int> findNUnique(int n) {
	vector<int> result(n);
    if(n==1)
        return {0};
    if(n==2)
        return {-1,1};
	for(int i = 1; i < n; i++) {
		result[i] = i;
		result[0] -= i;
	}
	return result;
}

/*
 * n = 1, [0]
n = 2, [-1, 1]

Now write more based on this
n = 3, [-2, 0, 2]
n = 4, [-3, -1, 1, 3]
n = 5, [-4, -2, 0, 2, 4]

It spreads like the wave.


Explanation
Find the rule
A[i] = i * 2 - n + 1
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/discuss/465585/JavaC%2B%2BPython-Find-the-Rule
 */
vector<int> findUnique(int n) {
	vector<int> result(n);
    if(n==1)
        return {0};
    if(n==2)
        return {-1,1};
    for(int i = 0; i < n; i++) {
    	result[i] = i * 2 - n + 1;
    }
    return result;
}

/*
int main() {

	findNUnique(5);
	return 0;
} */
