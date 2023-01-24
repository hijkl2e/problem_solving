#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ll> A(N + 50);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N + 50);
	for (int i = 0; i < B.size() - 1; ++i) {
		B[i] = A[i] / K;
		A[i] %= K;
		A[i + 1] += B[i];
	}
	string ans;
	for (int i = A.size() - 2; i >= 0; --i) {
		A[i] += min(A[i + 1] % M, B[i]) * K;
		char c = A[i] / M + '0';
		if (ans.size() || c > '0' || i == 0) {
			ans += c;
		}
	}
	cout << ans << "\n";
	return 0;
}
