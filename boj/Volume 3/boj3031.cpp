#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		vector<int> A(5);
		vector<int> B(5);
		for (int i = 0; i < 5; ++i) {
			string s;
			cin >> s;
			A[i] = s == "?" ? -1 : stoi(s);
		}
		for (int i = 0; i < 101; ++i) {
			for (int j = 0; i + j < 101; ++j) {
				B[0] = i + j == 100 ? 100 : A[0] == -1 ? i + j + A[3] : A[0];
				B[1] = i;
				B[2] = j;
				B[3] = B[0] - i - j;
				B[4] = 3 * i + j;
				bool yes = B[0] < 101 && B[3] >= 0;
				for (int i = 0; i < 5; ++i) {
					yes &= A[i] == -1 || A[i] == B[i];
				}
				if (yes) {
					i = 101;
					break;
				}
			}
		}
		for (int i = 0; i < 5; ++i) {
			cout << B[i] << (i == 4 ? "\n" : " ");
		}
	}
	return 0;
}
