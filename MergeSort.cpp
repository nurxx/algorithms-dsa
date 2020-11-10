#include <iostream>
#include <algorithm>

using namespace std;

void mergeSort(int*arr, int left, int mid, int right)
{
	int half1 = mid-left + 1;
	int half2 = right - mid;

	int L[500], R[500];

	for (int i = 0; i < half1; i++)
	{
		L[i] = arr[i+left];
	}
	for (int i = 0; i < half2; i++)
	{
		R[i] = arr[i + mid + 1];
	}
	
	int i = 0;
	int j = 0;
	int k = left;

	while (i < half1 && j < half2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i++];
		}
		else arr[k] = R[j++];
		k++;
	}
	while (i < half1)
	{
		arr[k++] = L[i++];
	}
	while (j < half2)
	{
		arr[k++] = R[j++];
	}

}

void merge(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(arr, left, mid);
		merge(arr, mid + 1, right);

		mergeSort(arr, left, mid, right);
	}
}
int main()
{
	int arr[5] = { 1,8,3,5,3};

	merge(arr, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}