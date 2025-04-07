#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(26);
	for (char c : A[0]) {
		++B[c - 'A'];
	}
	vector<int> C(26);
	int ans{};
	for (int i = 1; i < N; ++i) {
		copy(B.begin(), B.end(), C.begin());
		for (char c : A[i]) {
			--C[c - 'A'];
		}
		int x = count(C.begin(), C.end(), 1);
		int y = count(C.begin(), C.end(), -1);
		int z = count(C.begin(), C.end(), 0);
		if (z == 26 || (x + y == 1 && z == 25) || (x == 1 && y == 1 && z == 24)) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
