#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N = (N + 1) * (N + 2) / 2;
	cout << N * N << "\n";
	return 0;
}
