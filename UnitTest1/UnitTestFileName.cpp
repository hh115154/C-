#include "pch.h"
#include<ctime>
#include<iostream>
#include "CppUnitTest.h"
#include"LinkList.h"
#include"TreeNode.h"
#include"Sort.h"
#include"Stack.h"
#include<algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
time_t now = time(0);
tm* localtm = localtime(&now);
BEGIN_TEST_MODULE_ATTRIBUTE()
TEST_MODULE_ATTRIBUTE(L"Module Attribute",L"AttributeName")
END_TEST_MODULE_ATTRIBUTE()
TEST_MODULE_INITIALIZE(ModuleInitialize)
{
	Logger::WriteMessage("In Module Initialize");
}

TEST_MODULE_CLEANUP(ModuleCleanup)
{
	Logger::WriteMessage("In Module Cleanup");
}
namespace NameSpaceName
{
	TEST_CLASS(TestClassTree)
	{
	public:
		BEGIN_TEST_METHOD_ATTRIBUTE(TestBinaryTree)
			TEST_OWNER(L"OwnerName")
			TEST_PRIORITY(1)
			TEST_METHOD_ATTRIBUTE(L"MyTrait", L"thisTraitValue")
		END_TEST_METHOD_ATTRIBUTE()




		TEST_METHOD(TestBinaryTree)
		{
			int len = 10;
			int arr[] = { -87,34,-6,-18,-75,9,19,-30,129,-6 };
			BTreeNode* root = new BTreeNode(arr,len);
			int treeDepth = root->getDepthOfTree();
			Assert::AreEqual(6, treeDepth);

		}
	};
	TEST_CLASS(TestClassSort)
	{
	public:
		int* arr;
		int len;
		int* arrRes;
		void compare(int a[], int b[]) {
			for (int i = 0; i < len; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD_INITIALIZE(setUp)
		{
			len = 10;
			arr = new int[len]{ -87, 34, -6, -18, -75, 9, 19, -30, 129, -6 };
			arrRes = new int[len];
			memcpy(arrRes, arr, len * sizeof(int));
			sort(arrRes, arrRes+len
			
			
			);

		}
		TEST_METHOD_CLEANUP(teardown)
		{
			
		}
		TEST_METHOD(TestQuickSort)
		{
			Sort* s = new QuickSort();
			s->sort(arr, len);
			compare(arr, arrRes);
		}
		TEST_METHOD(TestMergeSort)
		{
			Sort* s = new MergeSort();
			s->sort(arr, len);
			compare(arr, arrRes);
		}
	};
	TEST_CLASS(TestClassStack) {
public:
	TEST_METHOD(TestIsValid) {
		string str = "[{}([])]";
		string str1 = "[](){";
		bool res = Stack::isStrValid(str);
		bool res1 = Stack::isStrValid(str1);
		Assert::IsTrue(res);
		Assert::IsFalse(res1);
	}
	TEST_METHOD(TestNextGreaterNum) {
		vector<int> set1{ 4,1,2 };
		vector<int> arr1{ 1,3,4,2 };
		vector<int> expRes1{ -1,3,-1 };
		vector<int> res1 = Stack::nextGreaterNum(set1, arr1);
		Assert::IsTrue(res1==expRes1);
		vector<int> set2{ 2,4 };
		vector<int> arr2{ 1,2,3,4 };
		vector<int> expRes2{ 3,-1 };
		vector<int> res2 = Stack::nextGreaterNum(set2, arr2);
		Assert::IsTrue(res2==expRes2);
	}
	TEST_METHOD(TestNextGreaterNum2) {

		vector<int> arr1{ 1,2,1 };
		vector<int> expRes1{ 2,-1,2 };
		vector<int> res1 = Stack::nextGreaterNum2( arr1);
		Assert::IsTrue(res1 == expRes1);
		
		vector<int> arr2{ 1,3,4,2 };
		vector<int> expRes2{ 3,4,-1,3 };
		vector<int> res2 = Stack::nextGreaterNum2( arr2);
		Assert::IsTrue(res2 == expRes2);
	}
	TEST_METHOD(TestDecodeString) {
		string str("2[2[abc]1[de]]");
		string expRes("abcabcdeabcabcde");
		string res = Stack::decodeString(str);
		Assert::AreEqual(res, expRes);

		string str1("2[2[abc]2[de]]12[f]");
		string expRes1("abcabcdedeabcabcdedeffffffffffff");
		string res1 = Stack::decodeString(str1);
		Assert::AreEqual(res1, expRes1);
	}

	TEST_METHOD(TestExclusiveTime) {
		vector<string> str{ "0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8" };
		vector<int> expRes{8,1};
		vector<int> res = Stack::exclusiveTime(2,str);
		Assert::IsTrue(res== expRes);

		vector<string> str1{ "0:start:0","1:start:1","1:end:1","2:start:3","2:end:3","0:end:4" };
		vector<int> expRes1{ 3,1,1};
		vector<int> res1 = Stack::exclusiveTime(3, str1);
		Assert::IsTrue(res1 == expRes1);

		vector<string> str2{ "0:start:0","1:start:2","1:end:5","0:end:6" };
		vector<int> expRes2{ 3,4 };
		vector<int> res2 = Stack::exclusiveTime(2, str2);
		Assert::IsTrue(res2 == expRes2);
	}
	};
}
