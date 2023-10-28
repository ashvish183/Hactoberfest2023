// C++ program to print all elements that
// appear more than once.
#include <bits/stdc++.h>
using namespace std;

// function to find repeating elements
vector<int> duplicates(int arr[], int n)
{
	// To store duplicates numbers.
	vector<int> ans;

	// First check all the values that are
	// present in an array then go to that
	// values as indexes and increment by
	// the size of array
	for (int i = 0; i < n; i++) {
		int index = arr[i] % n;
		arr[index] += n;
	}

	// Now check which value exists more
	// than once by dividing with the size
	// of array
	for (int i = 0; i < n; i++) {
		if ((arr[i] / n) >= 2)
		ans.push_back(i);
	}
return ans;
}

// Driver code
int main()
{
	int arr[] = { 1, 6, 3, 1, 3, 6, 6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "The repeating elements are: \n";

	// Function call
	vector<int> ans = duplicates(arr, arr_size);
	for (auto x : ans)
		cout << x << " ";

	return 0;
}
