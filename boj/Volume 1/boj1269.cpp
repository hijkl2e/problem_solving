#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	set<int> S;
	while (N--) {
		int x{};
		cin >> x;
		S.insert(x);
	}
	while (M--) {
		int x{};
		cin >> x;
		auto res = S.insert(x);
		if (!res.second) {
			S.erase(res.first);
		}
	}
	cout << S.size() << "\n";
	return 0;
}
