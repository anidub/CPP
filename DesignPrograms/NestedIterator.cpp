#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/flatten-nested-list-iterator/
 * You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
int next() Returns the next integer in the nested list.
boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80146/Real-iterator-in-Python-Java-C%2B%2B
 */

class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		begins.push(nestedList.begin());
		ends.push(nestedList.end());
	}

	int next() {
		return (begins.top()++)->getInteger();
	}
/* WORKS!
	bool hasNext() {
		while(begins.size()) {
			if(begins.top() == ends.top()) {
				begins.pop();
				ends.pop();
			} else {
				auto x = begins.top();
				if(x->isInteger())
					return true;
				begins.top()++;
				begins.push(x->getList().begin());
				ends.push(x->getList().end());
			}
		}
		return false;
	}*/

private:
	stack<vector<NestedInteger>::iterator> begins, ends;
};
