#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int cnt{};
	while (K--) {
		int x{};
		cin >> x;
		cnt += (x + 1) / 2;
	}
	cout << (cnt >= N ? "YES" : "NO") << "\n";
	return 0;
}
