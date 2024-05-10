// C++ program to compute sum of
// subarray elements
#include <bits/stdc++.h>
using namespace std;

// function compute sum all sub-array
long int SubArraySum(int arr[], int n)
{
	long int result = 0;

	// computing sum of subarray using formula
	for (int i = 0; i < n; i++)
		result += (arr[i] * (i + 1) * (n - i));

	// return all subarray sum
	return result;
}

// Driver code
int main()
{
	int arr[] = { 7, -1, -2, 1, 5, -11, 9, 1, 4, -1, 3, -10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sum of SubArray : " << SubArraySum(arr, n)
		<< endl;
	return 0;
}
