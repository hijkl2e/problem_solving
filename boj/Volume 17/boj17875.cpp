#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<queue<string>> A(N);
	for (int i = 0; i < N; ++i) {
		int M{};
		cin >> M;
		while (M--) {
			string s;
			cin >> s;
			A[i].push(s);
		}
	}
	int P{};
	cin >> P;
	queue<string> q;
	while (P--) {
		string s;
		cin >> s;
		q.push(s);
	}
	set<string> used;
	vector<vector<string>> B(N, vector<string>(K));
	for (int j = 0; j < K; ++j) {
		for (int i = 0; i < N; ++i) {
			while (A[i].size() && used.count(A[i].front())) {
				A[i].pop();
			}
			if (A[i].size()) {
				B[i][j] = A[i].front();
				used.insert(A[i].front());
				A[i].pop();
				continue;
			}
			while (q.size() && used.count(q.front())) {
				q.pop();
			}
			B[i][j] = q.front();
			used.insert(q.front());
			q.pop();
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			cout << B[i][j] << (j == K - 1 ? "\n" : " ");
		}
	}
	return 0;
}
