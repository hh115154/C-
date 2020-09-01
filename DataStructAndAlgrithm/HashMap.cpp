#include<iostream>
#include<unordered_map>// not standard #include"HashMap.h"
#include<map>
#include<vector>
#include "HashMap.h"
#include<algorithm>
#include<random>

using namespace std;
typedef unordered_map<int, int> ValIdxMap;

void HashMap::towSum(int nums[], int len,int target)
{
	vector<int> outpArr[2];
	ValIdxMap hMap;
	for (int i = 0; i < len; i++)
	{
		if (hMap.find(target - nums[i]) != hMap.end())//
		{
			outpArr[0].push_back(i);
			outpArr[1].push_back(hMap[target - nums[i]]);
			//cout<< i <<" and "<< hMap[target - nums[i]]<<endl;
		}
		else {
			hMap.insert({ nums[i], i });
		}
	}

	for (int i = 0; i < outpArr[0].size(); i++)
	{
		cout << outpArr[0][i] << "and" << outpArr[1][i] << endl;
	}
	
}

void HashMap::subarraySum(int nums[], int len, int target)
{
	ValIdxMap hashMap;
	hashMap.insert({ 0,-1 });//否则从0号元素开始的某个序列不会被发现
	int numOfSums = 0;
	long sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += nums[i];
		if (hashMap.find(sum - target) != hashMap.end()) {
			//numOfSums++;
			numOfSums += hashMap.count(sum - target);
			cout << hashMap[sum - target]+1 << "to" << i << endl;
		}
		hashMap.insert({ sum, i });
	}
	cout << numOfSums << endl;
}

NewNode* recursion(NewNode* oldList, unordered_map<NewNode*, NewNode*>map) {
	if (!oldList) return nullptr;
	if (map.count(oldList)) return map[oldList];
	NewNode* newHead = new NewNode(oldList->val);
	NewNode* newCurr = newHead;
	map[oldList] = newHead;
	newCurr->next = recursion(oldList->next, map);
	newCurr->radom = recursion(oldList->radom, map);

	return newHead;
}

NewNode* HashMap::deepCopyListRecursion(NewNode* _head)
{
	unordered_map<NewNode*, NewNode*> old2New_map;
	return recursion(_head, old2New_map);
}

NewNode* HashMap::deepCopy(NewNode* oldHead)
{
	//一次遍历只复制val,next,并建立old到new的map
	if (!oldHead) return nullptr;
	NewNode* newHead  = new NewNode(oldHead->val);
	NewNode* newCurr = newHead;
	NewNode* oldCurr = oldHead->next;
	unordered_map<NewNode*, NewNode*> old2New_map;
	old2New_map[oldHead] = newHead;
	while (oldCurr) {
		NewNode* newNode = new NewNode(oldCurr->val);
		newCurr->next = newNode;
		old2New_map[oldCurr] = newNode;

		oldCurr = oldCurr->next;
		newCurr = newCurr->next;
	}
	oldCurr = oldHead;
	newCurr = newHead;
	while(oldCurr){
		newCurr->radom = old2New_map[oldCurr->radom];

		oldCurr = oldCurr->next;
		newCurr = newCurr->next;
	}

	return newHead;
}


NewNode::NewNode(int arr[], int len)
{
	//随机数构造器
	default_random_engine e;
	uniform_int_distribution<int> dis(0, len-1);

	unordered_map<int, int> mMap;
	int idx;

	//NewNode* resHead = new NewNode(arr[0]);
	this->val = arr[0];
	NewNode* resHead = this;
	
	NewNode* curr = resHead;
	for (int i = 0; i < len; i++)
	{
		//构造除random指针外的链表
		if (i) {
			NewNode* node = new NewNode(arr[i]);
			curr->next = node;
			curr = curr->next;
		}


		//产生区间内满员并不重复的随机序列
		do idx = dis(e);
		while (mMap.count(idx));
		mMap[idx] = i;

		//测试
		cout << idx << endl;
	}
	curr = resHead;
	int j = 0;
	
	unordered_map<int, int>::iterator itor = mMap.begin();
	while (curr) {
		NewNode* tmp = resHead;
		for (int i = 0; i < itor->first; i++)
		{
			tmp = tmp->next;
		}
		curr->radom = tmp;

		curr = curr->next;
		itor++;
	}

}

void NewNode::printOut()
{
	
	NewNode* curr = this;
	cout.setf(ios::right);
	cout.width(5);
	cout << curr->val<<" ";

	cout.setf(ios::right);
	cout.width(5);
	if (curr->next)
		cout << curr->next->val;
	else
		cout << "NULL";
	cout << " ";

	cout.setf(ios::right);
	cout.width(5);
	if (curr->radom)
		cout << curr->radom->val;
	else
		cout << "NULL";
	cout << " ";




	//cout << this << endl;
	//while (curr) {
	//	cout << curr->val << " " << curr->next << " " << curr->radom << " # "  ;
	//	curr = curr->next;
	//}

	cout << endl;
}
