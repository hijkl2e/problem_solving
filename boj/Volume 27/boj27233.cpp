#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N;
stack<ii> st;

void solve(vector<int> &A, int x, int y) {
	vector<int> B;
	for (int i = y; i < N; ++i) {
		B.push_back(A[i]);
	}
	for (int i = x; i < y; ++i) {
		B.push_back(A[i]);
	}
	for (int i = 0; i < x; ++i) {
		B.push_back(A[i]);
	}
	A = B;
	st.push({N - y, N - x});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	while (true) {
		int p1{};
		while (p1 + 1 < N && A[p1] % N + 1 == A[p1 + 1]) {
			++p1;
		}
		if (p1 == N - 1) {
			p1 = find(A.begin(), A.end(), 1) - A.begin();
			if (p1) {
				solve(A, p1, p1);
			}
			break;
		}
		int p2 = find(A.begin(), A.end(), A[0] == 1 ? N : (A[0] - 1)) - A.begin();
		solve(A, p1 + 1, (p2 == N - 1 ? p1 : p2) + 1);
	}
	cout << st.size() << "\n";
	while (st.size()) {
		auto [x, y] = st.top(); st.pop();
		if (x == y) {
			cout << "2 " << x << "\n";
		} else {
			cout << "3 " << x << " " << y << "\n";
		}
	}
	return 0;
}
