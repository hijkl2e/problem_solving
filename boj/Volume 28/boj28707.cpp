#include <bits/stdc++.h>

using namespace std;

using ivi = pair<int, vector<int>>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	vector<int> L(M);
	vector<int> R(M);
	vector<int> C(M);
	for (int i = 0; i < M; ++i) {
		cin >> L[i] >> R[i] >> C[i];
		--L[i], --R[i];
	}
	map<vector<int>, int> D;
	priority_queue<ivi, vector<ivi>, greater<ivi>> pq;
	pq.push({D[A] = 0, A});
	while (pq.size()) {
		auto [d, v] = pq.top(); pq.pop();
		if (D[v] < d) {
			continue;
		}
		for (int i = 0; i < M; ++i) {
			swap(v[L[i]], v[R[i]]);
			auto it = D.insert({v, INF}).first;
			if (it->second > d + C[i]) {
				pq.push({it->second = d + C[i], v});
			}
			swap(v[L[i]], v[R[i]]);
		}
	}
	sort(A.begin(), A.end());
	auto it = D.find(A);
	int ans = it == D.end() ? -1 : it->second;
	cout << ans << "\n";
	return 0;
}
