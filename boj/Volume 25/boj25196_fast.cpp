#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> V(3);
	vector<int> S(3);
	vector<int> E(3);
	for (int i = 0; i < 3; ++i) {
		cin >> V[i] >> S[i] >> E[i];
	}
	vector<int> A(V[2], -1);
	queue<int> q;
	for (int i = S[2]; i <= E[2]; ++i) {
		A[i] = 0;
		q.push(i);
	}
	ll L = lcm(V[0], V[1]);
	int r = L % V[2];
	while (q.size()) {
		int x = q.front(); q.pop();
		int y = x - r + (x < r ? V[2] : 0);
		if (A[y] == -1) {
			A[y] = A[x] + 1;
			q.push(y);
		}
	}
	deque<bool> vst(V[2]);
	ll ans = INF, sz = V[0] * V[1];
	for (int i = 0, x = 0, y = 0, z = 0; i < L; ++i,
			++x == V[0] ? x = 0 : 0, ++y == V[1] ? y = 0 : 0, ++z == V[2] ? z = 0 : 0) {
		if (S[0] <= x && x <= E[0] && S[1] <= y && y <= E[1] && !vst[z] && A[z] != -1) {
			vst[z] = true;
			ans = min(ans, A[z] * sz + i);
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
