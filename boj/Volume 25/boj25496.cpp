#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int P{}, N{};
	cin >> P >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans{};
	while (ans < N && P < 200) {
		P += A[ans++];
	}
	cout << ans << "\n";
	return 0;
}
