#include <bits/stdc++.h>

using namespace std;

void print(int x, int y) {
	cout << x;
	if (x < y) {
		cout << (x + 1 == y ? " " : "-") << y;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> chk(1e3 + 5);
	while (N--) {
		int x{};
		cin >> x;
		chk[x] = true;
	}
	int S = -1;
	for (int i = 1, j = 0; i < chk.size(); ++i) {
		if (chk[i]) {
			S = S == -1 ? i : S;
		} else if (S != -1) {
			if (j) {
				cout << " ";
			}
			print(S, i - 1);
			S = -1;
			++j;
		}
	}
	cout << "\n";
	return 0;
}
