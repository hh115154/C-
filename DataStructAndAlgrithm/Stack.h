#pragma once
#include<vector>
#include<string>
using namespace std;

class Stack
{
public:
	//leetCode739,easy
	static void DailayTemperater(int arr[],int len);
	//leetCode735,easy
	static void AsteroidCrash(int arr[], int len);
	//leetcode42,hard
	static int getrain(vector<int>arr);
	//leetcode1047,easy
	static void removeDuplicates(string& str);
	//leetcode20,easy
	static bool isStrValid(const string& str);
	static bool isStrValid1(string s);
	static bool isStrValid2(string s);
	static bool isStrValid3(string str);
	//leetcode496,easy
	static vector<int> nextGreaterNum(vector<int>subset, vector<int>arr);
	//leetcode503,medium
	static vector<int> nextGreaterNum2(vector<int>arr);
	//leetcode394,medium
	static string decodeString(const string& str);
	//leetcode636,medium
	static vector<int> exclusiveTime(int n, vector<string>& logs);
	//leetcode84,hard
	static int largestRectangleArea(vector<int>& height);
};

