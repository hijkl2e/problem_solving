#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string N, S;
	cin >> N;
	int ans = 1;
	for (int i = 1;; ++i) {
		S += to_string(i);
		while (S.size() >= N.size() && S.substr(0, N.size()) != N) {
			S.erase(S.begin());
			++ans;
		}
		if (S.size() >= N.size()) {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
