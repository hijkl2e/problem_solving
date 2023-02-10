#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int H{}, W{}, N{};
		cin >> H >> W >> N;
		cout << (N - 1) % H + 1 << setw(2) << setfill('0') << (N - 1) / H + 1 << "\n";
	}
	return 0;
}
