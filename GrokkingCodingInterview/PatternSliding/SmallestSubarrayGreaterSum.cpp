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
/*https://www.educative.io/courses/grokking-the-coding-interview/7XMlMEQPnnQ
 * Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2].
 */
//TC: O(N): The outer for loop runs for all elements, and the inner while loop processes each element only once; therefore, the time complexity of the algorithm will be O(N+N)
// which is asymptotically equivalent to O(N)

int findMinSubArray(int S, const vector<int>& arr) {
    // TODO: Write your code here
    int minLen = INT_MAX;
    int windowStart = 0, curSum = 0;

    for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      curSum += arr[windowEnd];
      while(curSum >= S) {
        minLen = min(minLen, windowEnd - windowStart + 1);
        curSum -= arr[windowStart];
        windowStart++;
      }
    }
    return minLen == INT_MAX ? 0 : minLen;
  }

/*
int main(int argc, char* argv[]) {
  int result = findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
  cout << "Smallest subarray length: " << result << endl;
  result = findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
}
*/
