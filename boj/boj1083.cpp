#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	for (int i = 0; i < N; ++i) {
		int p = i;
		for (int j = i + 1; j < N && j - i <= M; ++j) {
			if (A[p] < A[j]) {
				p = j;
			}
		}
		int x = A[p];
		A.erase(A.begin() + p);
		A.insert(A.begin() + i, x);
		M -= p - i;
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
