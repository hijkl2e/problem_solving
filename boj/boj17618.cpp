#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		string s = to_string(i);
		int sum{};
		for (char c : s) {
			sum += c - '0';
		}
		if (i % sum == 0) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
