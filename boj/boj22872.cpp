#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<ii> A;

void move(int a, int b) {
	A.push_back({a, b});
}

void solve(int t, int n, int a, int b) {
	int c = a ^ b;
	if (n == 0) {
		return;
	} else if (n == 1) {
		if (t == 5) move(a, c);
		move(a, b);
		if (t == 6) move(c, b);
		return;
	}
	if (t == 1) {
		solve(2, n - 1, a, c);
		move(a, b);
		solve(3, n - 1, c, b);
	} else if (t == 2 || t == 3) {
		solve(t == 2 ? 2 : 4, n - 2, a, c);
		move(a, b), move(a, b);
		solve(t == 3 ? 3 : 4, n - 2, c, b);
	} else if (t == 4) {
		if (n == 2) {
			move(a, c), move(a, b), move(c, b);
			return;
		}
		solve(5, n - 1, a, c);
		n % 4 < 2 ? move(a, b) : move(b, a);
		solve(6, n - 1, c, b);
	} else if (t == 5) {
		if (n == 2) {
			move(a, b), move(a, c), move(a, b);
			return;
		}
		solve(4, n - 2, a, b);
		move(a, c), move(a, c);
		solve(4, n - 3, b, c);
		move(a, b);
		solve(5, n - 2, c, b);
	} else {
		if (n == 2) {
			move(a, b), move(c, b), move(a, b);
			return;
		}
		solve(6, n - 2, a, c);
		move(a, b);
		solve(4, n - 3, c, a);
		move(c, b), move(c, b);
		solve(4, n - 2, a, b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	solve(1, N, 1, 3);
	cout << A.size() << "\n";
	for (auto &p : A) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
