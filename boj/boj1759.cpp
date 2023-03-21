#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, C{};
	cin >> L >> C;
	vector<char> A(C);
	for (int i = 0; i < C; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = (1 << C) - 1; i >= 0; --i) {
		if (__builtin_popcount(i) != L) {
			continue;
		}
		vector<char> B;
		for (int j = C - 1; j >= 0; --j) {
			if (i & (1 << j)) {
				B.push_back(A[C - j - 1]);
			}
		}
		int cnt{};
		for (char c : B) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				++cnt;
			}
		}
		if (0 < cnt && cnt < L - 1) {
			for (int i = 0; i < L; ++i) {
				cout << B[i];
			}
			cout << "\n";
		}
	}
	return 0;
}
