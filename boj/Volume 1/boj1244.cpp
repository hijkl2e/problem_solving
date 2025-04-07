#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		if (x == 1) {
			for (int i = y; i <= N; i += y) {
				A[i] ^= 1;
			}
		} else {
			A[y] ^= 1;
			for (int i = 1; 1 <= y - i && y + i <= N && A[y - i] == A[y + i]; ++i) {
				A[y - i] = A[y + i] = A[y + i] ^ 1;
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << (i == N || i % 20 == 0 ? "\n" : " ");
	}
	return 0;
}
