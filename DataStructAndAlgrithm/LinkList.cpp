#include "LinkList.h"
#include<iostream>
using namespace std;


LinkList::LinkList(int arr[],int len)
{    
    head = new Node(arr[0]);
    Node* c = head;
    for (size_t i = 1; i < len; i++)
    {
        Node* p = new Node(arr[i]);
        c->next = p;
        c = c->next;
    }
}

LinkList::~LinkList()
{
    //delete[] head;
}

void LinkList::GetMidNode()
{  
    Node* s = head;
    Node* ds = head;
    while (ds != NULL && ds->next != NULL)
    {
        s = s->next;
        ds = ds->next->next;
    }
    cout << s->val << endl;
}

void LinkList::GetLastKthNode(int k)
{
    Node* p1 = head;
    Node* p2 = head;
    for (int i = 0; i < k; i++)
        p2 = p2->next;

    while (p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    cout << p1->val << endl;
}


Node* LinkList::copyLinkList()
{
    if (!head)
        return NULL;
    Node* tmpHead = head;//keep original head
    Node* outpHead = new Node(head->val);
    Node* newCurr = outpHead;
    while (tmpHead->next) {
        Node* nextNode = new Node(tmpHead->next->val);
        newCurr->next = nextNode;
        newCurr = newCurr->next;
        tmpHead = tmpHead->next;
    }
    return outpHead;
}

//leetcode206,反转链表
Node* LinkList::ReverseList() 
{
    Node* p = NULL;
    Node* q = head;
    while (q != NULL)
    {
        Node* temp = q->next;
        q->next = p;

        p = q;
        q = temp;
    }

    return p;
}

//leetcode141，快慢指针
bool LinkList::HasCycle()
{
    Node* p1 = head;
    Node* p2 = head;
    while (p1 != NULL && p2 != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
        {//快慢指针相遇，则有环
            return true;
        }
    }
    return false;
}

//leetcode24，两两交换链表中的节点
Node* LinkList::swapPairs() 
{
    //创建哑结点 dummyHead，令 dummyHead.next = head。令 temp 表示当前到达的节点，初始时 temp = dummyHead。每次需要交换 temp 后面的两个节点。
    Node* dummyHead = new Node(0);
    dummyHead->next = head;
    Node* temp = dummyHead;
    while (temp->next != NULL && temp->next->next != NULL) 
    {
        Node* node1 = temp->next;
        Node* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead->next;
}
Node* LinkList::swapParis_Reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* newHead = head->next;
    head->next = swapParis_Reverse(newHead);
    newHead->next = head;

    return newHead;
}

Node::Node(const Node& node):val(node.val),next(node.next)
{

}
