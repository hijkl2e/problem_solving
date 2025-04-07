#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N % 2 && M == 1) {
		cout << "-1\n";
		return 0;
	}
	cout << M << "\n";
	if (N % 2) {
		cout << "1 3";
		for (int i = N - 2 * M + 4; i < N; i += 2) {
			cout << " " << i;
		}
	} else if (M == 1) {
		cout << "2";
	} else if (M == 2) {
		cout << "2 " << N - 2;
	} else {
		cout << "1 3 ";
		for (int i = N - 2 * M + 5; i < N - 1; i += 2) {
			cout << i << " ";
		}
		cout << N;
	}
	cout << "\n";
	return 0;
}
