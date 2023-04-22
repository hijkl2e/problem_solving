#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	char c1 = 'a', c2 = 'b';
	if (N < M) {
		swap(N, M);
		swap(c1, c2);
	}
	int val = (N + M) * (N + M - 1) / 2;
	string ans;
	if (N > 3 && M > 1) {
		ans = string(1, c1) + string(1, c2) + string(N - 3, c1) + string(M - 1, c2) + string(2, c1);
	} else {
		val -= N < 3 || M > 1 ? M : 0;
		ans = string(1, c1) + string(M, c2) + string(N - 1, c1);
	}
	cout << val << "\n" << ans << "\n";
	return 0;
}
