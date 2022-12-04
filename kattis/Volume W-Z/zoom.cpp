#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A;
	A.reserve(N / K);
	for (int i = 1; i <= N; ++i) {
		int x{};
		cin >> x;
		if (i % K == 0) {
			A.push_back(x);
		}
	}
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
