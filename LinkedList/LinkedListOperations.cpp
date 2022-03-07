#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*
 * https://www.bogotobogo.com/cplusplus/linkedlist.php
 */
struct LLNode {
	int data;
	LLNode* next;

	//LLNode(int d) : data(d), next(nullptr) {}
};

void addNode(struct LLNode* head, int n) {
	LLNode* newNode = new LLNode;
	newNode->data = n;
	newNode->next = NULL;

	LLNode* cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertFront(struct LLNode **head, int n) {
	LLNode* newNode = new LLNode;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

struct LLNode * searchNode(LLNode *head, int n) {
	LLNode *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	return NULL;
}

bool deleteNode(struct LLNode **head, LLNode *ptrDel) {
	LLNode *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

LLNode* reverseIterative(struct LLNode **head) {
	LLNode *parent = *head;
	LLNode *me = parent->next;
	LLNode *child = me->next;
	/* make parent as tail */
	parent->next = NULL;

	while(child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}

	me->next = parent;
	*head = me;
	return *head;
}
//https://leetcode.com/problems/reverse-linked-list/discuss/58130/C%2B%2B-Iterative-and-Recursive
LLNode* reverseRecursive(LLNode *head) {
	if(!(head) || !(head->next))
		return head;

	LLNode *node = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}

//https://www.techgeekbuzz.com/clone-a-singly-linked-list/
LLNode* copyLinkedList(LLNode *head) {
	LLNode *newList = NULL;
	LLNode *cur = head;
	LLNode *tail = head;

	while(cur != NULL) {
		if(newList == NULL) {
			newList =  (struct LLNode*)malloc(sizeof(struct LLNode));
			newList->data = cur->data;
			newList->next = cur->next;
			tail = newList;
		} else {
			tail->next = (struct LLNode*)malloc(sizeof(struct LLNode));
			tail = tail->next;
			tail->data = cur->data;
			tail->next = NULL;
		}
		cur = cur->next;
	}
	return newList;
}

bool compareLinkedList(LLNode *node1, LLNode *node2) {
	if(node1 == NULL && node2 == NULL) return true;
	else {
		if(node1 == NULL || node2 == NULL) return false;
		else if(node1->data != node2->data) return false;
		else
			return compareLinkedList(node1->next, node2->next);
	}
}

void deleteLinkedList(LLNode *head) {
	LLNode *tmpNode;
	while(head) {
		tmpNode = head;
		head = tmpNode->next;
		delete tmpNode;
	}
}

void printLL(LLNode *head) {
	cout << "----------------------------------" << endl;
	LLNode *cur = head;
	while(cur != NULL) {
		cout << cur->data << "-";
		cur = cur->next;
	}
	cout << endl;
}
/*
int main() {
	LLNode *head = new LLNode; head->data = 1;
	head->next = new LLNode; head->next->data = 2;
	head->next->next = new LLNode; head->next->next->data = 3;
	head->next->next->next = NULL;
	printLL(head);
	addNode(head, 4);
	printLL(head);
	insertFront(&head, 0);
	printLL(head);
	cout << searchNode(head, 2)->data << endl;

	LLNode *ptrDelete = searchNode(head,0);
	cout << deleteNode(&head, ptrDelete) << endl;
	printLL(head);
	reverseIterative(&head);
	printLL(head);
	//reverseRecursive(head);

	LLNode *newHead = copyLinkedList(head);
	cout << "new head copied:" << endl;
	printLL(newHead);

	cout << "comparing:" << compareLinkedList(head, newHead) << endl;

	deleteLinkedList(head);
	printLL(newHead);



	delete head;
	return 0;
}*/
