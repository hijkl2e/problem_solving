#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int D{}, K{};
	cin >> D >> K;
	vector<int> fibo(D + 1);
	fibo[0] = 1;
	for (int i = 2; i <= D; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int ans_x{}, ans_y{};
	for (int i = 1;; ++i) {
		if ((K - i * fibo[D - 1]) % fibo[D] == 0) {
			ans_x = i;
			ans_y = (K - i * fibo[D - 1]) / fibo[D];
			break;
		}
	}
	cout << ans_x << "\n" << ans_y << "\n";
	return 0;
}
