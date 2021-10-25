#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <set>

using namespace std;
/*
 * https://leetcode.com/problems/advantage-shuffle/
 * Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
Return any permutation of A that maximizes its advantage with respect to B.
Example 1:
Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
https://leetcode.com/problems/advantage-shuffle/discuss/1125217/JS-Python-Java-C%2B%2B-or-Short-Solution-w-Explanation
https://leetcode.com/problems/advantage-shuffle/discuss/149831/C%2B%2B-6-lines-greedy-O(n-log-n)
 */
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<int> ord(B.size(), 0);
    vector<int> result(A.size());
     for (int i = 0; i < B.size(); i++)
        ord[i] = i;

    sort(ord.begin(), ord.end(), [&](int a, int b){ return B[a] > B[b];});
    sort(A.begin(), A.end());

    int i = 0, j = B.size() - 1;
    for(int ix: ord) {
        result[ix] = A[i] > B[ix] ? A[i++] : A[j--];
    }
    return result;
}

vector<int> advantageCountOptimal(vector<int>& A, vector<int>& B) {
	multiset<int> s(begin(A), end(A));

	for(auto i = 0; i < B.size(); i++) {
		auto p = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
		A[i] = *p;
		s.erase(p);
	}
	return A;
}
/*
int main() {
	vector<int> A;
	A.push_back(2);A.push_back(7);A.push_back(11);A.push_back(15);

	vector<int> B;
	B.push_back(1);B.push_back(10);B.push_back(4);B.push_back(11);
	advantageCount(A, B);
	advantageCountOptimal(A, B);
	return 0;
}*/
