#include <bits/stdc++.h>

using namespace std;

int v2i(vector<int> &A) {
	int ret{};
	for (int i = 0; i < A.size(); ++i) {
		ret = 8 * ret + A[i];
	}
	return ret;
}

vector<int> i2v(int N, int x) {
	vector<int> A(N);
	for (int i = N - 1; i >= 0; --i) {
		A[i] = x % 8;
		x /= 8;
	}
	return A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		--A[i];
	}
	int s = v2i(A);
	map<int, int> D;
	queue<int> q;
	D[s] = 0;
	q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		int d = D[x];
		A = i2v(N, x);
		for (int i = 0; i + K <= N; ++i) {
			reverse(A.begin() + i, A.begin() + i + K);
			int y = v2i(A);
			if (D.insert({y, d + 1}).second) {
				q.push(y);
			}
			reverse(A.begin() + i, A.begin() + i + K);
		}
	}
	for (int i = 0; i < N; ++i) {
		A[i] = i;
	}
	auto it = D.find(v2i(A));
	cout << (it == D.end() ? -1 : it->second) << "\n";
	return 0;
}
