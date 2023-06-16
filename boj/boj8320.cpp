#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i * i <= N; ++i) {
		for (int j = i; i * j <= N; ++j) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
