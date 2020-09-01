#pragma once

using namespace std;

class Sort
{
public:
	virtual void sort(int arr[], int len) = 0;

};

class PublicMethod {
protected:
	void swap(int& a, int& b);
	void show(int arr[],int len);
};

class QuickSort :public Sort ,public PublicMethod
{
	// 通过 Sort 继承
public:
	virtual void sort(int arr[], int len) override;
private:
	void quicksort(int arr[],int left,int right);
	int partition(int arr[],int left,int right);
};

class MergeSort :public Sort, public PublicMethod 
{
	// 通过 Sort 继承
public:
	virtual void sort(int arr[], int len) override;
private:
	void mergesort(int arr[],int left,int right);
	void merge(int arr[],int left,int mid,int end);
};
