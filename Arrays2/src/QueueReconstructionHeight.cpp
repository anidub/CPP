#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/queue-reconstruction-by-height/
 *You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

https://leetcode.com/problems/queue-reconstruction-by-height/discuss/287878/A-simple-C%2B%2B-solution-with-explanation
    // [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    //
    // Sort first:
    //
    // [7, 0] 0
    // [7, 1] 1
    // [6, 1] 2
    // [5, 0] 3
    // [5, 2] 4
    // [4, 4] 5
    //
    // Reconstruct the queue step by step:
    //
    // [7, 0]
    // [7, 0] [7, 1]
    // [7, 0] [6, 1] [7, 1]
    // [5, 0] [7, 0] [6, 1] [7, 1]
    // [5, 0] [7, 0] 5, 2] [6, 1] [7, 1]
    // [5, 0] [7, 0] 5, 2] [6, 1] [4, 4] [7, 1]
 */
//TC: NLOGN
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	if(people.empty()) return {};

	auto cmp = [] (const vector<int> &a, const vector<int> &b) {
		return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1] );
	};

	sort(people.begin(), people.end(), cmp);
	vector<vector<int>> peopleAfter;

	for(int i = 0; i < people.size(); i++) {
		if(people[i][1] == people.size())
			peopleAfter.push_back(people[i]);// Heights of all previous people are greater or equal to current person.
		else
			peopleAfter.insert(peopleAfter.begin() + people[i][1], people[i]);
	}
	return peopleAfter;
}
/*
int main() {
	vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	reconstructQueue(people);

	return 0;
}*/
