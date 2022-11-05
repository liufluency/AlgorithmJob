#include "CUtilSort.h"

inline void CUtilSort::_swap(int& l, int& r)
{
	int temp = l;
	l = r;
	r = temp;
}

void CUtilSort::selectSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			_swap(arr[i], arr[minIndex]);
		}
	}
}


void CUtilSort::MergeSort(int instance[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(instance, low, mid);
		MergeSort(instance, mid + 1, high);
		Merge(instance, low, mid, high);
	}
}

void CUtilSort::Merge(int instance[], int low, int mid, int high)
{
	int left = mid - low + 1;
	int right = high - mid;
	int* leftmarge = new int[left];
	int* rightmarge = new int[right];
	for (int i = 0; i < left; i++)
	{
		leftmarge[i] = instance[low + i];
	}
	for (int i = 0; i < right; i++)
	{
		rightmarge[i] = instance[mid + 1 + i];
	}

	int l = 0, r = 0;
	for (int i = low; i <= high; i++)
	{
		if (l == left)
		{
			instance[i] = rightmarge[r];
			r++;
		}
		else if (r == right)
		{
			instance[i] = leftmarge[l];
			l++;
		}
		else {
			if (leftmarge[l] < rightmarge[r])
			{
				instance[i] = leftmarge[l];
				l++;
			}
			else
			{
				instance[i] = rightmarge[r];
				r++;
			}
		}
	}
}
