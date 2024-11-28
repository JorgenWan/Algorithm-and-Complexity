#include<iostream>
#include<vector>
#include<algorithm>
/*
You can include <algorithm> if you
want to use max or min function.

#include<algorithm>

*/
using namespace std;

/*
In principle, you are not allowed to
use other functions in <algorithm> or
include other header files. So before
using any other function in <algorithm>,
or including any other header file,
you may need to confirm with TA.
*/

/*
Add more functions as you need,
but DO NOT change the main function
or any given code.
*/

int f(int i, int j, const vector<int>& B, vector<vector<int>>& opt) {
	if (opt[i][j] != 0) return opt[i][j];
	if (i > j) return 0;
	if (i == j) {
		opt[i][j] = B[i - 1]*B[i]*B[i + 1];
	}
	if (j - i >= 1) {
		int tmp = 0;
		for (int k = i;k <= j;++k) {
			tmp = max(f(i, k - 1, B, opt) + f(k + 1, j, B, opt) + B[i - 1] * B[k] * B[j + 1], tmp);
		}
		opt[i][j] = tmp;
	}
	return opt[i][j];
}


int maxCoins(vector<int>& nums) {
	// Create two virtual targets
	vector<int> B(1, 1);
	for (int i = 0; i < nums.size(); i++)
		B.push_back(nums[i]);
	B.push_back(1);

	int n = B.size();
	vector<vector<int>> opt(n, vector<int>(n, 0));

	f(1, n - 2, B, opt);
	/*
	Implement your algorithm here
	and return the maximum number
	of coins you can collect.
	*/

	return opt[1][n-2];
}

int main() {
	int N;
	vector<int> nums;

	cin >> N;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	cout << maxCoins(nums) << endl;

	return 0;
}