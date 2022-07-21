#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

/*
 *
 * https://www.enjoyalgorithms.com/blog/find-the-kth-smallest-element-in-an-array
 */
class KthSmallestNumber {
public:

	int getKthSmallestStartWithThis(vector<int> &nums, int K) {
		if(nums.empty()) return -1;
		int res = INT_MIN;
		priority_queue<int> pq;
		for(int n : nums)
			pq.push(n);

		while(!pq.empty()) {
			res = pq.top();
			pq.pop();
			K--;
			if(K == 0) return res;
		}
		return res;
	}

int getKthSmallest(vector<int> &nums, int K) {
	int n = nums.size();
	findKthSmallestNumber(nums, 0, n - 1, K);

}

//Avg case: TC:O(N), SC:O(N), Worse case : TC:O(N^2), SC:O(N)
 int findKthSmallestNumber(vector<int> &A, int left, int right, int K) {
	    if (left == right)
	         return A[left];
	    int pos = partition(A, left, right);
	    int count = pos - left + 1;
	    if ( count == K )
	         return A[pos];
	    else if ( count > K )
	         return findKthSmallestNumber(A, left, pos-1, K);
	    else
	         return findKthSmallestNumber(A, pos+1, right, K - count)  ;
 }

 int partition(vector<int> &A, int left, int right)  {
     int pivot = A[right];
     int i = left - 1;
     for (int j = left; j < right; j++) {
         if (A[j] <= pivot) {
             i = i + 1;
             swap(A[i], A[j]);
         }
     }
     swap(A[i+1], A[right]);
     return i+1;
 }
};
/*
int main(int argc, char *argv[]) {
	KthSmallestNumber ksn;
	vector<int> a1 = {1, 5, 12, 2, 11, 5};
  int result = ksn.getKthSmallest(a1, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  vector<int> a2 = {1, 5, 12, 2, 11, 5};
  result = ksn.getKthSmallest(a2, 4);
  cout << "Kth smallest number is: " << result << endl;

  vector<int> a3 = {5, 12, 11, -1, 12};
  result = ksn.getKthSmallest(a3, 3);
  cout << "Kth smallest number is: " << result << endl;
}
*/
