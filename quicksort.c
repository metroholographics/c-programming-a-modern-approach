/* 
--------
14/10/2024
QUICKSORT - CHANGE ARR IN MAIN
PARTITION - ELEMENT SET TO ARR[0]
--------
*/

#include <stdio.h>

void	quicksort(int arr[], int low, int high);
int		split(int arr[], int low, int high);
void	print_arr(int arr[], int n);

int
main(void)
{
	int arr[] = {12, 3, 6, 18, 7, 15, 10};
	int len = sizeof(arr) / sizeof(arr[0]);

	printf("Unsorted: ");
	print_arr(arr, len);

	quicksort(arr, 0, len - 1);

	printf("Sorted: ");
	print_arr(arr, len);

	return 0;
}

void
quicksort(int arr[], int low, int high)
{
	int e;

	if (low >= high) {
		return;
	}
	e = split(arr, low, high);
	quicksort(arr, 0, e - 1);
	quicksort(arr, e + 1, high);
}

int
split(int arr[], int low, int high)
{
	int element = arr[low];

	while (low < high) {
		while (arr[high] > element && high > low) {
			high--;
		}
		if (high > low) {
			arr[low] = arr[hi gh];
			low++;
		}
		while (arr[low] < element && low < high) {
			low++;
		}
		if (low < high) {
			arr[high] = arr[low];
			high--;
		}
	}
	arr[low] = element;

	return low;
}

void
print_arr(int arr[], int n)
{
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}