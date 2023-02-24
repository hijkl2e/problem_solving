#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<ll> B;

ii find(ll x) {
	int y = upper_bound(B.begin(), B.end(), x) - B.begin();
	return {y, x - B[y - 1]};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "#" + S;
	int N{};
	cin >> N;
	vector<string> A(26);
	while (N--) {
		char c{};
		string s;
		cin >> c >> s;
		A[c - 'A'] = s;
	}
	B.resize(S.size());
	for (int i = 1; i < B.size(); ++i) {
		B[i] = B[i - 1] + A[S[i] - 'A'].size();
	}
	vector<int> C[26][26];
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			C[i][A[i][j] - 'a'].push_back(j);
		}
	}
	vector<ll> D[26];
	for (int i = 0; i < 26; ++i) {
		D[i].resize(S.size());
		for (int j = 1; j < S.size(); ++j) {
			D[i][j] = D[i][j - 1] + C[S[j] - 'A'][i].size();
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		ll q{}, s{}, e{};
		cin >> q >> s >> e;
		auto [u1, v1] = find(s - 1);
		auto [u2, v2] = find(e - 1);
		int x = S[u1] - 'A';
		int y = S[u2] - 'A';
		if (q == 1) {
			if (u1 == u2) {
				cout << A[x].substr(v1, v2 - v1 + 1) << "\n";
				continue;
			}
			cout << A[x].substr(v1);
			for (int i = u1 + 1; i < u2; ++i) {
				cout << A[S[i] - 'A'];
			}
			cout << A[y].substr(0, v2 + 1) << "\n";
			continue;
		}
		ll ans{};
		for (int i = 0; i < 26; ++i) {
			if (u1 == u2) {
				ans = max<ll>(ans, upper_bound(C[x][i].begin(), C[x][i].end(), v2)
									- lower_bound(C[x][i].begin(), C[x][i].end(), v1));
				continue;
			}
			ll cnt{};
			cnt += C[x][i].size();
			cnt -= lower_bound(C[x][i].begin(), C[x][i].end(), v1) - C[x][i].begin();
			cnt += D[i][u2 - 1] - D[i][u1];
			cnt += upper_bound(C[y][i].begin(), C[y][i].end(), v2) - C[y][i].begin();
			ans = max(ans, cnt);
		}
		cout << ans << "\n";
	}
	return 0;
}
