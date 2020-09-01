#pragma once


class Node {
public:
	Node() :val(0), next(nullptr) {};
	Node(int val) :val(val) ,next(nullptr){};
	Node(const Node& node);

	int val;
	Node* next;

	bool operator < (const Node& node)const {
		return this->val < node.val;
	}

	bool operator > (const Node& node)const {
		return this->val > node.val;
	}

};

class LinkList
{
public:
	LinkList(int arr[],int len);
	LinkList() { head = new Node(); };
	virtual ~LinkList();

	//algrithm 1,中间节点
	void GetMidNode();
	
	//algrithn 2,倒数第K个节点
	void GetLastKthNode(int k);

	//algrithm 3,简单链表复制
	Node* copyLinkList();


	Node* head;

};

