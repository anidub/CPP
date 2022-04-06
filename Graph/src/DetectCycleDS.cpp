#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://www.youtube.com/watch?v=eTaWFhPXPz4
 *
 */
vector<int> dsuf;

int find(int v) {
	if(dsuf[v] == -1)
		return v;
	return find(dsuf[v]);
}

void union_op(int fromP, int toP) {
	fromP = find(fromP);
	toP = find(toP);

	dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int, int>> &edgeList) {
	for(auto p : edgeList) {
		int fromP = find(p.first);
		int toP = find(p.second);

		if(fromP == toP)
			return true;
		union_op(fromP, toP);
	}
	return false;
}

/*
int main () {
	int E = 5;
	int V = 5;

	dsuf.resize(V, -1);
	vector<pair<int, int>> edgeList;

	for(int i = 0; i < E; i++) {
		int from = i;
		int to = i + 1;
		edgeList.push_back({from, to});
	}
	cout << isCyclic(edgeList) << endl;
	return 0;
}
*/
