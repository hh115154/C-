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
		int pivotIdx = partition(arr, left, right);//�ֿ�ԭ���У�������м�λ��
		quicksort(arr, left, pivotIdx - 1);
		quicksort(arr, pivotIdx + 1, right);
	}

}

int QuickSort::partition(int arr[], int left, int right)
{
	/*
	* ����ָ�� j���죩 �� smallEdge������,һ����׼ֵ��
	* ����left��right��ÿ��j++
	* ֻ������С��ʱsmallEdge++����������ָ���µ���,�����µ�С������������ΪsmallEdge����һ����Ϊ����
	*/
	int pivot = arr[right];
	int smallEdge = left - 1;//��λ��ΪСԪ�ص����ұ߽�
	for (int j = left; j < right; j++)//��j������������
	{
		if (arr[j] < pivot)
		{
			smallEdge++;
			swap(arr[smallEdge], arr[j]);
		}
	}
	smallEdge++;//�����󣬽����Ԫ�أ�pivot����СԪ�ر߽���һ��Ԫ���滻λ�ã��Ӷ�ʹ���Ϊ�м�Ԫ��
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
	int j = mid + 1;//ע������ĸ�ֵ����Ҫ�ο��ⲿ�ݹ�ʱ�ָ��λ��
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


