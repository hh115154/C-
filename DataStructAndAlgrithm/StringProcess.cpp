#include <string>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;

#include "StringProcess.h"
#include <algorithm>

/*1. NC55,leetcode14,字符串的最长公共前缀*/
//横向扫描
//时间复杂度：O(mn)，其中 mm 是字符串数组中的字符串的平均长度，nn 是字符串的数量。最坏情况下，字符串数组中的每个字符串的每个字符都会被比较一次。
//空间复杂度：O(1)。使用的额外空间复杂度为常数。
string longestCommonPrefix(vector<string>& strVector)
{
	if (!strVector.size()) return "";
	string prefix = strVector[0];
	int size = strVector.size();
	for (int index = 1; index < size; index++)
	{
		int length = min(prefix.size(), strVector[index].size());
		int i = 0;
		for (; i < length; i++)
		{
			if (prefix[i] != strVector[index][i])
				break;
		}
		prefix = prefix.substr(0, i);
		if (!prefix.size())
		{
			break;
		}
	}
	return prefix;
}
//纵向扫描
//时间复杂度：O(mn)，其中 mm 是字符串数组中的字符串的平均长度，nn 是字符串的数量。最坏情况下，字符串数组中的每个字符串的每个字符都会被比较一次。
//空间复杂度：O(1)。使用的额外空间复杂度为常数。
string longestCommonPrefix_1(vector<string>& strVector)
{
	if (!strVector.size()) return "";

	int len = strVector[0].size();
	for (int col = 0; col < len; col++)
	{
		char c = strVector[0][col];

		for (int index = 1; index < strVector.size(); index++)
		{
			if (col == strVector[index].size() || strVector[index][col] != c)
			{
				return strVector[index].substr(0, col);
			}
		}
	}
	return strVector[0];
}
//分治
//时间复杂度：O(mn)，其中m是字符串数组中的字符串的平均长度，n是字符串的数量。时间复杂度的递推式是 T(n)=2*T(n/2)+O(m),通过计算可得 T(n) = O(mn)T(n) = O(mn)。
//空间复杂度：O(mlogn)，其中 m是字符串数组中的字符串的平均长度，n是字符串的数量。空间复杂度主要取决于递归调用的层数，层数最大为logn，每层需要 m的空间存储返回结果。
string longestCommonPrefix_2(vector<string>& strVector)
{
	int size = strVector.size();
	if (size == 0) return "";
	
	return CommonPrefix(strVector, 0, size -1);
}
string CommonPrefix(vector<string>& strVector, int i, int j)
{
	string prefix = "";
	if (i >= j)
	{
		prefix = strVector[i];
	}
	//此分支可以直接合并到else分支中
	//else if(j == i + 1)
	//{
	//	prefix = CommonPrefix(strVector[i], strVector[j]);
	//}
	else
	{
		int mid = (i + j) / 2;
		string prefix1 = CommonPrefix(strVector, i, mid);
		string prefix2 = CommonPrefix(strVector, mid+1, j);
		prefix = CommonPrefix(prefix1, prefix2);
	}
	return prefix;
}

string CommonPrefix(string str1, string str2)
{
	string prefix = "";
	for (int index = 0; index < min(str1.size(), str2.size()); index++)
	{
		if (str1[index] == str2[index])
		{
			prefix += str1[index];
		}
		else
		{
			break;
		}
	}
	return prefix;
}
//二分查找
//时间复杂度：O(mnlogm)，其中 mm 是字符串数组中的字符串的最小长度，nn 是字符串的数量。二分查找的迭代执行次数是O(logm)，每次迭代最多需要比较 mn个字符，因此总时间复杂度是O(mnlogm)。
//空间复杂度：O(1)。使用的额外空间复杂度为常数。
	string longestCommonPrefix_3(vector<string>& strs) {
		if (!strs.size()) {
			return "";
		}
		int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size(); })->size();
		int low = 0, high = minLength;
		while (low < high) {
			int mid = (high - low + 1) / 2 + low;
			if (isCommonPrefix(strs, mid)) {
				low = mid;
			}
			else {
				high = mid - 1;
			}
		}
		return strs[0].substr(0, low);
	}

	bool isCommonPrefix(const vector<string>& strs, int length) {
		string str0 = strs[0].substr(0, length);
		int count = strs.size();
		for (int i = 1; i < count; ++i) {
			string str = strs[i];
			for (int j = 0; j < length; ++j) {
				if (str0[j] != str[j]) {
					return false;
				}
			}
		}
		return true;
	}

    /*2. NC31 第一个只出现一次的字符*/
	//自己做的，时间复杂度不行
	int FirstNotRepeatingChar(string str) 
	{
		int index = -1;
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			char ch = str[i];
			string strTemp = str.substr(0, i) + str.substr(i + 1, len - i - 1);
			int j = strTemp.find(ch);
			if (j >= 0)
			{
				continue;
			}
			else
			{
				index = i;
				break;
			}
		}
		return index;
	}

	//hashmap
	int FirstNotRepeatingChar_hashmap(string str)
	{
			unordered_map<char, int> mp;
			for (const char ch : str) {
				++mp[ch];
			}
			for (int i = 0; i < str.length(); ++i) {
				if (mp[str[i]] == 1) return i;
			}
			return -1;
	}

	//array
	int FirstNotRepeatingChar_array(string str) {
		int mp[128] = { 0 };
		for (const char ch : str) {
			++mp[ch];
		}
		for (int i = 0; i < str.length(); ++i) {
			if (mp[str[i]] == 1) return i;
		}
		return -1;
	}

	//bitset
	//具体过程：
	//初始化：bitset<128> b1表示只出现1次， b2表示出现2次以上
	//遍历字符串，第一次出现，b1[ch] = 1
	//如果第二次出现，b2[ch] = 1
	//最后，找出第一个b1[ch] == 1 && b2[ch] == 0的字符
	int FirstNotRepeatingChar_bitset(string str)
	{
		bitset<128> b1, b2;
		for (const char ch : str)
		{
			if (b1[ch] == 0 && b2[ch] == 0)
			{
				b1.set(ch, 1);
			}
			else if (b1[ch] != 0)
			{
				b1.set(ch, 0);
				b2.set(ch, 1);
			}
		}
		for (int index = 0; index < str.size(); index++)
		{
			if (b1[str[index]] == 1 && b2[str[index]] == 0)
			{
				return index;
			}
		}
		return -1;
	}

	/*3. NC89,字符串变形*/
	//描述
	//对于一个给定的字符串，我们需要在线性(也就是O(n))的时间里对它做一些变形。首先这个字符串中包含着一些空格，就像"Hello World"一样，然后我们要做的是把着个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。比如"Hello World"变形后就变成了"wORLD hELLO"。
	//输入描述：
	//给定一个字符串s以及它的长度n(1≤n≤500)
	//返回值描述：
	//请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。

	/*C#,使用string.split*/
	/*public string trans(string s, int n)
	{
		// write code here
		string strOutput = string.Empty;
		string[] strArray = s.Split(' ');
		for (int i = strArray.Length - 1; i >= 0; i--)
		{
			string strTemp = string.Empty;
			string str = strArray[i];
			for (int index = 0; index < str.Length; index++)
			{
				char ch = str[index];
				if (char.IsUpper(ch))
				{
					ch = char.ToLower(ch);
				}
				else if (char.IsLower(ch))
				{
					ch = char.ToUpper(ch);
				}
				strTemp += ch;
			}
			strOutput += strTemp;
			if (i > 0)
			{
				strOutput += ' ';
			}
		}
		return strOutput;
	}*/
	char trans(char ch)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			return ch - 'A' + 'a';
		}
		else
		{
			return ch - 'a' + 'A';
		}
	}

	//从后往前扫，如果遇到空格，说明从这个空格的位置到下一个空格之间是一个单词。
	//然后将单词的每个字母依次取出，取出的过程变化大小写。
	string trans(string s, int n) {
		int p = n - 1;
		string ans;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				for (int j = i + 1; j <= p; ++j) ans += trans(s[j]);
				ans += ' ';
				p = i - 1;
			}
		}
		for (int j = 0; j <= p; ++j) ans += trans(s[j]);
		return ans;
	}


	/*4. NC114 旋转字符串*/
	//字符串旋转:
	//给定两字符串A和B，如果能将A从中间某个位置分割为左右两部分字符串（都不为空串），并将左边的字符串移动到右边字符串后面组成新的字符串可以变为字符串B时返回true。
	//	例如：如果A = ‘youzan’，B = ‘zanyou’，A按‘you’‘zan’切割换位后得到‘zanyou’和B相同返回true。

	//自己的解法
	bool solve(string A, string B) 
	{
		// write code here
		if (A.length() != B.length()) return false;
		for (int index = 0; index < A.length(); index++)
		{
			string strTemp;
			strTemp = A.substr(index + 1, A.length() - index - 1);
			strTemp += A.substr(0, index + 1);
			if (strTemp == B)
			{
				return true;
			}
		}
		return false;
	}

	//巧妙解法
	bool solve_1(string A, string B) {
		// write code here
		/*如果字符串的长度都不相同就直接返回false
		如果长度相同，就让A字符串拼接自己然后在判断有没有B这个字符串
		*/
		if (A.size() == B.size()) {
			A += A;
			//string中find()返回值是字母在母串中的位置（下标记录），如果没有找到，
			//那么会返回一个特别的标记npos。（返回值可以看成是一个int型的数）
			if (A.find(B) != A.npos)
				return true;
		}
		return false;
	}

	/*5. KMP算法*/
	//https://zhuanlan.zhihu.com/p/83334559
	KMP::KMP(string pat) 
	{
		this->pat = pat;
		
		int M = pat.length();
		// dp[状态][字符] = 下个状态
		this->dp = new int* [M];
		for (int i = 0; i < M; i++)
		{
			this->dp[i] = new int[256];
			memset(dp[i], 0, 256 * sizeof(int));
		}
		// base case
		dp[0][pat[0]] = 1;
		// 影子状态 X 初始为 0
		int X = 0;
		// 构建状态转移图（稍改的更紧凑了）
		for (int j = 1; j < M; j++) {
			for (int c = 0; c < 256; c++)
				dp[j][c] = dp[X][c];
			dp[j][pat[j]] = j + 1;
			// 更新影子状态
			X = dp[X][pat[j]];
		}
	}

	int KMP::search(string txt) 
	{
		int M = pat.length();
		int N = txt.length();
		// pat 的初始态为 0
		int j = 0;
		for (int i = 0; i < N; i++) {
			// 计算 pat 的下一个状态
			j = dp[j][txt[i]];
			// 到达终止态，返回结果
			if (j == M) return i - M + 1;
		}
		// 没到达终止态，匹配失败
		return -1;
	}

	KMP::~KMP()
	{
		if (this->dp != NULL)
		{
			delete[] dp;
		}
	}