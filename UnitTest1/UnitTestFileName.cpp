#include "pch.h"
#include<ctime>
#include<iostream>
#include "CppUnitTest.h"
#include"LinkList.h"
#include"TreeNode.h"
#include"Sort.h"
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
}
