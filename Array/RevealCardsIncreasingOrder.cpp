#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/reveal-cards-in-increasing-order/
 * In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.
The first entry in the answer is considered to be the top of the deck
Example 1:

Input: [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation:
We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.

check here for explanation: https://www.youtube.com/watch?v=17hn4bnoOD0
https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/200515/JavaC%2B%2BPython-Simulate-the-Reversed-Process
We simulate the reversed process.
Initial an empty list or deque or queue,
each time rotate the last element to the first,
and append a the next biggest number to the left.

Time complexity:
O(NlogN) to sort,
O(N) to construct using deque or queue.
 */

vector<int> deckRevealedIncreasing(vector<int>& deck) {
	if(deck.size() == 0 || deck.size() <= 2) return deck;
	sort(deck.rbegin(), deck.rend());
	deque<int> d;
	d.push_back(deck[0]);

	for(int i = 1; i < deck.size(); i++) {
		d.push_front(d.back());
		d.pop_back();
		d.push_front(deck[i]);
	}
	vector<int> result(d.begin(), d.end());
	for(int i : result)
		cout << i << " ";
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(17);nums.push_back(13);nums.push_back(11);
	nums.push_back(2);nums.push_back(3);nums.push_back(5);nums.push_back(7);

	deckRevealedIncreasing(nums);
	return 0;
}
*/
