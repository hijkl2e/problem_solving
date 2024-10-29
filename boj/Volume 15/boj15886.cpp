#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;
int ans;

void dfs(int x) {
	B[x] = 1;
	int nx = x + A[x];
	if (B[nx] == 0) {
		dfs(nx);
	} else if (B[nx] == 1) {
		++ans;
	}
	B[x] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		A[i] = (S[i] == 'E' ? 1 : -1);
	}
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		if (B[i] == 0) {
			dfs(i);
		}
	}
	cout << ans << "\n";
	return 0;
}
