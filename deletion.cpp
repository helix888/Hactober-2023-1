// C++ implementation to find 
// minimum number of deletions 
// to make a sorted sequence
#include <bits/stdc++.h>
using namespace std;

/* lis() returns the length
of the longest increasing 
subsequence in arr[] of size n */
int lis( int arr[], int n )
{
	int result = 0;
	int lis[n];

	/* Initialize LIS values
	for all indexes */
	for (int i = 0; i < n; i++ )
		lis[i] = 1;

	/* Compute optimized LIS 
	values in bottom up manner */
	for (int i = 1; i < n; i++ )
		for (int j = 0; j < i; j++ )
			if ( arr[i] > arr[j] &&
				lis[i] < lis[j] + 1)
			lis[i] = lis[j] + 1;

	/* Pick resultimum 
	of all LIS values */
	for (int i = 0; i < n; i++ )
		if (result < lis[i])
			result = lis[i];

	return result;
}

// function to calculate minimum
// number of deletions
int minimumNumberOfDeletions(int arr[], 
							int n)
{
	// Find longest increasing 
	// subsequence
	int len = lis(arr, n);

	// After removing elements 
	// other than the lis, we 
	// get sorted sequence.
	return (n - len);
}

// Driver Code
int main()
{
	int arr[] = {30, 40, 2, 5, 1,
				7, 45, 50, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of deletions = "
		<< minimumNumberOfDeletions(arr, n);
	return 0;
}
