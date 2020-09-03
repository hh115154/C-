#include "Graph.h"
#include<set>
#include<queue>
#include<cstring>



Graph::Graph( int adjM[NodeNum][NodeNum]) :nodeNum(NodeNum)
{
	for (int i = 0; i < nodeNum; i++)
	{
		Adj[i] = new GraphNode(i + 1);
		Adj[i]->neighbor = new NeighborNode(INF);
		NeighborNode* curr = Adj[i]->neighbor;
		for (int j = 0; j < nodeNum; j++)
		{
			AdjMatrix[i][j] = adjM[i][j];
			if (AdjMatrix[i][j]!=0 && INF!= AdjMatrix[i][j]) {
				if (Adj[i]->neighbor && INF == Adj[i]->neighbor->num) {//first neighbor
					Adj[i]->neighbor->num = j + 1;
				}
				else {
					curr->neighbor = new NeighborNode(j + 1);
					curr = curr->neighbor;
				}
				curr->eLen = AdjMatrix[i][j];
			}
		}
		if (INF == Adj[i]->neighbor->num)
			Adj[i]->neighbor = nullptr;
	}
	/*�߳���Ȩֵ
	* 	for (int i = 0; i < nodeNum; i++)
	{		
		Adj[i] = new GraphNode(i + 1);
		Adj[i]->neighbor = new NeighborNode(-1);
		NeighborNode* curr = Adj[i]->neighbor;
		for (int j = 0; j < nodeNum; j++)
		{
			AdjMatrix[i][j] = adjM[i][j];
			if (AdjMatrix[i][j]) {			
				if (Adj[i]->neighbor && -1 == Adj[i]->neighbor->num) {//first neighbor
					Adj[i]->neighbor->num = j + 1;
				}
				else {
					curr->neighbor = new NeighborNode(j + 1);
					curr = curr->neighbor;
				}
				
			}
		}
		if (-1 == Adj[i]->neighbor->num)
			Adj[i]->neighbor = nullptr;
	}
	*/

}

Graph::Graph() :nodeNum(NodeNum)
{
	for (int i = 0; i < nodeNum; i++)
	{
		Adj[i] = new GraphNode(i+1);
		for (int j = 0; j < nodeNum; j++) {
			AdjMatrix[i][j] = 0;
		}
	}
}

Graph::Graph(Graph*gr):nodeNum(gr->nodeNum)
{	
	for (int i = 0; i < nodeNum; i++)
	{		
		Adj[i] = new GraphNode(i + 1);
		NeighborNode* paraCurr = gr->Adj[i]->neighbor;
		NeighborNode* newCurr = nullptr;
		while (paraCurr) {
			newCurr = new NeighborNode(paraCurr->num);
			paraCurr = paraCurr->neighbor;
			newCurr = newCurr->neighbor;
		}		
	}

	memcpy(AdjMatrix, gr->AdjMatrix, sizeof(int) * nodeNum * nodeNum);

}

void GraphNode::clearGraphStatment()
{
	color = Color::WHITE;
	pre = nullptr;
	grayTime = 0;
	blackTime = 0;
}

void GraphNode::printPreNode()
{
	if (!pre)
		cout << "NULL";
	else
		cout << "V[" << pre->num << "]";
	cout << "<-";
	printNodeName();
	cout << endl;
}

void GraphNode::printNodeName()
{
	cout << "V[" << num << "]";
}

void GraphNode::printNodeColor()
{
	printNodeName();
	string strColor = getColor();
	cout << "s color is"<<strColor<<endl;
}

void GraphNode::printGrayTime()
{
	printNodeName();
	cout << "'s GrayTime is " << grayTime<<endl;
}

void GraphNode::printBlackTime()
{
	printNodeName();
	cout << "'s BlackTime is " << blackTime << endl;
}

string GraphNode::getColor()
{
	string str("");
	switch (color)
	{
	case Color::WHITE:
		str = "WHITE";
		break;
	case Color::GRAY:
		str = "GRAY";
		break;
	case Color::BLACK:
		str = "BLACK";
		break;
	default:
		break;
	}
	return str;
}

void Graph::printGraph()
{
	//print adjMatrix
	cout << "adjMatrix is:" << endl;
	for (int i = 0; i < nodeNum; i++)
	{
		for (int j = 0; j < nodeNum; j++)
			cout << AdjMatrix[i][j] << ", ";
		cout << endl;
	}
	//print Adj
	cout << "Adj is:" << endl;
	for (int i = 0; i < nodeNum; i++)
	{
		GraphNode* curr = Adj[i];
		cout << "[" << curr->num << "]->";//head
		NeighborNode* neiCurr = curr->neighbor;
		while (neiCurr) {
			cout << "[" << neiCurr->num << "]->";
			neiCurr = neiCurr->neighbor;
		}
		cout << "NULL" << endl;
	}
}

Graph* Graph::revDirectedGraph()
{
	Graph* revG = new Graph();
	
	//reverse adjMatriex
	for (int i = 0; i < nodeNum; i++)
		for (int j = 0; j < NodeNum; j++)
		{
			if (AdjMatrix[i][j]) {
				revG->AdjMatrix[i][j] = 0;
				revG->AdjMatrix[j][i] = 1;
			}
		}

	//reverse Adj
	NeighborNode* revCurr[NodeNum];
	for (int i = 0; i < nodeNum; i++)
		revCurr[i] = nullptr;
		

	for (int i = 0; i < nodeNum; i++)
	{
		NeighborNode* curr = Adj[i]->neighbor;
		while (curr) {
			if (!revG->Adj[curr->num - 1]->neighbor)
			{
				revG->Adj[curr->num - 1]->neighbor = new NeighborNode(i+1);
				revCurr[curr->num - 1] = revG->Adj[curr->num - 1]->neighbor;
			}
			else {
				revCurr[curr->num - 1]->neighbor = new NeighborNode(i + 1);
				revCurr[curr->num - 1] = revCurr[curr->num - 1]->neighbor;
			}
			curr = curr->neighbor;
		}
	}

	return revG;
}

void Graph::BFS(int nodeIdx)
{
	//print bfs process
	cout << "BFS from V[" << nodeIdx << "]:" << endl;
	GraphNode* root = Adj[nodeIdx - 1];
	root->color = Color::GRAY;
	root->dist = 0;
	root->pre = nullptr;
	queue<GraphNode*> grayNodeQ;
	grayNodeQ.push(root);
	GraphNode*head = nullptr;
	NeighborNode* curr = nullptr;
	
	while (!grayNodeQ.empty()) {
		head = grayNodeQ.front();
		curr = head->neighbor;
		grayNodeQ.pop();
		while(curr){
			if (Adj[curr->num-1]->color == Color::WHITE)
			{
				Adj[curr->num - 1]->color = Color::GRAY;
				Adj[curr->num - 1]->dist = head->dist +1;
				Adj[curr->num - 1]->pre = head;
				//cout << "V[" <<head->num << "] <- V[" << Adj[curr->num - 1]->num << "]" << endl;

				grayNodeQ.push(Adj[curr->num - 1]);
			}
			curr = curr->neighbor;
		}
		if (head->color == Color::GRAY)
		{
			head->color = Color::BLACK;
			printColor();
		}
		
	}

	printPreNode();
}

void Graph::DFS()
{
	cout << "***************DFS begins***************************" << endl;
	for (int i = 0; i < nodeNum; i++)
		Adj[i]->clearGraphStatment();
	tick = 0;
	for (int i = 0; i < nodeNum; i++)
		if (Color::WHITE == Adj[i]->color)
			dfsVisit(Adj[i]);
	printTopologicList();
	cout << "***************DFS ends***************************" << endl;
}


void Graph::printColor()
{
	for (int i = 0; i < nodeNum; i++)
		cout << "V[" << i + 1 << "]'s color is" << (int)Adj[i]->color<<endl;
	cout << endl;
}

void Graph::printPreNode()
{
	for (int i = 0; i < nodeNum; i++)
		Adj[i]->printPreNode();
}

void Graph::dfsVisit(GraphNode* node)
{
	tick++;
	node->color = Color::GRAY;
	node->grayTime = tick;
	NeighborNode* curr = node->neighbor;
	while (curr) {
		if (Color::WHITE == Adj[curr->num - 1]->color)
		{
			Adj[curr->num - 1]->pre = node;
			dfsVisit(Adj[curr->num - 1]);
		}
		curr = curr->neighbor;
	}
	node->color = Color::BLACK;
	tick++;
	node->blackTime = tick;
	topologicSortList.push_front(node);

	node->printGrayTime();
	node->printBlackTime();
	node->printPreNode();
}
void Graph::dfsVisitForSCC(GraphNode* node)
{
	//tick++;
	node->color = Color::GRAY;
	//node->grayTime = tick;
	NeighborNode* curr = node->neighbor;
	while (curr) {
		if (Color::WHITE == Adj[curr->num - 1]->color)
		{
			Adj[curr->num - 1]->pre = node;
			dfsVisitForSCC(Adj[curr->num - 1]);
		}
		curr = curr->neighbor;
	}
	node->color = Color::BLACK;
	//tick++;
	//node->blackTime = tick;
	topologicSortList.push_front(node);

	//node->printGrayTime();
	//node->printBlackTime();
	//node->printPreNode();
}

void Graph::printTopologicList()
{
	cout << "TOPO sort list:" << endl;
	string str;
	for (deque<GraphNode*>::iterator itor = topologicSortList.begin();itor!=topologicSortList.end();++itor)
	{
		(*itor)->printNodeName();
		cout << "->";
	}
	cout << "NULL" << endl;
}


void Graph::helpDfs(GraphNode* strt, GraphNode* end, deque<GraphNode*>& tpl)
{
	if (strt->num == end->num)
	{
		tpl.push_front(end);
		return;
	}

	strt->color = Color::GRAY;
	NeighborNode* curr = strt->neighbor;
	while (curr) {
		if (Color::WHITE == Adj[curr->num - 1]->color)
		{
			if (curr->num == end->num)
			{
				Adj[curr->num - 1]->color = Color::BLACK;
				tpl.push_front(end);
			}
			else
				helpDfs(Adj[curr->num - 1],end,tpl);
		}
		curr = curr->neighbor;
	}

	strt->color = Color::BLACK;
	tpl.push_front(strt);
}

void Graph::helpDfs1(GraphNode* strt, GraphNode* end)
{
	if (strt->num == end->num) {
		strt->color = Color::BLACK;
		return;
	}

	strt->color = Color::GRAY;

	NeighborNode* curr = strt->neighbor;
	while (curr) {
		if (Color::WHITE == Adj[curr->num - 1]->color)
			helpDfs1(Adj[curr->num-1],end);
		strt->pathNum += Adj[curr->num - 1]->pathNum;
		curr = curr->neighbor;
	}
	strt->color = Color::BLACK;
}

int Graph::getPathNum(GraphNode* strt, GraphNode* end)
{
	for (int i = 0; i < nodeNum; i++)
		Adj[i]->clearGraphStatment();
	tick = 0;

	deque<GraphNode*> tplList;
	int pathNum = 0;
	helpDfs(strt, end, tplList);

	pathNum = helpGetPathNum(strt,end, tplList);

	return pathNum;
}

int Graph::getPathNum1(GraphNode* strt, GraphNode* end)
{
	/*����㸽��һ����������time����ʼ�� t.time = 1��
	������ time ��Ϊ 0 ���� s ΪԴ������ DFS��
	һ�������� t���� t �����ź�ɫ�������������� t �ĺ������
	ÿ������һ��������������ý��� time ���� = �ý����ָ������н��� time ֮�͡�
	��� s.time ��·��������*/
	for (int i = 0; i < nodeNum; i++)
	{
		Adj[i]->color = Color::WHITE;
		if (Adj[i]->num == end->num)
			Adj[i]->pathNum = 1;
		else
			Adj[i]->pathNum = 0;
	}

	helpDfs1(strt, end);
	
	return strt->pathNum;
}

void Graph::getStrongConectedConponents()
{
	/*
	* 1,dfs to get the topologic sort result
	* 2,get (G)T,transposition of the graph
	* 3,dfs (G)T as the sequence of topologic,
	* 4,each tree is a strong connected conponent
	*/
	clearGraphSt();

	DFS();
	Graph* GT = revDirectedGraph();
	GT->clearGraphSt();

	int pos = 0;
	for (int i = 0; i < nodeNum; i++) {
		if (Color::WHITE == GT->Adj[topologicSortList[i]->num - 1]->color) {
			GT->dfsVisitForSCC(GT->Adj[topologicSortList[i]->num - 1]);
			//print subTree
			for (int j = 0; j < GT->topologicSortList.size() - pos; j++)
			{
				GT->topologicSortList[j]->printNodeName();
				cout << ",";
			}
			pos = GT->topologicSortList.size();
			cout << endl;
		}
	}


}

void Graph::dijkstra(int nodeIdx)
{
	initSingleSource(nodeIdx);
	vector<GraphNode*> newGraph;//only black nodes
	priority_queue<GraphNode*, vector<GraphNode*>, myGreater> minHeap;//only gray nodes
	Adj[nodeIdx]->color = Color::GRAY;
	minHeap.push(Adj[nodeIdx]);

	while (!minHeap.empty()) {
		GraphNode* minNode = minHeap.top();
		minHeap.pop();
		newGraph.push_back(minNode);
		minNode->color = Color::BLACK;
		
 		NeighborNode* nb = minNode->neighbor;
		while (nb) {
			//nb.relaxation start
			if (Adj[nb->num-1]->dist>minNode->dist+nb->eLen)
			{
				Adj[nb->num-1]->dist = minNode->dist + nb->eLen;
				Adj[nb->num-1]->pre = minNode;
				if (Color::WHITE ==Adj[nb->num-1]->color)
				{
					minHeap.push(Adj[nb->num - 1]);
					Adj[nb->num - 1]->color = Color::GRAY;//ʹ����ɫ���ƣ���֤ÿ���ڵ�ֻ���һ��
				}		
			}
			//nb.relaxation end
			nb = nb->neighbor;
		}
	}

	for (int i = 0; i < nodeNum; i++)
		cout << "V[" << i + 1 << "]'s dist is" << Adj[i]->dist << endl;
}

int Graph::helpGetPathNum(GraphNode* strt, GraphNode* end, deque<GraphNode*>& tpl)
{
	if (strt->num == end->num)
		return 1;

	int res = 0;
	NeighborNode* curr = strt->neighbor;
	while (curr)
	{
		if (Adj[curr->num-1]->color == Color::BLACK)
			res += helpGetPathNum(Adj[curr->num - 1],end, tpl);		
		curr = curr->neighbor;
	}
	return res;
}

void Graph::clearGraphSt()
{
	for (int i = 0; i < nodeNum; i++)
		Adj[i]->clearGraphStatment();
	tick = 0;
	topologicSortList.clear();
}

void Graph::initSingleSource(int nodeIdx)
{
	for (int i = 0; i < nodeNum; i++)
	{
		if (i == nodeIdx)
			Adj[i]->dist = 0;
		else
			Adj[i]->dist = INF;//infinity
		Adj[i]->pre = nullptr;
	}
}



MetrixGraph::MetrixGraph(const int& l, const int& c, const vector<vector<int>>& met) :line(l), column(c) {
/*
* leetcode542
* �㷨������01������ÿ���ڵ����������������Ҿ���1�����ÿ��1�ڵ������0�ڵ����̾���
* 1.init each 0 as color of gray and push into queue
* 2.BFS the metrix graph,each layer distance++
*/

	metGraph.resize(l, vector<MetrixNode*>(c, nullptr));//vector ��ʼ��
	deque< MetrixNode*> que;

	for (int i = 0; i < l; i++)
		for (int j = 0; j < c; j++)
		{
			metGraph[i][j] = new MetrixNode();
			metGraph[i][j]->val = met[i][j];
			metGraph[i][j]->l = i;
			metGraph[i][j]->c = j;
			if (!metGraph[i][j]->val) {
				metGraph[i][j]->color = Color::GRAY;
				que.push_back(metGraph[i][j]);
			}
				
		}
	MetrixNode* curr = nullptr;
	while(!que.empty()){
		curr= que.front();
		que.pop_front();
		if (curr->l > 0 && Color::WHITE == metGraph[curr->l - 1][curr->c]->color) {
			metGraph[curr->l - 1][curr->c]->color = Color::GRAY;
			metGraph[curr->l - 1][curr->c]->dist2Zero = curr->dist2Zero + 1;
			que.push_back(metGraph[curr->l - 1][curr->c]);
		}
		if (curr->c > 0 && Color::WHITE == metGraph[curr->l][curr->c-1]->color) {
			metGraph[curr->l][curr->c-1]->color = Color::GRAY;
			metGraph[curr->l][curr->c-1]->dist2Zero = curr->dist2Zero + 1;
			que.push_back(metGraph[curr->l][curr->c-1]);
		}
		if (curr->l + 1 < line  && Color::WHITE == metGraph[curr->l + 1][curr->c]->color) {
			metGraph[curr->l + 1][curr->c]->color = Color::GRAY;
			metGraph[curr->l + 1][curr->c]->dist2Zero = curr->dist2Zero + 1;
			que.push_back(metGraph[curr->l + 1][curr->c]);
		}
		if (curr->c + 1 < column && Color::WHITE == metGraph[curr->l][curr->c+1]->color) {
			metGraph[curr->l][curr->c+1]->color = Color::GRAY;
			metGraph[curr->l][curr->c+1]->dist2Zero = curr->dist2Zero + 1;
			que.push_back(metGraph[curr->l][curr->c+1]);
		}
		curr->color = Color::BLACK;
	}
	
}

void MetrixGraph::print()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << metGraph[i][j]->dist2Zero << " ";
		}
		cout << endl;
	}
}


