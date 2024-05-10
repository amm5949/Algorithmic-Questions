// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum sum
int helper(vector<int>& arr, int k)
{

	unordered_map<int, int> mp;
	int currentSum = 0, maxSum = 0;
	int n = arr.size(), left = 0, i = 0;

	// Iterating for length k
	while (i < k && i < n) {

		currentSum += arr[i];
		mp[arr[i]]++;

		i++;
	}

	// If distinct elements present in map
	// equal to k
	if (mp.size() == k) {
		maxSum = currentSum;
	}

	// Iterating over the left array
	for (int i = k; i < n; i++) {

		mp[arr[i]]++;
		mp[arr[left]]--;
		if (mp[arr[left]] == 0) {
			mp.erase(arr[left]);
		}
		currentSum += arr[i];
		currentSum -= arr[left];
		if (mp.size() == k) {
			maxSum = max(maxSum, currentSum);
		}
		++left;
	}

	// Returning the maximum sum
	return maxSum;
}

// Driver Code
int main()
{
	vector<int> arr = { 3, 4, 4, 4 };
	int k = 3;

	// Function call
	cout << helper(arr, k);
	return 0;
}
