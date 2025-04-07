#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	map<string, int> s2p;
	for (int i = 0; i < N; ++i) {
		string s;
		int p{};
		cin >> s >> p;
		s2p[s] = p;
	}
	int sum{};
	for (int i = 0; i < K; ++i) {
		string t;
		cin >> t;
		sum += s2p[t];
		s2p.erase(t);
	}
	vector<int> A;
	for (auto &p : s2p) {
		A.push_back(p.second);
	}
	sort(A.begin(), A.end());
	int minv = sum + accumulate(A.begin(), A.begin() + M - K, 0);
	int maxv = sum + accumulate(A.end() - M + K, A.end(), 0);
	cout << minv << " " << maxv << "\n";
	return 0;
}
