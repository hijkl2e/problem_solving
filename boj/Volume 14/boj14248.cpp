#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int s{};
	cin >> s;
	--s;
	deque<bool> vst(N);
	queue<int> q;
	vst[s] = true;
	q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		int y = A[x];
		if (x + y < N && !vst[x + y]) {
			vst[x + y] = true;
			q.push(x + y);
		}
		if (x - y >= 0 && !vst[x - y]) {
			vst[x - y] = true;
			q.push(x - y);
		}
	}
	int ans = accumulate(vst.begin(), vst.end(), 0);
	cout << ans << "\n";
	return 0;
}
