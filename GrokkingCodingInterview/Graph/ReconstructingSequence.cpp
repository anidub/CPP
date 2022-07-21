#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/m7VAO5OrQr3
 * Given a sequence originalSeq and an array of sequences, write a method to find if originalSeq can
 *  be uniquely reconstructed from the array of sequences.

Unique reconstruction means that we need to find if originalSeq is the only sequence such that all sequences in the array are subsequences of it.
Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct
[1, 2, 3, 4], in other words, all the given sequences uniquely define the order of numbers
in the 'originalSeq'.
 */
class SequenceReconstruction {
 public:
	//TC:O(V + N), SC:O(V + N)
  bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
	 vector<int> sortedOrder;
	 if(originalSeq.size() <= 0) return false;

	 unordered_map<int, int> inDegree;
	 unordered_map<int, vector<int>> graph;

	 for(auto seq : sequences) {
		 for(int i = 0; i < seq.size(); i++) {
			 inDegree[seq[i]] = 0;
			 graph[seq[i]] = vector<int>();
		 }
	 }

	 for(auto seq : sequences) {
		 for(int i = 1; i < seq.size(); i++) {
			 int parent = seq[i - 1], child = seq[i];
			 graph[parent].push_back(child);
			 inDegree[child]++;
		 }
	 }

	 // if we don't have ordering rules for all the numbers we'll not able to uniquely construct the sequence
	 if(inDegree.size() != originalSeq.size()) return false;
	 queue<int> sources;

	 for(auto entry : inDegree) {
		 if(entry.second == 0)
			 sources.push(entry.first);
	 }

	 // d. For each source, add it to the sortedOrder and subtract one from all of its children's
	 //in-degrees if a child's in-degree becomes zero, add it to the sources queue
	 while(!sources.empty()) {
		 if(sources.size() > 1) return false; // more than one sources mean, there is more than one way to reconstruct the sequence
		 if(originalSeq[sortedOrder.size()] != sources.front())
			 return false;// the next source (or number) is different from the original sequence
		 int vertex = sources.front(); sources.pop();
		 sortedOrder.push_back(vertex);
		 auto children = graph[vertex];
		 for(auto child : children) {
			 inDegree[child]--;
			 if(inDegree[child] == 0)
				 sources.push(child);
		 }
	 }
	    // if sortedOrder's size is not equal to original sequence's size, there is no unique way to construct
	 return sortedOrder.size() == originalSeq.size();
  }
};

/*
int main(int argc, char *argv[]) {
	SequenceReconstruction sr;
  bool result = sr.canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = sr.canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = sr.canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}
*/
