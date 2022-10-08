#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/qVljv3Plr67
 * Given an array, find the sum of all numbers between the K1’th and K2’th smallest elements of that array.
 * Input: [1, 3, 12, 5, 15, 11], and K1=3, K2=6
Output: 23
Explanation: The 3rd smallest number is 5 and 6th smallest number 15. The sum of numbers coming
between 5 and 15 is 23 (11+12).

 */
class SumOfElements {
 public:
	//TC:O(N *LOGK2) SC:O(K2)
  int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int elementSum = 0;
    priority_queue<int> max_heap;

    // keep smallest k2 numbers in the max heap
    for(int i = 0; i < nums.size(); i++) {
    	if(i < k2 - 1)
    		max_heap.push(nums[i]);
    	else if(nums[i] < max_heap.top()) {
    		max_heap.pop(); // as we are interested only in the smallest k2 numbers
    		max_heap.push(nums[i]);
    	}
    }

    // get the sum of numbers between k1 and k2 indices these numbers will be at the top of the max heap
    for(int i = 0; i < k2 - k1 - 1; i++) {
    	elementSum += max_heap.top();
    	max_heap.pop();
    }
    return elementSum;
  }
};

/*
int main(int argc, char *argv[]) {
	SumOfElements soe;
  int result = soe.findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = soe.findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}
*/
