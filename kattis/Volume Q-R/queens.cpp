#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> row(N);
	deque<bool> col(N);
	deque<bool> d1(2 * N - 1);
	deque<bool> d2(2 * N - 1);
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		row[x] = col[y] = true;
		d1[x + y] = d2[x - y + N - 1] = true;
	}
	bool yes = true;
	yes &= accumulate(row.begin(), row.end(), 0) == N;
	yes &= accumulate(col.begin(), col.end(), 0) == N;
	yes &= accumulate(d1.begin(), d1.end(), 0) == N;
	yes &= accumulate(d2.begin(), d2.end(), 0) == N;
	cout << (yes ? "CORRECT" : "INCORRECT") << "\n";
	return 0;
}
