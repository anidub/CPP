#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*https://leetcode.com/problems/random-pick-with-weight/
 * You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

https://www.youtube.com/watch?v=fWS0TCcr-lE
https://leetcode.com/problems/random-pick-with-weight/discuss/154044/Java-accumulated-freq-sum-and-binary-search
https://leetcode.com/problems/random-pick-with-weight/discuss/671415/C%2B%2B-Binary-Search-Approach(with-explanation)-(edited)
 */

class RandomPickWeights {
	vector<int> wSums;
public:
	RandomPickWeights(vector<int> weights) {//O(N)
		for(int ind : weights) {
			if(wSums.empty()) wSums.push_back(ind);
			else
				wSums.push_back(ind + wSums.back());
		}
	}
	//O(LOGN)
	int pickIndex() {
		int len = wSums.size();
		int x = wSums.back();
		int idx = rand() % x + 1;
		int left = 0, right = len - 1;

		while(left <= right) {
			int mid = left + (right - left)/ 2;
			if(wSums[mid] == idx)
				return mid;
			else if(wSums[mid] < idx)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
};
/*
int main() {
	RandomPickWeights *obj = new RandomPickWeights({1, 3});
	obj->pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
	obj->pickIndex(); // return 1
	obj->pickIndex(); // return 1
	cout << obj->pickIndex() << endl; // return 1
	cout << obj->pickIndex() << endl; // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

	delete obj;
	return 0;
}*/
