#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-hashset/
 * //works tested on https://onlinegdb.com/tfrAcBLWE : used
 * https://leetcode.com/problems/design-hashset/discuss/773006/C%2B%2B-3-Approaches
 */

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
  }
};

class BSTree {
 public:
   TreeNode *root = nullptr;

  TreeNode* searchBST(TreeNode *root, int val) {
    if (root == nullptr || val == root->val)
      return root;

    return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
  }

  TreeNode* insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr)
      return new TreeNode(val);

    if (val > root->val)
      root->right = insertIntoBST(root->right, val);
    else if (val == root->val)
      // skip the insertion
      return root;
    else
      // insert into the left subtree
      root->left = insertIntoBST(root->left, val);
    return root;
  }

  int successor(TreeNode *root) {
    root = root->right;
    while (root->left != nullptr)
      root = root->left;
    return root->val;
  }

  int predecessor(TreeNode *root) {
    root = root->left;
    while (root->right != nullptr)
      root = root->right;
    return root->val;
  }

  TreeNode* deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return nullptr;

    // delete from the right subtree
    if (key > root->val)
      root->right = deleteNode(root->right, key);
    // delete from the left subtree
    else if (key < root->val)
      root->left = deleteNode(root->left, key);
    // delete the current node
    else {
      // the node is a leaf
      if (root->left == nullptr && root->right == nullptr)
        root = nullptr;
      // the node is not a leaf and has a right child
      else if (root->right != nullptr) {
        root->val = successor(root);
        root->right = deleteNode(root->right, root->val);
      }
      // the node is not a leaf, has no right child, and has a left child
      else {
        root->val = predecessor(root);
        root->left = deleteNode(root->left, root->val);
      }
    }
    return root;
  }
};

class Bucket {
public:
  BSTree *tree;
  Bucket() {
    tree = new BSTree();
  }

  void insert(int key) {
    this->tree->root = this->tree->insertIntoBST(this->tree->root, key);
  }
  void deleteKey(int key) {
    this->tree->root = this->tree->deleteNode(this->tree->root, key);
  }

  bool exists(int key) {
    TreeNode *node = this->tree->searchBST(this->tree->root, key);
    return (node != nullptr);
  }
};


class MyHashSet {
public:
   vector<Bucket*> bucketArray;
   int keyRange;

  //Initialize your data structure here.
  MyHashSet() {
    keyRange = 20;
    bucketArray.resize(20);
    for (int i = 0; i < keyRange; ++i)
      bucketArray[i] = new Bucket();
  }

   int _hash(int key) {
    return (key % keyRange);
  }

  void add(int key) {
    int bucketIndex = _hash(key);
    bucketArray[bucketIndex]->insert(key);
  }

  void removeKey(int key) {
    int bucketIndex = _hash(key);
    bucketArray[bucketIndex]->deleteKey(key);
  }

  // Returns true if this set contains the specified element
  bool contains(int key) {
    int bucketIndex = _hash(key);
    return bucketArray[bucketIndex]->exists(key);
  }
};
/*
int main(){
  MyHashSet *myHashSet = new MyHashSet();
  myHashSet->add(1);      // set = [1]
  myHashSet->add(2);      // set = [1, 2]
  cout << myHashSet->contains(1) << endl; // return True
  cout << myHashSet->contains(3) << endl; // return False, (not found)
  myHashSet->add(2);      // set = [1, 2]
  cout << myHashSet->contains(2) << endl; // return True
  myHashSet->removeKey(2);   // set = [1]
  cout << myHashSet->contains(2) << endl; // return False, (already removed)

  delete myHashSet;
  return 0;
}
*/
