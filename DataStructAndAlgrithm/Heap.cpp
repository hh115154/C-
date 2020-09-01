#include "Heap.h"
#include<algorithm>
#include<iostream>
#include<queue>
#include<list>
using namespace std;
void Heap::GetTopK(int arr[], int len, int k)
{	
	priority_queue<int,vector<int>,greater<int>> minHeap;
	for (int i = 0; i < k; i++)
		minHeap.push(arr[i]);
	//make_heap(temp[0], temp[4],greater<int>());

	for (int i = k; i < len; i++)
	{
		if (arr[i] >= minHeap.top())
		{
			minHeap.push(arr[i]);
			minHeap.pop();
		}
	}

	cout << minHeap.top() << endl;

}

void Heap::GetTopK1(int arr[], int len, int k)
{
	vector<int> ivect(arr, arr + k );
	make_heap(ivect.begin(), ivect.end(), greater<int>());
	for (int i = k; i < len; i++)
	{
		if (arr[i] >= ivect[0])
		{
			ivect.push_back(arr[i]);
			push_heap(ivect.begin(), ivect.end(), greater<int>());

			pop_heap(ivect.begin(), ivect.end(), greater<int>());
			ivect.pop_back();
		}
	}

	cout << ivect[0] << endl;
}

void Heap::MergeKSortedList(LinkList head[], int k)
{
	priority_queue<Node,vector<Node>,greater<Node>> heap;

	for (int i = 0; i < k; i++)
		heap.push(*head[i].head);

	list<Node> resList;
	resList.push_back(heap.top());
	Node curr = heap.top();

	while (!heap.empty()) {
		Node top = heap.top();
		heap.pop();

		resList.push_back(top);
		curr.next = &top;
		curr = *curr.next;

		if (nullptr != curr.next) 	
			heap.push(*curr.next);

	}

	resList.pop_front();
	for (list<Node>::iterator iter = resList.begin(); iter!= resList.end();iter++)
	{
		cout << iter->val << " ";
	}
	cout << endl;
}

void Heap::MergeKSortedList1(LinkList head[], int k)
{
	priority_queue<Node, vector<Node>, greater<Node>> heap;
	for (int i = 0; i < k; i++)
		heap.push(*head[i].head);

	Node resHead = heap.top();
	Node* curr = &resHead;

	while (!heap.empty()) {
		Node* top = new Node(heap.top());
		heap.pop();

		curr->next = top;
		curr = curr->next;

		if (nullptr != curr->next)
			heap.push(*curr->next);
	}

	curr->next = nullptr;

	while (nullptr!=resHead.next)
	{
		cout << resHead.next->val << " ";
		resHead = *resHead.next;
	}
	cout << endl;

}

void Heap::testObjctHeap(TestNode* head)
{
	priority_queue<TestNode*, vector<TestNode*>, myLess> heap;
	TestNode* node = head;
	while (node) {
		heap.push(node);
		node = node->next;
	}
}

void Heap::updateHeap(vector<int> src, int idx, int newVal)
{
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0; i < src.size(); i++)
		heap.push(src[i]);
	

}



