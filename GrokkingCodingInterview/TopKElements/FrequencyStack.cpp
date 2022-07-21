#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/Y5zDWlVRz2p
 * Frequency Stack (hard)#
Design a class that simulates a Stack data structure, implementing the following two operations:

push(int num): Pushes the number ‘num’ on the stack.
pop(): Returns the most frequent number in the stack. If there is a tie, return the number which was pushed later.
After following push operations: push(1), push(2), push(3), push(2), push(1), push(2), push(5)

1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2
https://leetcode.com/problems/maximum-frequency-stack/
https://leetcode.com/problems/maximum-frequency-stack/discuss/361469/C%2B%2B-short-solution-with-priority_queue : used

TC: O(LOGN) SC:O(N)
 */
class FrequencyStack {
unordered_map<int, int> freq;// element count
priority_queue< pair<int, pair<int, int> > > max_heap;
int pos = 0;
 public:
  void push(int num) {
    freq[num]++;
    pos++;
    max_heap.push( {freq[num], {pos, num} });
  }

  int pop() {
    auto val = max_heap.top(); max_heap.pop();
    int x = val.second.second;
    freq[x]--;
     return x;
  }
};
/*https://leetcode.com/problems/maximum-frequency-stack/discuss/1861911/C%2B%2B-or-Easy-solution-with-explanation-or-Simple-solution
 * Time Complexity : O(1) FOR PUSH AND POP
Space Complexity : O(N)
 */
class FreqStackUsingStacks {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group_stack;
    int max_freq = 0;

public:
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        group_stack[freq[val]].push(val);
    }

    int pop() {
        int val = group_stack[max_freq].top();
        group_stack[max_freq].pop();

        freq[val]--;
        if(group_stack[max_freq].size() == 0)
            max_freq--;
        return val;
    }
};
/*
int main(int argc, char *argv[]) {
  FrequencyStack frequencyStack;
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(3);
  frequencyStack.push(2);
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(5);
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
}
*/
