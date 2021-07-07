#include <string>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;

#include "StringProcess.h"
#include <algorithm>

/*1. NC55,leetcode14,�ַ����������ǰ׺*/
//����ɨ��
//ʱ�临�Ӷȣ�O(mn)������ mm ���ַ��������е��ַ�����ƽ�����ȣ�nn ���ַ����������������£��ַ��������е�ÿ���ַ�����ÿ���ַ����ᱻ�Ƚ�һ�Ρ�
//�ռ临�Ӷȣ�O(1)��ʹ�õĶ���ռ临�Ӷ�Ϊ������
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
//����ɨ��
//ʱ�临�Ӷȣ�O(mn)������ mm ���ַ��������е��ַ�����ƽ�����ȣ�nn ���ַ����������������£��ַ��������е�ÿ���ַ�����ÿ���ַ����ᱻ�Ƚ�һ�Ρ�
//�ռ临�Ӷȣ�O(1)��ʹ�õĶ���ռ临�Ӷ�Ϊ������
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
//����
//ʱ�临�Ӷȣ�O(mn)������m���ַ��������е��ַ�����ƽ�����ȣ�n���ַ�����������ʱ�临�Ӷȵĵ���ʽ�� T(n)=2*T(n/2)+O(m),ͨ������ɵ� T(n) = O(mn)T(n) = O(mn)��
//�ռ临�Ӷȣ�O(mlogn)������ m���ַ��������е��ַ�����ƽ�����ȣ�n���ַ������������ռ临�Ӷ���Ҫȡ���ڵݹ���õĲ������������Ϊlogn��ÿ����Ҫ m�Ŀռ�洢���ؽ����
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
	//�˷�֧����ֱ�Ӻϲ���else��֧��
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
//���ֲ���
//ʱ�临�Ӷȣ�O(mnlogm)������ mm ���ַ��������е��ַ�������С���ȣ�nn ���ַ��������������ֲ��ҵĵ���ִ�д�����O(logm)��ÿ�ε��������Ҫ�Ƚ� mn���ַ��������ʱ�临�Ӷ���O(mnlogm)��
//�ռ临�Ӷȣ�O(1)��ʹ�õĶ���ռ临�Ӷ�Ϊ������
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

    /*2. NC31 ��һ��ֻ����һ�ε��ַ�*/
	//�Լ����ģ�ʱ�临�ӶȲ���
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
	//������̣�
	//��ʼ����bitset<128> b1��ʾֻ����1�Σ� b2��ʾ����2������
	//�����ַ�������һ�γ��֣�b1[ch] = 1
	//����ڶ��γ��֣�b2[ch] = 1
	//����ҳ���һ��b1[ch] == 1 && b2[ch] == 0���ַ�
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

	/*3. NC89,�ַ�������*/
	//����
	//����һ���������ַ�����������Ҫ������(Ҳ����O(n))��ʱ���������һЩ���Ρ���������ַ����а�����һЩ�ո񣬾���"Hello World"һ����Ȼ������Ҫ�����ǰ��Ÿ��ַ������ɿո�����ĵ��ʷ���ͬʱ��תÿ���ַ��Ĵ�Сд������"Hello World"���κ�ͱ����"wORLD hELLO"��
	//����������
	//����һ���ַ���s�Լ����ĳ���n(1��n��500)
	//����ֵ������
	//�뷵�ر��κ���ַ�������Ŀ��֤�������ַ������ɴ�Сд��ĸ�Ϳո񹹳ɡ�

	/*C#,ʹ��string.split*/
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

	//�Ӻ���ǰɨ����������ո�˵��������ո��λ�õ���һ���ո�֮����һ�����ʡ�
	//Ȼ�󽫵��ʵ�ÿ����ĸ����ȡ����ȡ���Ĺ��̱仯��Сд��
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


	/*4. NC114 ��ת�ַ���*/
	//�ַ�����ת:
	//�������ַ���A��B������ܽ�A���м�ĳ��λ�÷ָ�Ϊ�����������ַ���������Ϊ�մ�����������ߵ��ַ����ƶ����ұ��ַ�����������µ��ַ������Ա�Ϊ�ַ���Bʱ����true��
	//	���磺���A = ��youzan����B = ��zanyou����A����you����zan���иλ��õ���zanyou����B��ͬ����true��

	//�Լ��Ľⷨ
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

	//����ⷨ
	bool solve_1(string A, string B) {
		// write code here
		/*����ַ����ĳ��ȶ�����ͬ��ֱ�ӷ���false
		���������ͬ������A�ַ���ƴ���Լ�Ȼ�����ж���û��B����ַ���
		*/
		if (A.size() == B.size()) {
			A += A;
			//string��find()����ֵ����ĸ��ĸ���е�λ�ã��±��¼�������û���ҵ���
			//��ô�᷵��һ���ر�ı��npos��������ֵ���Կ�����һ��int�͵�����
			if (A.find(B) != A.npos)
				return true;
		}
		return false;
	}

	/*5. KMP�㷨*/
	//https://zhuanlan.zhihu.com/p/83334559
	KMP::KMP(string pat) 
	{
		this->pat = pat;
		
		int M = pat.length();
		// dp[״̬][�ַ�] = �¸�״̬
		this->dp = new int* [M];
		for (int i = 0; i < M; i++)
		{
			this->dp[i] = new int[256];
			memset(dp[i], 0, 256 * sizeof(int));
		}
		// base case
		dp[0][pat[0]] = 1;
		// Ӱ��״̬ X ��ʼΪ 0
		int X = 0;
		// ����״̬ת��ͼ���Ըĵĸ������ˣ�
		for (int j = 1; j < M; j++) {
			for (int c = 0; c < 256; c++)
				dp[j][c] = dp[X][c];
			dp[j][pat[j]] = j + 1;
			// ����Ӱ��״̬
			X = dp[X][pat[j]];
		}
	}

	int KMP::search(string txt) 
	{
		int M = pat.length();
		int N = txt.length();
		// pat �ĳ�ʼ̬Ϊ 0
		int j = 0;
		for (int i = 0; i < N; i++) {
			// ���� pat ����һ��״̬
			j = dp[j][txt[i]];
			// ������ֹ̬�����ؽ��
			if (j == M) return i - M + 1;
		}
		// û������ֹ̬��ƥ��ʧ��
		return -1;
	}

	KMP::~KMP()
	{
		if (this->dp != NULL)
		{
			delete[] dp;
		}
	}