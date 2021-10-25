#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
 * In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
We may rotate the ith domino, so that A[i] and B[i] swap values.
Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
If it cannot be done, return -1.
Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation:
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
 * https://www.youtube.com/watch?v=X1rIR9KGtmk : well explained
 * https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252242/JavaC%2B%2BPython-Different-Ideas
 */
int minDomonioRotationsOptimal(vector<int>& A, vector<int>& B) {
	if(A.empty() || B.empty()) return 0;
	int n = A.size();
	vector<int> faceA(7); //or of size 7
	vector<int> faceB(7); // or of size 7
	vector<int> same(7); //or of size 7

	for(int i = 0; i < n; i++) {
		faceA[A[i]]++;
		faceB[B[i]]++;
		if(A[i] == B[i]) same[A[i]]++;
	}

	int minRotations = INT_MAX;
	for(int i = 1; i < 7; i++) {
		if(faceA[i] + faceB[i] - same[i] == n){
			minRotations = min(minRotations, min(faceA[i], faceB[i]) - same[i]);
		}
	}
	return minRotations == INT_MAX ? -1 : minRotations;
}

int dominoRotations(vector<int>& A, vector<int>& B) {
	int minRotations = INT_MAX;
	for(int d = 1; d <= 6; d++) {
		int swap = 0;
		int i = 0;
		for(; i < A.size(); i++) {
			if(A[i] == d) continue;
			else if(B[i] == d) swap++;
			else break;
		}
		if(i == A.size() && minRotations > swap)
			minRotations = swap;
	}
	return minRotations = INT_MAX ? -1: minRotations;
}

int minDomonioRotations(vector<int>& A, vector<int>& B) {
	int AB = dominoRotations(A,B);
	int BA = dominoRotations(B,A);
	return AB  == -1 ? BA : BA == -1 ? AB : min(AB, BA);
}
/*
int main() {
	vector<int> A;
	A.push_back(2);A.push_back(1);A.push_back(2);A.push_back(4);A.push_back(2);A.push_back(2);
	vector<int> B;
	B.push_back(5);B.push_back(2);B.push_back(6);B.push_back(2);B.push_back(3);B.push_back(2);
	cout << minDomonioRotationsOptimal(A, B) << endl;
	cout << minDomonioRotations(A, B) << endl;
	return 0;
}
*/
