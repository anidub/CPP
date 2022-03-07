#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/friends-of-appropriate-ages/
 * Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.
Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.
Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
How many total friend requests are made?

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
https://leetcode.com/problems/friends-of-appropriate-ages/discuss/620199/C%2B%2B-or-Hashmap
https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127029/C%2B%2BJavaPython-Easy-and-Straight-Forward

For each age a and each age b != a, if request(a, b), we will make count[a] * count[b] requests.
For each age a, if request(a, a), we will make count[a] * (count[a] - 1) requests.
 */

bool isReq(int ageA, int ageB) {
	if(ageB <= 0.5 * ageA + 7) return false;
	if(ageB > ageA) return false;
	return true;
}

//O(A + C^2) : time complexity
int numFriendRequests(vector<int>& ages) {
	if(ages.empty()) return 0;
	int result = 0;
	unordered_map<int, int> count;
	for(int& i : ages)
		count[i]++;

	for(auto a = count.begin(); a != count.end(); a++) {
		for(auto b = count.begin(); b != count.end(); b++) {
			if(isReq(a->first, b->first)) {
				result += a->second * (b->second - (a->first == b->first ? 1 : 0));
			}
		}
	}

	return result;
}
/*
int main() {
	vector<int> ages;
	ages.push_back(16);ages.push_back(17);ages.push_back(18);
	cout << numFriendRequests(ages) << endl;

	return 0;
}*/
