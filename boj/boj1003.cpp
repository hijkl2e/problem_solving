#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> fibo(42);
	fibo[0] = 1;
	for (int i = 2; i < fibo.size(); ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << fibo[N] << " " << fibo[N + 1] << "\n";
	}
	return 0;
}
