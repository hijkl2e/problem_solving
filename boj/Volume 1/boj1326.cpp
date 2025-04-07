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
	int a{}, b{};
	cin >> a >> b;
	--a, --b;
	vector<int> D(N, -1);
	queue<int> q;
	D[a] = 0;
	q.push(a);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = x + A[x]; i < N; i += A[x]) {
			if (D[i] == -1) {
				D[i] = D[x] + 1;
				q.push(i);
			}
		}
		for (int i = x - A[x]; i >= 0; i -= A[x]) {
			if (D[i] == -1) {
				D[i] = D[x] + 1;
				q.push(i);
			}
		}
	}
	cout << D[b] << "\n";
	return 0;
}
