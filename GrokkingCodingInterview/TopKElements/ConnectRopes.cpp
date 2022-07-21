#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/qVZmZJVxPY0
 *Given ‘N’ ropes with different lengths, we need to connect these ropes into one big rope with minimum cost.
 *Given  The cost of connecting two ropes is equal to the sum of their lengths.
 *Input: [1, 3, 11, 5]
Output: 33
Explanation: First connect 1+3(=4), then 4+5(=9), and then 9+11(=20). So the total cost is 33 (4+9+20)

https://stackoverflow.com/questions/57271271/is-there-a-maxheap-in-the-c-standard-library
priority_queue<int> maxHeap; // NOTE: default is max heap

priority_queue<int, vector<int> , greater<int>> minHeap;

There is also DP soln on Leetcode with merge stones
https://leetcode.com/problems/minimum-cost-to-merge-stones/
 */
class ConnectRopes {
public:
	//TC:O(NLOGN), SC:O(N)
	int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
		if(ropeLengths.empty()) return 0;

		priority_queue<int, vector<int>, greater<int>> min_heap;
		for(int i : ropeLengths)
			min_heap.push(i);

		int result = 0, temp = 0;

		while(min_heap.size() > 1) {
			temp = min_heap.top(); min_heap.pop();
			temp += min_heap.top(); min_heap.pop();

			result += temp;
			min_heap.push(temp);
		}
		return result;
	}
};

/*
int main(int argc, char *argv[]) {
	ConnectRopes cr;

  int result = cr.minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = cr.minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = cr.minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}*/
