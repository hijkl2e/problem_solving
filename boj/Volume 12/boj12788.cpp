#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.rbegin(), A.rend());
	int X = M * K;
	int ans{}, sum{};
	while (ans < N && sum < X) {
		sum += A[ans++];
	}
	if (sum < X) {
		cout << "STRESS\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
