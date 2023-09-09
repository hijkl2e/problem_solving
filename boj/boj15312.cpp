#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1
	};
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<int> B(2 * s1.size());
	for (int i = 0; i < B.size(); ++i) {
		char c = i % 2 ? s2[i / 2] : s1[i / 2];
		B[i] = A[c - 'A'];
	}
	while (B.size() > 2) {
		vector<int> C(B.size() - 1);
		for (int i = 0; i < C.size(); ++i) {
			C[i] = (B[i] + B[i + 1]) % 10;
		}
		B = C;
	}
	int ans = 10 * B[0] + B[1];
	cout << setfill('0') << setw(2) << ans << "\n";
	return 0;
}
