#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/Bn2KLlOR0lQ
 *You are visiting a farm to collect fruits. The farm has a single row of fruit trees. You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.

You will be given an array of characters where each character represents a fruit tree. The farm has following restrictions:

Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
You can start with any tree, but you can’t skip a tree once you have started.
You will pick exactly one fruit from every tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both baskets.
Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']


Similar Problems#
Problem 1: Longest Substring with at most 2 distinct characters

Given a string, find the length of the longest substring in it with at most two distinct characters.

Solution: This problem is exactly similar to our parent problem.
 */
//TC: O(N), SC: O(N)
int findFruitLength(const vector<char>& arr) {
	if(arr.empty()) return 0;
	int maxLength = 0, windowStart = 0;
	unordered_map<char, int> fruitFreq;

	for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
		fruitFreq[arr[windowEnd]]++;

		while(fruitFreq.size() > 2) { // 2 because 2 baskets in question means we need ony 2 types of fruits
			int leftFruit = arr[windowStart];
			fruitFreq[leftFruit]--;
			if(fruitFreq[leftFruit] == 0) fruitFreq.erase(leftFruit);
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}
/*
int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: " << findFruitLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  cout << "Maximum number of fruits: " << findFruitLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}*/
