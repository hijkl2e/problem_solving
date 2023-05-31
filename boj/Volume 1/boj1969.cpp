#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	string ans(M, 'X');
	int cnt{};
	for (int i = 0; i < M; ++i) {
		vector<int> B(4);
		for (int j = 0; j < N; ++j) {
			char c = A[j][i];
			++B[c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3];
		}
		int x = max_element(B.begin(), B.end()) - B.begin();
		ans[i] = "ACGT"[x];
		cnt += N - B[x];
	}
	cout << ans << "\n" << cnt << "\n";
	return 0;
}
