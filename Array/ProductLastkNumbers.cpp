#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 * https://leetcode.com/problems/product-of-the-last-k-numbers/
 *Implement the class ProductOfNumbers that supports two methods:

1. add(int num)

Adds the number num to the back of the current list of numbers.
2. getProduct(int k)

Returns the product of the last k numbers in the current list.
You can assume that always the current list has at least k numbers.
At any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32

https://leetcode.com/problems/product-of-the-last-k-numbers/discuss/510260/JavaC%2B%2BPython-Prefix-Product
Time O(1) each
Space O(N)
 */

class ProductOfNumbers {
public:
	vector<int> products;

	ProductOfNumbers() {
		products.push_back(1);
	}

	void add(int num) {
		if(num)
			products.push_back(products.back() * num);
		else
			products = {1};
	}

	int getProduct(int k){
		print(products);
		if(k >= products.size()) return 0;
		return products.back() / products[products.size() - k - 1];
	}

    void print(vector<int>& nums) {
        cout << endl;
        for(int& i : nums)
            cout << i << " ";
        cout << endl;
    }
};
/*
int main() {
	ProductOfNumbers* obj = new ProductOfNumbers();
	obj->add(3);obj->add(0);obj->add(2);obj->add(5);obj->add(4);
	//obj->add(2);obj->add(3);obj->add(4);obj->add(8);obj->add(2);
	int param_2 = obj->getProduct(3);
	int param_3 = obj->getProduct(4);

	cout << "param_2: " << param_2 << " param_3:" << param_3 << endl;
	return 0;
}*/
