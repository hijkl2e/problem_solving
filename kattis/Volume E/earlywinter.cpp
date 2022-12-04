#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (x <= M) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << "It had never snowed this early!\n";
	} else {
		cout << "It hadn't snowed this early in " << ans << " years!\n";
	}
	return 0;
}
