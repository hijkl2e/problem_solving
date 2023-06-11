#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B;
	for (int i = 1; i * i <= A[0]; ++i) {
		if (A[0] % i) {
			continue;
		}
		B.push_back(i);
		if (i * i < A[0]) {
			B.push_back(A[0] / i);
		}
	}
	sort(B.begin(), B.end());
	for (int i = 1; i < N; ++i) {
		for (int j = B.size() - 1; j >= 0; --j) {
			if (A[i] % B[j]) {
				B.erase(B.begin() + j);
			}
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
