#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int p = N;
	for (int i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			p = i;
			break;
		}
	}
	int ans = N - N / p;
	cout << ans << "\n";
	return 0;
}
