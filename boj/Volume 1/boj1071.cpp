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
	sort(A.begin(), A.end());
	vector<int> B{A[0]};
	A.erase(A.begin());
	while (A.size()) {
		int x{};
		while (x < A.size() && A[x] == B.back() + 1) {
			++x;
		}
		if (x < A.size()) {
			B.push_back(A[x]);
			A.erase(A.begin() + x);
			continue;
		}
		x = B.size();
		while (x && B[x - 1] == B.back()) {
			--x;
		}
		B.insert(B.begin() + x, A.begin(), A.end());
		break;
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
