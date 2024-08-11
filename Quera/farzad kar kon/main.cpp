// C++ program to compute sum of
// subarray elements
// I am gonna use Kadane's algorithm 
// the link: https://cyberw1ng.medium.com/kadanes-algorithm-the-efficient-way-to-find-maximum-subarray-sum-2023-f67b42236bde
#include <bits/stdc++.h>
using namespace std;

// function compute sum all sub-array
int SubArraySum(int arr[], int n)
{
	int max_so_far = 0;
	int max_ending_here = 0;

	// computing sum of subarray using formula
	for (int i = 0; i < n; i++) {
		max_ending_here += arr[i];

		if (max_ending_here < 0) {
			max_ending_here = 0;
		}

		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
		}
	}

	// return all subarray sum
	return max_so_far;
}


int main()
{
	int n;
	int arr[100]; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << SubArraySum(arr, n) << endl;

	return 0;
}
