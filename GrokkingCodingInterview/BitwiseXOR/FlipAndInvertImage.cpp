#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/3j7zEJzL2y9
 * Given a binary matrix representing an image, we want to flip the image horizontally, then invert it.

To flip an image horizontally means that each row of the image is reversed. For example, flipping [0, 1, 1] horizontally results in [1, 1, 0].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [1, 1, 0] results in [0, 0, 1].
https://leetcode.com/problems/flipping-an-image/
 */
class FlipInvertImage {
public:
	 vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		 if(A.empty()) return A;

		 for(auto &row : A) {
			 int l = 0, r  = row.size() - 1, temp;
			 while(l < r) {
				 temp = row[l];
				 row[l] = row[r];
				 row[r] = temp;
				 l++; r--;
			 }
		 }

		 for(auto &row : A) {
			 for(int i = 0; i < row.size(); i++) {
				 if(row[i] == 0)
					 row[i] = 1;
				 else
					 row[i] = 0;
			 }
		 }
		 return A;
	 }

	 void print( vector<vector<int>> arr) {
	       for(int i=0; i < arr.size(); i++) {
	         for (int j=0; j < arr[i].size(); j++) {
	           cout << arr[i][j] << " ";
	         }
	         cout << endl;
	       }
	     }
};
/*
int main(int argc, char* argv[]) {
	FlipInvertImage fi;
  vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  fi.flipAndInvertImage(arr);
  fi.print(arr);
  cout << endl;

  vector<vector<int>> arr2 = vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
  fi.print(fi.flipAndInvertImage(arr2));
}
*/
