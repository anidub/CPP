#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <set>

using namespace std;
/*https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * Given an integer array bloomDay, an integer m and an integer k.
We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
Example 1:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
https://www.youtube.com/watch?v=paYIrQKxE7I&t=899s
More problems similar: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686316/JavaC%2B%2BPython-Binary-Search
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686812/Intuition-behind-the-Bin-Search-video-explanation-wcode
More similar problems: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/769703/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
Similar Binary Search problems:
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
https://leetcode.com/problems/koko-eating-bananas/
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
 */
//https://www.youtube.com/watch?v=paYIrQKxE7I&t=899s
int getBouquetFlowerDays(vector<int>& bloomDay, int m, int k) {
	if(bloomDay.empty()) return 0;
	int n = bloomDay.size();
	if(n < m*k) return -1;

	int maxE = INT_MIN;
	int minE = INT_MAX;

	for(auto& day : bloomDay) {
		minE = min(minE, day);
		maxE = max(maxE, day);
	}

	int mid, curr, adj;

	while(minE < maxE) {
		mid = minE + (maxE-minE)/2;

		curr = 0, adj = 0;
		for(int i = 0; i < n; i++) {
			if(bloomDay[i] > mid)
				adj = 0;
			else{
				adj++;
				if(adj == k){
					adj = 0;
					curr++;
				}
			}
			if(curr >= m) break;
		}
		if(curr < m) minE = mid + 1;
		else maxE = mid;
	}
	return minE;

}
/*
int main() {
	vector<int> bloomDay;
	bloomDay.push_back(1);bloomDay.push_back(10);bloomDay.push_back(3);bloomDay.push_back(10);bloomDay.push_back(2);
	cout << getBouquetFlowerDays(bloomDay, 3, 1) << endl;

	return 0;
}
*/
