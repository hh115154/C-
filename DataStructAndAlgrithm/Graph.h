#pragma once

#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<map>

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
//8, leetcode 133,clone noneDirected Graph
class TmpNode{
public:
	int val;
	vector<TmpNode*> neibors;
	TmpNode():val(0),neibors(vector<TmpNode*>()){}
	TmpNode(int _v):val(_v),neibors(vector<TmpNode*>()){}
	TmpNode(int _v,vector<TmpNode*> _nei):val(_v),neibors(_nei){}

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

	//8, leetcode 133,clone noneDirected Graph
	TmpNode* cloneGraph(TmpNode* node);
	

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
	// TmpNode* cloneGraphHelp(TmpNode* node,set<TmpNode*>& nodeSet);
	TmpNode* cloneGraphHelp(TmpNode*node,map<TmpNode*,TmpNode*>& inp2outp );
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

class LeetCode399{
	public:
	vector<pair<string,string>> equitions;
	vector<double> values;
	map<string,map<string,double>> graph;
	LeetCode399(const vector<pair<string,string>>& _eq,const vector<double> _val):equitions(_eq),values(_val){
		int i = 0;
		for(vector<pair<string,string>>::iterator iterEq = equitions.begin();iterEq!= equitions.end();iterEq++){
           graph[iterEq->first][iterEq->second] = values[i];
		   graph[iterEq->second][iterEq->first] = values[i]?1/values[i]:0;
		   i++;
		}
	}
	double dfs(string src,string dest,set<string>& visited){
		if(!graph.count(src)) return -1;
		if(src == dest) return 1;
		double res = -1.0;
		visited.insert(src);//标记已经访问的节点
		map<string,double> tmp = graph[src];//降维
		if(tmp.count(dest)) 
			return tmp[dest];
		else
		{
			for(map<string,double>::iterator iter = tmp.begin();iter!=tmp.end();iter++){
				if(visited.count(iter->first))
					continue;
				else{

				}
					res = graph[src][iter->first]*dfs(iter->first,dest,visited);//拆分任务
					if(res<0)
						res= -1;
			}
		}
		return res;
	}
	vector<double> queries(vector<pair<string,string>> qu ){
		/*
		*for each query.first,dfs graph to search query.second,
		*/
		vector<double> res;
		double tmp;
		set<string> bVis;
		for (vector<pair<string,string>>::iterator iter = qu.begin();iter!=qu.end();iter++)
		{
			tmp = dfs(iter->first,iter->second,bVis);
			res.push_back(tmp);
			bVis.clear();
		}
		
		return res;
	}
};

class LeetCode785 {//是否图可以只着两种颜色，不同颜色不邻接
private:
	bool dfs(Color preColor,int currIdx,vector<vector<int>>& graph,vector<Color>& colors){
		if(Color::WHITE == colors[currIdx]) 
			if(preColor ==Color::GRAY)
				colors[currIdx] = Color::BLACK;
			else
				colors[currIdx] = Color::GRAY;
		else
			return preColor != colors[currIdx];
		
		bool res = true;
		vector<int> adj = graph[currIdx];
		for (int i = 0; i < adj.size(); i++)
		{
			res = dfs(colors[currIdx],adj[i],graph,colors);
			if(!res) return res;
		}
		
		return res;
	}
public:	
    bool isBipartite(vector<vector<int>>& graph) {
		//color the nodes as gray and black
		bool res = true;
		vector<Color> nodeColor(graph.size(),Color::WHITE);
		res = dfs(Color::BLACK,0,graph,nodeColor);
		return res;
    }
};

class Leetcode841{//keys and rooms
private:
	void dfs(vector<vector<int>>& rooms,int currIdx,set<int>& avlbKeys,set<int>& vstdRooms){
		vstdRooms.insert(currIdx);
		//add new keys and visit new rooms
		vector<int> newKeys = rooms[currIdx];
		for (int i = 0; i < newKeys.size(); i++)
			avlbKeys.insert(newKeys[i]);
		//visit new rooms
		bool res = true;
		for(int i = 0;i<newKeys.size();i++)
			if(!vstdRooms.count(newKeys[i]))
				dfs(rooms,newKeys[i],avlbKeys,vstdRooms);

	}
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms){
		set<int> avalibleKeys;		
		set<int> visitedRooms{};
		dfs(rooms,0,avalibleKeys,visitedRooms);
		bool res = visitedRooms.size() == rooms.size();
		return res;
	}




};



