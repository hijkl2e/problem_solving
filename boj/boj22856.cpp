#include <bits/stdc++.h>

using namespace std;

int N, cnt, ans;
vector<int> L, R;

void dfs(int x) {
	if (L[x] != -1) {
		++ans;
		dfs(L[x]);
	}
	++cnt;
	if (R[x] != -1) {
		++ans;
		dfs(R[x]);
	}
	if (cnt < N) {
		++ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	L.resize(N + 1);
	R.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		L[a] = b;
		R[a] = c;
	}
	dfs(1);
	cout << ans << "\n";
	return 0;
}
