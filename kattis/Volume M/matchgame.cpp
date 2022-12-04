#include <bits/stdc++.h>

using namespace std;

using cc = pair<char, char>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string X, Y;
	cin >> X >> Y;
	vector<cc> A{
		{'1', '7'}, {'3', '9'}, {'5', '6'}, {'5', '9'}, {'0', '8'}, {'6', '8'}, {'9', '8'}
	};
	vector<cc> B{
		{'2', '3'}, {'3', '5'}, {'0', '6'}, {'0', '9'}, {'6', '9'}
	};
	vector<int> C;
	bool yes = true;
	for (int i = 0; i < X.size(); ++i) {
		if (X[i] == Y[i]) {
			continue;
		}
		int x{};
		for (auto &p : A) {
			if (make_pair(X[i], Y[i]) == p) {
				x = 1;
				break;
			} else if (make_pair(Y[i], X[i]) == p) {
				x = -1;
				break;
			}
		}
		if (x) {
			C.push_back(x);
			continue;
		}
		if (X[i] > Y[i]) {
			swap(X[i], Y[i]);
		}
		for (auto &p : B) {
			if (make_pair(X[i], Y[i]) == p) {
				x = 1;
				break;
			}
		}
		if (x) {
			C.push_back(1);
			C.push_back(-1);
		} else {
			yes = false;
			break;
		}
	}
	yes &= C.size() == 2 && C[0] + C[1] == 0;
	cout << (yes ? "yes" : "no") << "\n";
	return 0;
}
