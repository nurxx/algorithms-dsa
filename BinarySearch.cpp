#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int left, int right, int *arr,int x)
{
	
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == x)return mid;
		
		if (arr[mid] > x)right = mid - 1;

		if (arr[mid] < x) left = mid + 1;
	}
	return -1;
}
int main()
{
	int arr[10] = { 1,2,3,3,4,5,7,8,9,10};
	std::sort(arr, arr + 10);

	cout << binarySearch(0, 10, arr, 3);

	system("pause");
	return 0;
}