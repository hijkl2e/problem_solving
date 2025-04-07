#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> X(N);
	vector<int> L(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> L[i];
	}
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c;
		C[i] = c == 'R' ? 0 : c == 'Y' ? 1 : 2;
	}
	vector<int> R(3, -2 * INF);
	vector<int> A(3, -1);
	int ans_x{}, ans_y{};
	for (int i = 0; i < N; ++i) {
		if (R[C[i]] < X[i] + L[i]) {
			R[C[i]] = X[i] + L[i];
			A[C[i]] = i + 1;
		}
		for (int j = 0; j < 3; ++j) {
			if (j == C[i] || R[j] < X[i] - L[i]) {
				continue;
			}
			ans_x = A[j];
			ans_y = i + 1;
			i = N;
			break;
		}
	}
	if (ans_x) {
		cout << "YES\n";
		cout << ans_x << " " << ans_y << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
