#include <limits.h>
#include <iostream>
#include <ctime>

using namespace std;

int Max(int a, int b) { return (a > b) ? a : b; }

int Max(int a, int b, int c) { return Max(Max(a, b), c); }

int maxCrossingSum(int A[], int l, int m, int h)
{
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
			left_sum = sum;
	}
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m; i <= h; i++)
	{
		sum = sum + A[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	return Max(left_sum + right_sum - A[m], left_sum, right_sum);
}
int maxSubArraySum(int A[], int l, int h)
{
	if (l > h)
		return INT_MIN;

	if (l == h)
		return A[l];

	int m = (l + h) / 2;

	return Max(maxSubArraySum(A, l, m - 1),
			   maxSubArraySum(A, m + 1, h),
			   maxCrossingSum(A, l, m, h));
}

int main()
{
	int x;
	// cout << "Enter the size of the array: ";
	cin >> x;
	int arr[x];
	for (int i = 0; i < x; i++)
	{
		// cout << "Enter element " << i + 1 << " of the array: ";
		cin >> arr[i];
	}

	int n = sizeof(arr) / sizeof(arr[0]);

	clock_t tstart = clock();
	int max_sum = maxSubArraySum(arr, 0, n - 1);
	double time1 = (double)(clock() - tstart) / CLOCKS_PER_SEC;
	cout << "Time taken by the algorithm is: " << time1 << endl;
	return 0;
}