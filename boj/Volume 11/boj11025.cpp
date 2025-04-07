#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans{};
	for (int i = 2; i <= N; ++i) {
		ans = (ans + K) % i;
	}
	cout << ++ans << "\n";
	return 0;
}
