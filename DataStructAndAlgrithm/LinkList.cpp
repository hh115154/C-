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
    while (ds != nullptr && ds->next != nullptr)
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

    while (p2 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    cout << p1->val << endl;
}

Node* LinkList::copyLinkList()
{
    if (!head)
        return nullptr;
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

Node::Node(const Node& node):val(node.val),next(node.next)
{

}
