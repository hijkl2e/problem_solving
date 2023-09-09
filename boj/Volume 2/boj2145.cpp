#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		while (N >= 10) {
			int sum{};
			while (N) {
				sum += N % 10;
				N /= 10;
			}
			N = sum;
		}
		cout << N << "\n";
	}
	return 0;
}
