#pragma once
#include<vector>
#include<algorithm>
using namespace std;

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

	//algrithm 1,�м�ڵ�
	void GetMidNode();
	
	//algrithn 2,������K���ڵ�
	void GetLastKthNode(int k);

	//algrithm 3,����������
	Node* copyLinkList();


	Node* head;

};


//Array
class Leetcode11{//container with most water
	public:
	int getMaxArea(vector<int> arr){
		int i = 0;
		int k = arr.size()-1;
		int res = 0;
		while(i<k){
			res = max(res,(k-i)*min(arr[i],arr[k]));
			i<k?i++:k--;
		}
		return res;
	}
};

class Leetcode42{
	public:
	int getRain(vector<int> arr)
	{
		int l = 0;
		int r = arr.size()-1;
		int lmax = l;
		int rmax = r;
		int res = 0;
		//1，处理短边一侧，因此不会出现单向斜面不存水的问题
		//2，两侧都记录一个最长边
		//3,两侧各自求最长边和当前边之间的雨量，
		while(l<r){
			if(arr[l]<arr[r]){
				arr[l]>=arr[lmax]?lmax=l:res+=arr[lmax]-arr[l];
				l++;
			}else{
				arr[r]>=arr[rmax]?rmax=r:res+=arr[rmax]-arr[r];
				r--;
			}
		}
		return res;
	}
};
 
class Leetcode283{
	public:
	static void movezeros(vector<int>& arr){
		int firstZero = 0;
		int firstNum = 0;
		while(firstNum<arr.size()&&firstZero<arr.size()){
			while (0!=arr[firstZero]&&firstZero<arr.size())
				firstZero++;
			while (0==arr[firstNum]&&firstNum<arr.size())
				firstNum++;
			if(firstNum>firstZero&&firstNum<arr.size()&&firstZero<arr.size())
				swap(arr[firstZero],arr[firstNum]);		
		}
	}
};

class Leetcode80{
	public:
	static int removeDuplicates(vector<int>& arr){
		int len = arr.size();
		int le = 0,ri =0;
		int m = 2;
		if (len<2) return  len;
		while(ri<len){
			//remove
			while(arr[ri] == arr[le]){
				if(ri-le<m)
					ri++;
				if (ri == len)
					break;
				if (ri-le == m &&arr[ri] == arr[le])
				{
					for(int i = ri;i<len-1;i++)
						arr[i] = arr[i+1];
					len--;
				}
					
			}
			//new num
			le = ri;
		}
		return len;
	}
};