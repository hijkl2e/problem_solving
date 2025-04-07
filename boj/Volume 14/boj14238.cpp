#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int, int>;

string B[51][51][51][3][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(3);
	for (char c : S) {
		++A[c - 'A'];
	}
	string ans = "-1";
	queue<rec> q;
	q.push({S.size(), A[0], A[1], 0, 0});
	while (q.size()) {
		auto [a, b, c, d, e] = q.front(); q.pop();
		if (a == 0) {
			ans = B[a][b][c][d][e];
			break;
		}
		if (b && B[a - 1][b - 1][c][e][0] == "") {
			B[a - 1][b - 1][c][e][0] = B[a][b][c][d][e] + "A";
			q.push({a - 1, b - 1, c, e, 0});
		}
		if (c && e != 1 && B[a - 1][b][c - 1][e][1] == "") {
			B[a - 1][b][c - 1][e][1] = B[a][b][c][d][e] + "B";
			q.push({a - 1, b, c - 1, e, 1});
		}
		if (a - b - c && d != 2 && e != 2 && B[a - 1][b][c][e][2] == "") {
			B[a - 1][b][c][e][2] = B[a][b][c][d][e] + "C";
			q.push({a - 1, b, c, e, 2});
		}
	}
	cout << ans << "\n";
	return 0;
}
