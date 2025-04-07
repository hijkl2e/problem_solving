#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;

const ll MOD = 1234567891;

mat mul(mat &m1, mat &m2) {
	mat ret = mat(m1.size(), vector<ll>(m2[0].size()));
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			for (int k = 0; k < m2.size(); ++k) {
				ret[i][j] = (ret[i][j] + m1[i][k] * m2[k][j]) % MOD;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<string> A;
	while (N--) {
		string s;
		cin >> s;
		bool yes = true;
		for (char c : s) {
			if (c != '4' && c != '7') {
				yes = false;
				break;
			}
		}
		if (yes) {
			A.push_back(s);
		}
	}
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	mat B(2, vector<ll>(2));
	mat C(2, vector<ll>(1));
	for (auto &s : A) {
		++B[s.back() == '7'][s.front() == '7'];
	}
	C[0][0] = C[1][0] = 1;
	while (L) {
		if (L % 2) {
			C = mul(B, C);
		}
		B = mul(B, B);
		L /= 2;
	}
	ll ans = (C[0][0] + C[1][0]) % MOD;
	cout << ans << "\n";
	return 0;
}
