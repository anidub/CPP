#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/3sum-with-multiplicity/
 * Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.
 * Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation:
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

https://leetcode.com/problems/3sum-with-multiplicity/solution/ : USED

https://leetcode.com/problems/3sum-with-multiplicity/discuss/1918457/C%2B%2B-Simplest-Solution-or-W-Easy-Explanation-or-Intuitive : TC:O(N^2), SC:O(N)
 */
//TC: O(N^2), SC:O(1)
int threeSumMulti(vector<int>& A, int target) {
	if(A.empty()) return 0;
	sort(A.begin(), A.end());
	int mod = 1e9 + 7;
	int ans = 0;

	for(int i = 0; i < A.size(); i++) {
		 // We'll try to find the number of i < j < k with A[j] + A[k] == T, where T = target - A[i]. The below is a "two sum with multiplicity".
		int T = target - A[i];
		int j = i + 1, k = A.size() - 1;
        while(j < k) {
        	// These steps proceed as in a typical two-sum.
            if(A[j] + A[k] < T) {
                j++;
            } else if(A[j] + A[k] > T) {
                k--;
            } else if(A[j] != A[k]) { // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...// And similarly for "right".
                int left = 1, right = 1;
                while(j + 1 < k && A[j] == A[j+1]) {
                    left++;
                    j++;
                }
                while(k > j - 1 && A[k] == A[k-1]) {
                    right++;
                    k--;
                }
                ans += left * right;
                ans %= mod;
                j++; k--;
            } else {
                ans += (k - j + 1) * (k - j) / 2;// M = k - j + 1 We contributed M * (M-1) / 2 pairs.
                ans %= mod;
                break;
            }
        }
	}
	return ans;
}
/*
int main() {
	vector<int> A = {1,1,2,2,3,3,4,4,5,5};
	cout << threeSumMulti(A, 8) << endl;

	return 0;
}*/
