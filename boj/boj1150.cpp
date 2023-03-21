#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	vector<int> L(N);
	vector<int> R(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		L[i] = i - 1;
		R[i] = i + 1;
		if (i < N - 1) {
			C[i] = A[i + 1] - A[i];
			pq.push({C[i], i, i + 1});
		}
	}
	deque<bool> vst(N);
	int ans{};
	while (K--) {
		while (true) {
			auto &[c, l, r] = pq.top();
			if (vst[l] || vst[r]) {
				pq.pop();
				continue;
			}
			vst[l] = vst[r] = true;
			ans += c;
			break;
		}
		auto [c, l, r] = pq.top(); pq.pop();
		int nl = L[l], nr = R[r];
		if (nl == -1 || nr == N) {
			continue;
		}
		R[nl] = nr;
		L[nr] = nl;
		C[nl] += C[r] - c;
		pq.push({C[nl], nl, nr});
	}
	cout << ans << "\n";
	return 0;
}
