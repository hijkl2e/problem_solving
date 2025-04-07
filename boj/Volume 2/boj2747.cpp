#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> fibo(N + 1);
	fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N] << "\n";
	return 0;
}
