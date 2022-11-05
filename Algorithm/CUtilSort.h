#pragma once
class CUtilSort
{
private:
	static void Merge(int instance[], int low, int mid, int high);
public:
	inline static void _swap(int& l, int& r);
	static void selectSort(int arr[], int n);
	static void MergeSort(int arr[], int low, int high);
};

