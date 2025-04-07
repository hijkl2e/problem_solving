#include <bits/stdc++.h>

using namespace std;

using cc = pair<char, char>;

char make_char(int k) {
	char c{};
	if (k < 26) {
		c = k + 'A';
	} else {
		c = k - 26 + 'a';
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<deque<bool>> A(52, deque<bool>(52));
	while (N--) {
		char c{}, d{};
		string s;
		cin >> c >> s >> d;
		int x = (c >= 'a' ? (c - 'a' + 26) : (c - 'A'));
		int y = (d >= 'a' ? (d - 'a' + 26) : (d - 'A'));
		A[x][y] = true;
	}
	for (int k = 0; k < 52; ++k) {
		for (int i = 0; i < 52; ++i) {
			for (int j = 0; j < 52; ++j) {
				A[i][j] |= A[i][k] && A[k][j];
			}
		}
	}
	vector<cc> B;
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 52; ++j) {
			if (i == j || !A[i][j]) {
				continue;
			}
			B.push_back({make_char(i), make_char(j)});
		}
	}
	cout << B.size() << "\n";
	for (auto &[c, d] : B) {
		cout << c << " => " << d << "\n";
	}
	return 0;
}
