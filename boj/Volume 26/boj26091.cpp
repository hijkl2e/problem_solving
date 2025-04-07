#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int S = 0, E = N - 1;
	int ans{};
	while (S < E) {
		if (A[S] + A[E] >= M) {
			++ans;
			--E;
		}
		++S;
	}
	cout << ans << "\n";
	return 0;
}
