#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/* https://leetcode.com/problems/nested-list-weight-sum/
 * You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.
Input: nestedList = [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.
https://leetcode.com/problems/nested-list-weight-sum/discuss/249952/C%2B%2B-recursive-and-iterative
 */

// This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
//TC:O(N), SC:O(N)

 class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

 //TC:O(N), SC:O(N)
 int depthSum(vector<NestedInteger>& nestedList) {
     queue<NestedInteger> todo;
     for (auto &i : nestedList) {
         todo.push(i);
     }
     int sum = 0, depth = 1;

     while (!todo.empty()) {
         int n = todo.size();
         for (int i = 0; i < n; i++) {
             NestedInteger ni = todo.front();
             todo.pop();
             if (ni.isInteger()) {
                 sum += ni.getInteger() * depth;
             } else {
                 for (auto j : ni.getList()) {
                     todo.push(j);
                 }
             }
         }
         depth++;
     }
     return sum;
 }
/*
int main() {


	return 0;
}*/
