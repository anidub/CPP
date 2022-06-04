#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;
/*https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
 * https://www.youtube.com/watch?v=3pvZhwp0U9w
 *
 * comparator behavior is opposite for PQ vs sort
 *
 * in regular sort put elements in desired order. example (a, b) : return a  < b; means ascending order. a > b means descending order
 * for pq opposite of above
 */
#define ROW 5
#define COL 2

class Person {
public:
	int age;
	float height;

	// this is used to initialize the variables of the class
	Person(int age, float height)
		: age(age), height(height)
	{
	}
};

// we are doing operator overloading through this
bool operator<(const Person& p1, const Person& p2){
	// this will return true when second person has greater height. Suppose we have p1.height=5
	// and p2.height=5.5 then the object which have max height will be at the top(or max priority)
	return p1.height < p2.height;
}

bool cmp(Person p1, Person p2) {
	return p1.height < p2.height;
}
/*
int main(){
	priority_queue<Person> Q;
	float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },{ 20, 6 }, { 33, 6.1 }, { 23, 5.6 } };

	for (int i = 0; i < ROW; ++i) {
		Q.push(Person(arr[i][0], arr[i][1]));
	}
  vector<Person> persons;
  for (int i = 0; i < ROW; ++i) {
  	persons.push_back(Person(arr[i][0], arr[i][1]));
  }
  sort(persons.begin(), persons.end(), cmp);
  cout << "-----------Regular sorting begins----- " << "\n";
  for(auto p : persons) {
    cout << p.age << " " << p.height << "\n";
  }

    cout << "-----------PQ sorting begins----- " << "\n";
	while (!Q.empty()) {
		Person p = Q.top();
		Q.pop();
		cout << p.age << " " << p.height << "\n";
	}
	return 0;
}
*/
