#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> fibo(N + 1);
	fibo[1] = fibo[2] = 1;
	for (int i = 3; i <= N; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N] << " " << N - 2 << "\n";
	return 0;
}
