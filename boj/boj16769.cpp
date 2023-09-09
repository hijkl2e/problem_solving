#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i] >> B[i];
	}
	for (int i = 0; i < 100; ++i) {
		int j = i % 3;
		int k = (i + 1) % 3;
		int l = min(B[j], A[k] - B[k]);
		B[j] -= l;
		B[k] += l;
	}
	for (int i = 0; i < 3; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
