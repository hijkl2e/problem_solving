#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, P{};
	cin >> C >> P;
	vector<int> V(P);
	vector<queue<int>> A(P);
	for (int i = 0; i < P; ++i) {
		cin >> V[i];
		for (int j = 0; j < C; ++j) {
			int x{};
			cin >> x;
			A[i].push(x);
		}
	}
	int vsum = accumulate(V.begin(), V.end(), 0);
	vector<int> B(C + 1);
	deque<bool> chk(C + 1);
	set<ii> S;
	for (int i = 0; i < P; ++i) {
		B[A[i].front()] += V[i];
	}
	for (int i = 1; i <= C; ++i) {
		S.insert({B[i], i});
	}
	int ans{};
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < P; ++j) {
			if (!chk[A[j].front()]) {
				continue;
			}
			while (chk[A[j].front()]) {
				A[j].pop();
			}
			int x = A[j].front();
			S.erase({B[x], x});
			B[x] += V[j];
			S.insert({B[x], x});
		}
		auto it = --S.end();
		if (it->first > vsum / 2) {
			ans = it->second;
			break;
		}
		chk[S.begin()->second] = true;
		S.erase(S.begin());
	}
	cout << ans << "\n";
	return 0;
}
