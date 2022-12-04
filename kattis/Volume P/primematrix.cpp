#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 2, 3, 7, 11, 17, 23, 29, 37, 47, 59, 67, 79, 97, 107, 127,
		137, 157, 173, 191, 211, 233, 257, 277, 307, 331, 353, 379, 409,
		439, 467, 499, 541, 563, 599, 631, 673, 709, 743, 787, 821, 863,
		907, 947, 991, 1039, 1087, 1129, 1181, 1229, 1277
	};
	int N{}, B{};
	cin >> N >> B;
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		C[i] = i + 1;
	}
	int sum = N * (N + 1) / 2;
	for (int i = 0; sum + i < A[N]; ++i) {
		++C[N - i - 1];
	}
	if (C[N - 1] > B) {
		cout << "impossible\n";
	} else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << C[(i + j) % N] << (j == N - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
