#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 3; ++i) {
		cin >> B[i];
	}
	double minv = 1e9;
	for (int i = 0; i < 3; ++i) {
		minv = min(minv, A[i] * 1.0 / B[i]);
	}
	cout << fixed << setprecision(10);
	for (int i = 0; i < 3; ++i) {
		cout << (A[i] - minv * B[i]) << (i == 2 ? "\n" : " ");
	}
	return 0;
}
