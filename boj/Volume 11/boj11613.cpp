#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"xxx.xxx", "..x..x.", "x.xxx.x", "x.xx.xx", ".xxx.x.",
		"xx.x.xx", "xx.xxxx", "x.x..x.", "xxxxxxx", "xxxx.xx"
	};
	vector<string> B(7);
	for (int i = 0; i < 7; ++i) {
		getline(cin, B[i]);
	}
	string C;
	for (int i = 0; i < B[0].size(); i += 6) {
		string s;
		s += B[0][i + 2];
		s += B[1][i];
		s += B[1][i + 4];
		s += B[3][i + 2];
		s += B[5][i];
		s += B[5][i + 4];
		s += B[6][i + 2];
		auto it = find(A.begin(), A.end(), s);
		if (it == A.end()) {
			C += '+';
		} else {
			C += it - A.begin() + '0';
		}
	}
	istringstream iss(C);
	int a{}, b{};
	char c{};
	iss >> a >> c >> b;
	int res = a + b;
	C = to_string(res);
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < C.size(); ++j) {
			int x = C[j] - '0';
			if (i % 3) {
				cout << A[x][i / 3 * 3 + 1] << "..." << A[x][i / 3 * 3 + 2];
			} else {
				cout << (x == 1 || (i == 3 && x == 7) || (i == 6 && x % 3 == 1) ? "." : "x");
				cout << string(3, A[x][i]) << "x";
			}
			cout << (j == C.size() - 1 ? "\n" : ".");
		}
	}
	return 0;
}
