#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 10; i <= N; i *= 10) {
		if (N / (i / 10) % 10 > 4) {
			N += i;
		}
		N -= N % i;
	}
	cout << N << "\n";
	return 0;
}
