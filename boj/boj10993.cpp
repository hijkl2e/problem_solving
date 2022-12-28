#include <bits/stdc++.h>

using namespace std;

vector<string> A;

void solve(int x, int y, int sz) {
	if (sz == 1) {
		A[x][y] = '*';
		return;
	}
	int z = 1;
	int szp = 1 << sz;
	if (sz % 2) {
		x += szp - 2;
		z = -1;
	}
	for (int i = 0; i < 2 * szp - 3; ++i) {
		A[x][y + i] = '*';
	}
	for (int i = 1; i < szp - 1; ++i) {
		A[x + z * i][y + i] = A[x + z * i][y - i + 2 * szp - 4] = '*';
	}
	solve(x - (sz % 2 ? szp / 2 : 0) + 1, y + szp / 2, sz - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign((1 << N) - 1, string((2 << N) - 3, ' '));
	solve(0, 0, N);
	for (auto &s : A) {
		while (s.back() == ' ') {
			s.erase(s.size() - 1);
		}
		cout << s << "\n";
	}
	return 0;
}
