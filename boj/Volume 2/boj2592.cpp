#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(10);
	for (int i = 0; i < 10; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int avg = accumulate(A.begin(), A.end(), 0) / 10;
	vector<int> B(100);
	for (int i = 0; i < 10; ++i) {
		++B[A[i] / 10];
	}
	int mode = 10 * (max_element(B.begin(), B.end()) - B.begin());
	cout << avg << "\n" << mode << "\n";
	return 0;
}
