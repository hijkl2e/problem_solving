#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N, maxv, minv;
vector<int> A, B, C, D, E;

void solve(int step) {
	if (step == N) {
		D.clear();
		E.clear();
		copy(A.begin(), A.end(), back_inserter(D));
		copy(C.begin(), C.end(), back_inserter(E));
		for (int i = 0; i < E.size();) {
			if (E[i] < 2) {
				++i;
				continue;
			} else if (E[i] == 2) {
				D[i] *= D[i + 1];
			} else {
				D[i] /= D[i + 1];
			}
			D.erase(D.begin() + i + 1);
			E.erase(E.begin() + i);
		}
		int sum = D[0];
		for (int i = 0; i < E.size(); ++i) {
			sum += (E[i] ? -1 : 1) * D[i + 1];
		}
		maxv = max(maxv, sum);
		minv = min(minv, sum);
		return;
	}
	int x = A[step];
	for (int i = 0; i < 4; ++i) {
		if (B[i] == 0) {
			continue;
		}
		--B[i];
		C.push_back(i);
		solve(step + 1);
		C.pop_back();
		++B[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	B.resize(4);
	for (int i = 0; i < 4; ++i) {
		cin >> B[i];
	}
	maxv = -INF;
	minv = INF;
	solve(1);
	cout << maxv << "\n" << minv << "\n";
	return 0;
}
