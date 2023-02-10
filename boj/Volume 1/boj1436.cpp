#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1, j = 0; j < N; ++i) {
		string s = to_string(i);
		if (s.find("666") != -1) {
			ans = i;
			++j;
		}
	}
	cout << ans << "\n";
	return 0;
}
