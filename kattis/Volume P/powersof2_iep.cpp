#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

ll N, E;
string sn, p2;
vector<ll> pt(20);

ll solve(int x) {
	string s(sn.size(), '#');
	for (int i = 0; i < sn.size(); ++i) {
		if ((x >> i) & 1) {
			for (int j = 0; j < p2.size(); ++j) {
				if (s[i + j] != '#' && s[i + j] != p2[j]) {
					return 0;
				}
				s[i + j] = p2[j];
			}
		}
	}
	vector<ii> A;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '#') {
			continue;
		}
		int j = i;
		while (j < s.size() && s[j] == '#') {
			++j;
		}
		A.push_back({i, j});
		i = j;
	}
	A.push_back({s.size(), -1});
	int cnt = count(s.begin(), s.end(), '#');
	replace(s.begin(), s.end(), '#', '0');
	ll ret{};
	for (auto &[u, v] : A) {
		if (stoull(s) > N) {
			break;
		}
		if (u == s.size()) {
			++ret;
			break;
		}
		if (u && stoll(sn.substr(0, u)) > stoll(s.substr(0, u))) {
			ret += pt[cnt];
			break;
		}
		cnt -= v - u;
		ret += stoll(sn.substr(u, v - u)) * pt[cnt];
		copy(sn.begin() + u, sn.begin() + v, s.begin() + u);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> E;
	sn = to_string(N);
	p2 = to_string(1LL << E);
	if (sn.size() < p2.size()) {
		cout << "0\n";
		return 0;
	}
	pt[0] = 1;
	for (int i = 1; i < pt.size(); ++i) {
		pt[i] = 10 * pt[i - 1];
	}
	ll ans{};
	for (int i = 1; i < (1 << (sn.size() - p2.size() + 1)); ++i) {
		ans += (__builtin_popcount(i) % 2 ? 1 : -1) * solve(i);
	}
	cout << ans << "\n";
	return 0;
}
