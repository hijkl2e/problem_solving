#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	int x{};
	for (int i = 0; i < N; ++i) {
		x ^= P[i] + (P[i] % 4 == 3) - (P[i] % 4 == 0);
	}
	cout << (x ? "koosaga" : "cubelover") << "\n";
	return 0;
}
