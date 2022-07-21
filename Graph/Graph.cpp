#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <list>

using namespace std;
/*https://www.section.io/engineering-education/graphs-in-data-structure-using-cplusplus/
 *
 */

class Graph {
public:
	list<int> *adjList;
	int n;

	Graph(int v) {
		adjList = new list<int>[v];
		n = v;
	}

	void addEdge(int u, int v) {
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void print() {
		for(int i = 1; i < n; i++) {
			cout << i << "--->";
			for(auto it : adjList[i]){
				cout << it << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};
/*
int main() {
	Graph g(5);
	g.addEdge(1, 2);
	g.addEdge(4, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 3);
	g.addEdge(1, 4);

	g.print();
}*/
