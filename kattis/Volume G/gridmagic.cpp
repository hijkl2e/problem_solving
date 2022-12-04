#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N < M) {
		swap(N, M);
	}
	int ans{};
	if (M == 1 && N < 6) {
		ans = (10 - N) / 2;
	} else if (N == M && N < 4) {
		ans = (N + 1) * (N + 1);
	} else if (N == 3 && M == 2) {
		ans = 5;
	}
	cout << ans << "\n";
	return 0;
}
