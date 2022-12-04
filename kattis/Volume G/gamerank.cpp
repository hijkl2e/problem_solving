#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(26);
	for (int i = 1; i < 26; ++i) {
		A[i] = min(6 - (i - 1) / 5, 5);
	}
	int rank = 25;
	int star{}, cnt{};
	string S;
	getline(cin, S);
	for (char c : S) {
		if (c == 'W') {
			star += 1 + (rank >= 6 && ++cnt >= 3);
			if (star > A[rank]) {
				star -= A[rank--];
				if (!rank) {
					break;
				}
			}
		} else {
			if (rank < 20) {
				if (!star--) {
					++rank;
					star = A[rank] - 1;
				}
			} else if (rank == 20) {
				star = max(star - 1, 0);
			}
			cnt = 0;
		}
	}
	if (rank) {
		cout << rank << "\n";
	} else {
		cout << "Legend\n";
	}
	return 0;
}
