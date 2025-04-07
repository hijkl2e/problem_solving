#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	vector<int> B(K + 1, INF);
	vector<int> C(K);
	for (int i = K - 1; i >= 0; --i) {
		C[i] = B[A[i]];
		B[A[i]] = i;
	}
	set<ii> S;
	deque<bool> D(K + 1);
	int ans{};
	for (int i = 0; i < K; ++i) {
		if (D[A[i]]) {
			S.erase({i, A[i]});
			S.insert({C[i], A[i]});
			continue;
		}
		if (S.size() == N) {
			auto it = --S.end();
			D[it->second] = false;
			S.erase(it);
			++ans;
		}
		D[A[i]] = true;
		S.insert({C[i], A[i]});
	}
	cout << ans << "\n";
	return 0;
}
