#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	ll ans{};
	string jane = "Jane Eyre";
	while (N--) {
		string s;
		int k{};
		getline(cin, s, '"');
		getline(cin, s, '"');
		cin >> k;
		if (s < jane) {
			ans += k;
		}
	}
	vector<ii> A;
	while (M--) {
		int t{}, k{};
		string s;
		cin >> t;
		getline(cin, s, '"');
		getline(cin, s, '"');
		cin >> k;
		if (s < jane) {
			A.push_back({t, k});
		}
	}
	sort(A.begin(), A.end());
	for (auto &p : A) {
		if (ans >= p.first) {
			ans += p.second;
		}
	}
	ans += K;
	cout << ans << "\n";
	return 0;
}
