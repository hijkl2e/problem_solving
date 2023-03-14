#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(1000001);
	bool yes{};
	for (int i = 0; i < N; ++i) {
		if (i - M >= 0) {
			--B[A[i - M]];
		}
		if (++B[A[i]] == (9 * M - 1) / 10 + 1) {
			yes = true;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
