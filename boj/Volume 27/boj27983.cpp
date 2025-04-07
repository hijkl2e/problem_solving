#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> X(N);
	vector<int> L(N);
	vector<char> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> L[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	int ans_x{}, ans_y{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (X[j] - X[i] <= L[i] + L[j] && C[i] != C[j]) {
				ans_x = i + 1;
				ans_y = j + 1;
				i = N;
				break;
			}
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
