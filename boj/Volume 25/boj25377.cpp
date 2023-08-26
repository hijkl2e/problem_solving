#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = INF;
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		if (a <= b) {
			ans = min(ans, b);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
