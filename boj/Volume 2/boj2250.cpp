#include <bits/stdc++.h>

using namespace std;

vector<int> L, R, B, C;
int cnt;

void dfs(int x, int d) {
	if (x == 0) {
		return;
	}
	dfs(L[x], d + 1);
	B[d] = min(B[d], ++cnt);
	C[d] = max(C[d], cnt);
	dfs(R[x], d + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	L.resize(N + 1);
	R.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		int x{}, y{}, z{};
		cin >> x >> y >> z;
		L[x] = y == -1 ? 0 : y;
		R[x] = z == -1 ? 0 : z;
	}
	deque<bool> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[L[i]] = A[R[i]] = true;
	}
	int r = find(A.begin(), A.end(), false) - A.begin();
	B.assign(N + 1, 1e9);
	C.resize(N + 1);
	dfs(r, 1);
	for (int i = 1; i <= N; ++i) {
		C[i] -= B[i] - 1;
	}
	int ans = max_element(C.begin(), C.end()) - C.begin();
	cout << ans << " " << C[ans] << "\n";
	return 0;
}
