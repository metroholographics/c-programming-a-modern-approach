/* 
--------
12/01/2025
Enter 10 numbers
Outputs the largest and smallest numbers in the array
--------
*/


#include <stdio.h>

#define N 10

void
max_min(int a[], int n, int *max, int *min)
{
	int *p = a;
	*max = *min = a[0];
	
	for (p = a + 1; p < a + n; p++) {
		if (*max < *p) {
			*max = *p;
		} else if (*min > *p) {
			*min = *p;
		}
	}
}

int
main(void)
{
	int nums[N];
	int *p, big, small;

	printf("Enter %d numbers: ", N);

	for (p = nums; p < nums + N; p++) {
		scanf("%d", p);
	}

	max_min(nums, N, &big, &small);

	printf("Largest: %d\nSmallest: %d\n", big, small);

	return 0;

}
