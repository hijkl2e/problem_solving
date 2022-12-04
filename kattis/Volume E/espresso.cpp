#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	int M = S;
	int ans{};
	while (N--) {
		string s;
		cin >> s;
		int x = s[0] - '0' + s.size() - 1;
		if (M < x) {
			M = S;
			++ans;
		}
		M -= x;
	}
	cout << ans << "\n";
	return 0;
}
