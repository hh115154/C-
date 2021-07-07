#pragma once
#include <string>
#include <vector>
using namespace std;

/*求字符串的最长公共子串*/
//横向扫描
string longestCommonPrefix(vector<string>& strVector);
//纵向扫描
string longestCommonPrefix_1(vector<string>& strVector);
//分治
string longestCommonPrefix_2(vector<string>& strVector);
string CommonPrefix(string str1, string str2);
string CommonPrefix(vector<string>& strVector, int i, int j);
//二分
string longestCommonPrefix_3(vector<string>& strs);
bool isCommonPrefix(const vector<string>& strs, int length);


//NC31 第一个只出现一次的字符
int FirstNotRepeatingChar(string str);
int FirstNotRepeatingChar_hashmap(string str);
int FirstNotRepeatingChar_array(string str);
int FirstNotRepeatingChar_bitset(string str);

//NC114 旋转字符串
bool solve(string A, string B);
bool solve_1(string A, string B);

//KMP算法
class KMP
{
private:
	int** dp;// dp[状态][字符] = 下个状态
	string pat;//匹配串
public:
	KMP(string pat);
	int search(string txt);//给定字符串，进行匹配
	~KMP();
};