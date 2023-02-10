#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(2);
	vector<int> B(2);
	vector<char> C(2);
	int now = 1;
	for (int i = 0; i < N - 1; ++i) {
		int x{};
		cin >> x;
		for (int j = 0; j < x; ++j) {
			cin >> A[j] >> C[j];
			if (C[j] == 'L') {
				B[j] = A[j];
				A[j] = 1;
			} else {
				B[j] = M;
			}
		}
		if (x == 2 && C[0] == 'R' && C[1] == 'L') {
			B[0] = B[1];
			--x;
		}
		for (int j = 0; j < x; ++j) {
			if (A[j] <= now && now <= B[j]) {
				now = B[j] + 1;
			}
		}
	}
	cout << (now <= M ? "YES" : "NO") << "\n";
	return 0;
}
