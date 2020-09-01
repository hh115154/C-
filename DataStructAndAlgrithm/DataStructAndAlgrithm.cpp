﻿// DataStructAndAlgrithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<array>
#include<vector>
#include"Sort.h"
#include"LinkList.h"
#include"Stack.h"
#include"Heap.h"
#include"HashMap.h"
#include"TreeNode.h"
#include"Graph.h"
#include<algorithm>

using namespace std;
int main()
{
    int len = 10;
    int arr[] = { -87,34,-6,-18,-75,9,19,-30,129,-6 };
    sort(arr, arr+len);

    //********sort***********
    //Sort* sort = new QuickSort();
    Sort* sort = new MergeSort();
    sort->sort(arr, len);
    //delete sort;

    //********LinkList**********
    LinkList* list = new LinkList(arr, len);
    //list->GetMidNode();
    //list->GetLastKthNode(2);
    //list->GetLastKthNode(3);
    //Node* newList = list->copyLinkList();

    //********Stack************
    //Stack::DailayTemperater(arr, len);
    //Stack::AsteroidCrash(arr, len);

    //********Heap*************
    int k = 5;
    ////case1
    //Heap::GetTopK(arr, len, k);
    //Heap::GetTopK1(arr, len, k);

    ////case2
    //int arr1[] = { 3,6,20,30,31 };
    //int arr2[] = {1,4,7,10};
    //int arr3[] = {2,5,8};

    //LinkList l1 = LinkList(arr1, 5);
    //LinkList l2 = LinkList(arr2, 4);
    //LinkList l3 = LinkList(arr3, 3);
    //LinkList list[3] ;
    //list[0] = l1;
    //list[1] = l2;
    //list[2] = l3;
    //Heap::MergeKSortedList(list, 3);
    //Heap::MergeKSortedList1(list, 3);
    vector<int> vec = { 87,34,-6,-18,-75,9,19,-30,129,-6 };
    TestNode* head = new TestNode(vec);
    NodeHeap nHeap(head);
    nHeap.updateSrc(4, 100);//cannot update the sequence of heap

    //hash_map
    //case1
    //HashMap::towSum(arr, len, 28);

    //case2
    //HashMap::subarraySum(arr, len, 28);

    //case3.1
    //NewNode* testList = new NewNode(arr,len);
    //NewNode* copy1 = HashMap::deepCopy(testList);
    //NewNode* copy2 = HashMap::deepCopyListRecursion(testList);

    //NewNode* t1 = testList;
    //NewNode* t2 = copy1;
    //NewNode* t3 = copy2;

    //for (int i = 0; i < len; i++)
    //{
    //    t1->printOut();
    //    t2->printOut();
    //    t3->printOut();
    //    t1 = t1->next;
    //    t2 = t2->next;
    //    t3 = t3->next;
    //}


    //binary tree
    BTreeNode* bTreeNode =new BTreeNode(arr, len);
    
    //leetCode 124,maxPathSum
    int maxPathSum = bTreeNode->getMaxPathSum();


 //   vector<int> ivct;
 //   bTreeNode->preorderTraversal(ivct);
	////print
 //   cout.setf(ios::right);
 //   cout.width(20);
 //   cout << "preorderTraversal: ";
	//for (vector<int>::iterator i = ivct.begin(); i != ivct.end(); ++i) {
	//	cout << *i << " ";
	//}
	//cout << endl;

 //   ivct.clear();
 //   bTreeNode->postorderTraversal(ivct);
 //   //print
 //   cout.setf(ios::right);
 //   cout.width(20);
 //   cout << "postorderTraversal: ";
 //   for (vector<int>::iterator i = ivct.begin(); i != ivct.end(); ++i) {
 //       cout << *i << " ";
 //   }
 //   cout << endl;

 //   ivct.clear();
 //   bTreeNode->inorderTraversal(ivct);
 //   //print
 //   cout.setf(ios::right);
 //   cout.width(20);
 //   cout << "inorderTraversal: ";
 //   for (vector<int>::iterator i = ivct.begin(); i != ivct.end(); ++i) {
 //       cout << *i << " ";
 //   }
 //   cout << endl;

 //   ivct.clear();
 //   bTreeNode->Bfs(ivct);
 //   cout.setf(ios::right);
 //   cout.width(20);
 //   cout << "BFS: ";
 //   for (vector<int>::iterator i = ivct.begin(); i != ivct.end(); ++i) {
 //       cout << *i << " ";
 //   }
 //   cout << endl;

 //   int depth = bTreeNode->getDepthOfTree();
 //   cout << "depth of the tree is " << depth << endl;

    //Graph
    //int sampleMatix[NodeNum][NodeNum] = { {0,1,0,0,1,0,0,0,0,0,0,0,0,0},//图22-8
    //                                      {0,0,1,0,1,0,0,0,1,0,0,0,0,0},
    //                                      {0,0,0,0,0,1,1,0,0,1,0,0,0,0},
    //                                      {0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    //                                      {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,1,0,0,0,1,0},
    //                                      {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,1,0,0,0,0,0,0}, 
    //                                      {0,0,0,0,0,0,0,0,0,0,1,1,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //                                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    //                                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, };

//int sampleMatix[NodeNum][NodeNum] = { {0,0,1,1,0,0,1,0,0,0},//图22-6,q~z,means 1~10
//                                      {0,0,0,0,1,0,0,0,1,0},
//                                      {0,0,0,0,0,1,0,0,0,0},
//                                      {0,0,0,0,0,0,0,1,1,0},
//                                      {0,0,0,0,0,0,0,0,1,0},
//                                      {0,0,0,0,0,0,1,0,0,0},
//                                      {0,0,1,0,0,0,0,0,0,0},
//                                      {0,0,0,0,0,0,0,0,0,1},
//                                      {1,0,0,0,0,0,0,0,0,0},
//                                      {0,0,0,0,0,0,0,1,0,0}, };
//    Graph* gr = new Graph(sampleMatix);
//    gr->getStrongConectedConponents();
    
    //gr->printGraph();
    //int strt = 1, end = 10;
    //int pathN = gr->getPathNum(gr->Adj[strt], gr->Adj[end]);
    //int pathN1 = gr->getPathNum1(gr->Adj[strt], gr->Adj[end]);//faster
    //gr->BFS(3);
    //gr->DFS();
    //Graph* revGr = gr->revDirectedGraph();
    //revGr->printGraph();
    //revGr->BFS(3);

    //Graph* newGr = new Graph(*gr);
    //newGr->printGraph();
    //newGr->BFS(2);


    //vector metrix
    //int lNum = 10;
    //int column = 10;
    //vector<vector<bool>> metrix(lNum,vector<bool>(column));
    //for (int i = 0; i < 10; i++)
    //    for (int j = 0; j < 10; j++)
    //        metrix[i][j] = i % 2 == j % 2 ? true : false;
    //int v = 0;
    //for (int i = 0; i < 10; i++) {
    //    for (int j = 0; j < 10; j++) {
    //        if (metrix[i][j])
    //            v = 1;
    //        else
    //            v = 0;
    //        cout << v << " ";
    //    }
    //    cout << endl;
    //}


    vector<vector<int>> sampMet = { {0,0,0},
                                 {0,1,0},
                                 {1,1,1} };
    
    MetrixGraph* metG = new MetrixGraph(3, 3, sampMet);
    metG->print();
    int sampleMatix[NodeNum][NodeNum] = { {0,  10, 5,  INF,INF},
                                          {INF,0,  2,  1,  INF},
                                          {INF,3,  0,  1,  2},
                                          {INF,1,INF,0,  4},
                                          {7,  INF,INF,6,  0, } };
    Graph* gr = new Graph(sampleMatix);
    gr->dijkstra(0);




    


    
    


    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件