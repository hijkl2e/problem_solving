#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 1;

map<string, ll> A;

ll solve(vector<int> &C, vector<string> &D) {
	ll ret{};
	for (int i = 0; i < C.size(); ++i) {
		auto it = A.find(D[i]);
		if (it == A.end()) {
			return -1;
		}
		ret += C[i] * it->second;
	}
	ret = min(ret, INF);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	while (N--) {
		string s;
		int x{};
		cin >> s >> x;
		A[s] = x;
	}
	cin.ignore();
	vector<string> B(M);
	vector<vector<int>> C(M);
	vector<vector<string>> D(M);
	for (int i = 0; i < M; ++i) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		getline(iss, B[i], '=');
		while (getline(iss, s, '+')) {
			C[i].push_back(s[0] - '0');
			D[i].push_back(s.substr(1));
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < M; ++i) {
			ll p = solve(C[i], D[i]);
			if (p == -1) {
				continue;
			}
			auto it = A.insert({B[i], INF + 1}).first;
			if (it->second > p) {
				it->second = p;
				flag = true;
			}
		}
	}
	auto it = A.find("LOVE");
	cout << (it == A.end() ? -1 : it->second) << "\n";
	return 0;
}
