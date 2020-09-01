#pragma once


class NewNode{
public:
	NewNode(int _val): val(_val), next(nullptr), radom(nullptr) {};
	NewNode(int arr[],int len);
	int val;
	NewNode* next;
	NewNode* radom;
	void printOut();
};
class HashMap
{
public:
	static void towSum(int nums[],int len,int target);//sum of two nums in array ,equals target
	static void subarraySum(int nums[],int len,int target);//subarray sum equals target
	static NewNode* deepCopyListRecursion(NewNode* head);
	static NewNode* deepCopy(NewNode* oldHead);
};

