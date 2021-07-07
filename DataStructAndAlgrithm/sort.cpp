#include<iostream>
#include "Sort.h"
#include<cstring>

void QuickSort::sort(int arr[], int len)
{
	quicksort(arr, 0, len - 1);
	show(arr, len);
}

void QuickSort::quicksort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivotIdx = partition(arr, left, right);//返回中间大小的位置，并将原数组分为小数区和大数区
		quicksort(arr, left, pivotIdx - 1);
		quicksort(arr, pivotIdx + 1, right);
	}

}

int QuickSort::partition(int arr[], int left, int right)
{
	/*
	* 双指针的方法，快指针向前遍历寻找小数，然后与慢指针位置的大数替换，慢指针再前移
	* 结果是前一半是小数，后一半是大数
	*/
	int pivot = arr[right];
	int smallEdge = left;//慢指针
	for (int j = left; j < right; j++)//快指针
	{
		if (arr[j] < pivot)
		{
			swap(arr[smallEdge], arr[j]);
			smallEdge++;
		}
	}

	swap(arr[smallEdge], arr[right]);//最后将末尾的pivot与满指针位置的大数替换

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
	int j = mid + 1;
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


