#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{};
		cin >> N;
		set<int> S;
		while (N--) {
			int x{};
			cin >> x;
			auto res = S.insert(x);
			if (!res.second) {
				S.erase(res.first);
			}
		}
		cout << "Case #" << tc << ": " << *S.begin() << "\n";
	}
	return 0;
}
