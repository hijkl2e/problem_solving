#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> tab{
		3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1
	};
	int N{}, M{};
	cin >> N >> M;
	string a, b;
	cin >> a >> b;
	vector<int> A;
	for (int i = 0; i < N || i < M; ++i) {
		if (i < N) {
			A.push_back(tab[a[i] - 'A']);
		}
		if (i < M) {
			A.push_back(tab[b[i] - 'A']);
		}
	}
	while (A.size() > 2) {
		vector<int> B(A.size() - 1);
		for (int i = 0; i < A.size() - 1; ++i) {
			B[i] = (A[i] + A[i + 1]) % 10;
		}
		swap(A, B);
	}
	int ans = 10 * A[0] + A[1];
	cout << ans << "%\n";
	return 0;
}
