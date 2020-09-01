#pragma once

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

#define INF 0x7FFFFFFF
#define NodeNum 5
enum class Color :int {
	WHITE = -1,
	GRAY = 0,
	BLACK = 1
};
class NeighborNode {
public:
	NeighborNode(const int n) :num(n),neighbor(nullptr) {}
	int num;
	int eLen;//dist to pre node,different value in different Adj[i]'s neighbor
	NeighborNode* neighbor;
};

class GraphNode:public NeighborNode {
public:
	GraphNode(const int& n):NeighborNode(n), color(Color::WHITE),dist(0),pre(nullptr),grayTime(0),
	blackTime(0),pathNum(0){};
	Color color;//-1:white not be found,0 gray found but not all neighbors are found,1 black found and all neighbors are found
	int dist;//distand to root
	GraphNode* pre;
	int grayTime;
	int blackTime;
	void clearGraphStatment();
	void printPreNode();
	void printNodeName();
	void printNodeColor();
	void printGrayTime();
	void printBlackTime();
	string getColor();
	bool operator<(const GraphNode*& node)const {
		return this->dist < node->dist;
	}

	int pathNum;//for algorithm getPathNum1,pathNum(end) =1,others = 0 as init
};

struct myGreater {
	bool operator()(GraphNode* a, GraphNode* b){
		return a->dist > b->dist;
	}
};

class Graph
{
public:
	int nodeNum;//size
	Graph(int adjM[NodeNum][NodeNum]);
	Graph();
	Graph(Graph* gr);
	GraphNode* Adj[NodeNum];
	int AdjMatrix[NodeNum][NodeNum];

	void printGraph();

	//1,reverse the directed graph
	Graph* revDirectedGraph();

	//2,BFS
	void BFS(int nodeIdx);

	//3,DFS
	void DFS();

	//4,topologic sort
	deque<GraphNode*> topologicSortList;

	//5,getPathNum p->v
	int getPathNum(GraphNode* strt, GraphNode* end);//1,topologic sort to reduce size;2,f(a) = sum(f(a.adj))
	int getPathNum1(GraphNode* strt, GraphNode* end);

	//6,strong connected conponents
	void getStrongConectedConponents();

	//7,dijkstra shorted pass
	void dijkstra(int nodeNum);

private:
	void printColor();
	void printPreNode();
	void dfsVisit(GraphNode* node);
	void dfsVisitForSCC(GraphNode* node);
	void printTopologicList();
	void helpDfs(GraphNode* strt, GraphNode* end, deque<GraphNode*> &tpl);//help for No.5
	void helpDfs1(GraphNode* strt, GraphNode* end);
	int helpGetPathNum(GraphNode* strt, GraphNode* end, deque<GraphNode*>& tpl);
	void clearGraphSt();
	int tick;
	void initSingleSource(int nodeIdx);

};

//leetcode542 ,
class MetrixNode {
public:
	MetrixNode() :val(0), color(Color::WHITE),  dist2Zero(0),l(0),c(0) {}
	bool val;
	int dist2Zero;
	Color color;
	int l;
	int c;
};
class MetrixGraph {
public:
	MetrixGraph(const int& l, const int& c, const vector<vector<int>>& met);
	void print();
private:
	int line;
	int column;
	vector<vector<MetrixNode*>> metGraph;
};




