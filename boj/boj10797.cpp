#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, ans{};
	cin >> N;
	for (int i = 0; i < 5; ++i) {
		int x{};
		cin >> x;
		if (x == N) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
