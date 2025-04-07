#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int avg = accumulate(A.begin(), A.end(), 0) / 5;
	cout << avg << "\n" << A[2] << "\n";
	return 0;
}
