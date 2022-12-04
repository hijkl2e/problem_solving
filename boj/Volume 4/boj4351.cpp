#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	map<string, int> A;
	while (N--) {
		string s;
		int x{};
		cin >> s >> x;
		A[s] = x;
	}
	while (M--) {
		string s;
		int ans{};
		while (cin >> s, s != ".") {
			auto it = A.find(s);
			if (it != A.end()) {
				ans += it->second;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
