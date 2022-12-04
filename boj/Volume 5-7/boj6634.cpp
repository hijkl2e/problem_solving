#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ",
		"-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"
	};
	string S;
	while (getline(cin, S)) {
		if (S == "end") {
			cout << S << "\n";
			break;
		}
		for (int i = 0; i < 7; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (j == 2) {
					cout << (i == 2 || i == 4 ? "o  " : "   ");
					continue;
				}
				int idx = S[j] - '0';
				if (i % 3) {
					cout << A[idx][i / 3 * 3 + 1] << "   " << A[idx][i / 3 * 3 + 2];
				} else {
					cout << (idx == 1 || (i == 3 && idx == 7) || (i == 6 && idx % 3 == 1) ? " " : "+");
					cout << string(3, A[idx][i]) << "+";
				}
				cout << (j == 4 ? "\n" : "  ");
			}
		}
		cout << "\n\n";
	}
	return 0;
}
