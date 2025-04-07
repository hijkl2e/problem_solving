#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int x = ++N;
	vector<int> A;
	while (x) {
		A.push_back(x % 10);
		x /= 10;
	}
	reverse(A.begin(), A.end());
	int t = 1, u{};
	for (int i = 0; i < A.size() - 1; ++i) {
		u += t;
		t *= 10;
	}
	vector<int> B(10, (A.size() - 1) * t / 10);
	B[0] -= u;
	for (int i = 0; i < A.size(); ++i) {
		N %= t;
		for (int j = i ? 0 : 1; j < 10; ++j) {
			if (A[i] == j) {
				B[j] += N;
				break;
			}
			B[j] += t;
			for (int k = 0; k < 10; ++k) {
				B[k] += (A.size() - i - 1) * t / 10;
			}
		}
		t /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		cout << B[i] << (i == 9 ? "\n" : " ");
	}
	return 0;
}
