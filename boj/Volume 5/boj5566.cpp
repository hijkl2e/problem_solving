#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(2001);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int ans{}, p = 1;
	while (p < N) {
		int x{};
		cin >> x;
		p += x;
		p += A[p];
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
