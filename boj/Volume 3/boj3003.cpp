#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	vector<int> B{1, 1, 2, 2, 2, 8};
	for (int i = 0; i < 6; ++i) {
		cout << B[i] - A[i] << (i == 5 ? "\n" : " ");
	}
	return 0;
}
