#pragma once
#include<vector>

using namespace std;

class LayerTreeNode
{
	int val;
	LayerTreeNode* firstChild;
	LayerTreeNode* nextSibling;
};


class BTreeNode
{
public:
	BTreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {};	
	BTreeNode(int arr[], int len);
	int val;
	BTreeNode* left;
	BTreeNode* right;

	void preorderTraversal(vector<int>& outpV);
	void postorderTraversal(vector<int>& outpV);
	void inorderTraversal(vector<int>& outpV);

	void Bfs(vector<int>& outpV);

	int getDepthOfTree();

	int getMaxPathSum();//leetCode 124
private:
	BTreeNode* insertNode(BTreeNode* node, int val);

	//for leetCode124
	int maxParentPathSum();
	int maxChildPathSum();
	void dfsHelp(BTreeNode* pNode,int&maxRes);
};




