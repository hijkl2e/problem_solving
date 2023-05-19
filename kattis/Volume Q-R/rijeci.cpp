#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> fibo(K + 1);
	fibo[1] = 1;
	for (int i = 2; i <= K; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[K - 1] << " " << fibo[K] << "\n";
	return 0;
}
