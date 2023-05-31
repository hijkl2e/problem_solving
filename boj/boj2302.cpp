#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M + 2);
	for (int i = 1; i <= M; ++i) {
		cin >> A[i];
	}
	A[M + 1] = N + 1;
	vector<int> fibo(N + 1);
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int ans = 1;
	for (int i = 0; i <= M; ++i) {
		ans *= fibo[A[i + 1] - A[i] - 1];
	}
	cout << ans << "\n";
	return 0;
}
