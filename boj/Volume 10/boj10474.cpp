#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		cout << N / M << " " << N % M << " / " << M << "\n";
	}
	return 0;
}
