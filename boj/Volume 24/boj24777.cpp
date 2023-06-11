#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(12);
	for (int i = 0; i < 12; ++i) {
		cin >> A[i];
	}
	vector<iii> B;
	set<char> S;
	for (int i = 0; i < 12; ++i) {
		for (int j = i + 1; j < 12; ++j) {
			for (int k = j + 1; k < 12; ++k) {
				bool yes = true;
				for (int l = 0; l < 4; ++l) {
					S.clear();
					S.insert(A[i][l]);
					S.insert(A[j][l]);
					S.insert(A[k][l]);
					if (S.size() == 2) {
						yes = false;
						break;
					}
				}
				if (yes) {
					B.push_back({i + 1, j + 1, k + 1});
				}
			}
		}
	}
	if (B.empty()) {
		cout << "no sets\n";
	} else {
		for (auto &[i, j, k] : B) {
			cout << i << " " << j << " " << k << "\n";
		}
	}
	return 0;
}
