#include<iostream>
#include "Sort.h"

void QuickSort::sort(int arr[], int len)
{
	quicksort(arr, 0, len - 1);
	show(arr, len);
}

void QuickSort::quicksort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivotIdx = partition(arr, left, right);//分块原序列，并输出中间位置
		quicksort(arr, left, pivotIdx - 1);
		quicksort(arr, pivotIdx + 1, right);
	}

}

int QuickSort::partition(int arr[], int left, int right)
{
	/*
	* 两个指针 j（快） 和 smallEdge（慢）,一个基准值。
	* 遍历left到right，每次j++
	* 只有遇到小数时smallEdge++并交换两个指针下的数,即把新的小数换过来，因为smallEdge后面一个数为大数
	*/
	int pivot = arr[right];
	int smallEdge = left - 1;//该位置为小元素的最右边界
	for (int j = left; j < right; j++)//用j遍历整个数组
	{
		if (arr[j] < pivot)
		{
			smallEdge++;
			swap(arr[smallEdge], arr[j]);
		}
	}
	smallEdge++;//结束后，将最后元素（pivot）与小元素边界后的一个元素替换位置，从而使其成为中间元素
	swap(arr[smallEdge], arr[right]);

	return smallEdge;
}

void MergeSort::sort(int arr[], int len)
{
	mergesort(arr, 0, len - 1);
	show(arr, len);
}

void MergeSort::mergesort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void MergeSort::merge(int arr[], int left, int mid, int end)
{
	int k = 0;
	int i = left;
	int j = mid + 1;//注意这里的赋值，需要参考外部递归时分割的位置
	int* tmp = new int[end - left + 1];

	while (i <= mid && j <= end)
		if (arr[i] < arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];

	if (i <= mid)
		memcpy(tmp + k, arr + i, (mid - i + 1) * sizeof(int));
	if (j <= end)
		memcpy(tmp + k, arr + j, (end - j + 1) * sizeof(int));
	memcpy(arr + left, tmp, (end - left + 1) * sizeof(int));


	delete[]tmp;
	tmp = nullptr;
}

void PublicMethod::swap(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void PublicMethod::show(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}


