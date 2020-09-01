#include "TreeNode.h"
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

BTreeNode::BTreeNode(int arr[], int len):left(nullptr),right(nullptr)
{
	val = arr[0];
	for (int i = 1; i < len; i++)
	{
		insertNode(this, arr[i]);
	}
}

BTreeNode* BTreeNode::insertNode(BTreeNode* node,int val)
{
	if (!node)
		return new BTreeNode(val);
	

	if (val < node->val)
		if (node->left)
			insertNode(node->left, val);
		else
			node->left = insertNode(node->left, val);
		
	else
		if(node->right)
			insertNode(node->right, val);
		else
			node->right = insertNode(node->right,val);

}


void BTreeNode::preorderTraversal( vector<int>& outpV)
{
	outpV.push_back(val);
	if (left)
		left->preorderTraversal(outpV);
	if (right)
		right->preorderTraversal(outpV);
}

void BTreeNode::postorderTraversal( vector<int>& outpV)
{
	if (left)
		left->postorderTraversal(outpV);
	if (right)
		right->postorderTraversal(outpV);
	outpV.push_back(val);
}

void BTreeNode::inorderTraversal(vector<int>& outpV)
{
	if(left)
		left->inorderTraversal( outpV);
	outpV.push_back(val);
	if(right)
		right->inorderTraversal( outpV);
	
}

void BTreeNode::Bfs(vector<int>& outpV)
{
	queue<BTreeNode*> nodeQ;
	nodeQ.push(this);
	while (!nodeQ.empty()) {
		BTreeNode* node = nodeQ.front();
		nodeQ.pop();
		outpV.push_back(node->val);
		if (node->left)
			nodeQ.push(node->left);
		if (node->right)
			nodeQ.push(node->right);
	}
}

int BTreeNode::getDepthOfTree()
{
	if (!left && !right) return 1;
	int leftDep = 0;
	int rightDep = 0;
	if (left)
		leftDep = left->getDepthOfTree() + 1;
	if (right)
		rightDep = right->getDepthOfTree() + 1;
	return leftDep>rightDep?leftDep:rightDep;
}

int BTreeNode::getMaxPathSum()
{
	/*
	* 如果:
	*节点A是路径的最浅公共父节点，
	*max(A)为经过最浅父节点的最大路径和,maxChild(A)为A的最大孩子路径和
	* 则max(A) = MAX{A,A+maxChild(A->left),A+maxChild(A->right),A+maxChild(A->left)+maxChild(A->right)};
	* maxChild(n) = MAX(n,n+maxChild(n->left),n+maxChild(n->right))
	*/
	int res = 0;
	//for each node in the tree ,if(res<maxParentPathSum(node)) res = maxParentPathSum(node).bfs or dfs
	dfsHelp(this, res);

	return res;
}


int BTreeNode::maxParentPathSum()
{//pNode!=null
	int le = left ? left->maxChildPathSum() : 0;
	int ri = right ? right->maxChildPathSum() : 0;
	return max({ val,val + le,val + ri,val + le + ri });
}

int BTreeNode::maxChildPathSum()
{
	int le = left ? left->maxChildPathSum() : 0;
	int ri = right ? right->maxChildPathSum() : 0;
	return max({ val,val+le,val+ri });
}

void BTreeNode::dfsHelp(BTreeNode* pNode, int& maxRes)
{
	int res = pNode->maxParentPathSum();
	if (res > maxRes)
		maxRes = res;
	if (pNode->left)
		dfsHelp(pNode->left, maxRes);
	if (pNode->right)
		dfsHelp(pNode->right, maxRes);
}
