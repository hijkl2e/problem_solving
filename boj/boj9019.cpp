#include <bits/stdc++.h>

using namespace std;

vector<int> D(10001);
vector<int> par(10001);
vector<int> cmd(10001);
queue<int> q;

void solve(int x, int p, int c) {
	if (D[x] == -1) {
		D[x] = D[p] + 1;
		par[x] = p;
		cmd[x] = c;
		q.push(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int A{}, B{};
		cin >> A >> B;
		fill(D.begin(), D.end(), -1);
		D[A] = 0;
		q.push(A);
		while (q.size()) {
			int x = q.front(); q.pop();
			solve(2 * x % 10000, x, 0);
			solve((x + 9999) % 10000, x, 1);
			solve(10 * x % 10000 + x / 1000, x, 2);
			solve(x / 10 + x % 10 * 1000, x, 3);
		}
		string s;
		while (A != B) {
			s += cmd[B] == 0 ? 'D' : cmd[B] == 1 ? 'S' : cmd[B] == 2 ? 'L' : 'R';
			B = par[B];
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
	return 0;
}
