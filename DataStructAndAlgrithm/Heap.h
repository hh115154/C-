#pragma once
#include"LinkList.h"
#include<vector>
#include<queue>
using namespace std;
class TestNode {
public:
	TestNode(int a) :val(a), next(nullptr) {};
	TestNode(vector<int> arr):TestNode(arr[0]) {
		next = new TestNode(arr[1]);
		TestNode* p = next;
		for (int i = 2; i < arr.size(); i++)
		{
			p->next = new TestNode(arr[i]);
			p = p->next;
		}
	}
	int val;
	TestNode* next;
	bool operator <(const TestNode* node)const {
		return this->val < node->val;
	}

};

struct myLess{
	bool operator()(TestNode* a, TestNode* b) {
		return a->val > b->val;
	}
};
class NodeHeap {
public:
	priority_queue<TestNode*, vector<TestNode*>, myLess> heap;
	TestNode* head;
	NodeHeap(TestNode* _head):head(_head) {
		TestNode* p = head;
		while (p) {
			heap.push(p);
			p = p->next;
		}
	}
	void updateSrc(int idx, int _val) {
		TestNode* p = head;
		for (int i = 0; i < idx; i++)
			p = p->next;
		p->val = _val;
	}
};
class Heap
{
public:
	static void GetTopK(int arr[], int len, int k);
	static void GetTopK1(int arr[], int len, int k);
	static void MergeKSortedList(LinkList head[], int k);//use stl linklist
	static void MergeKSortedList1(LinkList head[], int k);//use my linklist
	static void testObjctHeap(TestNode* head);
	static void updateHeap(vector<int> src,int idx,int newVal);
};

