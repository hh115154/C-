#pragma once
#include <string>
#include <vector>
using namespace std;

/*���ַ�����������Ӵ�*/
//����ɨ��
string longestCommonPrefix(vector<string>& strVector);
//����ɨ��
string longestCommonPrefix_1(vector<string>& strVector);
//����
string longestCommonPrefix_2(vector<string>& strVector);
string CommonPrefix(string str1, string str2);
string CommonPrefix(vector<string>& strVector, int i, int j);
//����
string longestCommonPrefix_3(vector<string>& strs);
bool isCommonPrefix(const vector<string>& strs, int length);


//NC31 ��һ��ֻ����һ�ε��ַ�
int FirstNotRepeatingChar(string str);
int FirstNotRepeatingChar_hashmap(string str);
int FirstNotRepeatingChar_array(string str);
int FirstNotRepeatingChar_bitset(string str);

//NC114 ��ת�ַ���
bool solve(string A, string B);
bool solve_1(string A, string B);

//KMP�㷨
class KMP
{
private:
	int** dp;// dp[״̬][�ַ�] = �¸�״̬
	string pat;//ƥ�䴮
public:
	KMP(string pat);
	int search(string txt);//�����ַ���������ƥ��
	~KMP();
};