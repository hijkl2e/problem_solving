#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, d{};
	cin >> N >> d;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j) {
			if (j % 10 == d) {
				++ans;
			}
			j /= 10;
		}
	}
	cout << ans << "\n";
	return 0;
}
