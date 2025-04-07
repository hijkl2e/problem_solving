#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

bool solve1(vector<int> &B) {
	for (int i = 0; i < 5; ++i) {
		if (B[i] != B[0] + i) {
			return false;
		}
	}
	return true;
}

vector<int> solve2(vector<int> B) {
	vector<int> ret(4);
	for (int i = 0, j = 1; i < 5; i = j++) {
		while (j < 5 && B[i] == B[j]) {
			++j;
		}
		if (j - i > 2) {
			ret[j - i == 3] = B[i];
		} else if (j - i == 2) {
			ret[ret[2] ? 3 : 2] = B[i];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<char> A(5);
	vector<int> B(5);
	for (int i = 0; i < 5; ++i) {
		string S;
		getline(cin, S);
		A[i] = S[0];
		B[i] = S[2] - '0';
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	bool f = solve1(B);
	vector<int> C = solve2(B);
	int ans{};
	if (A[0] == A[4] && f) {
		ans = B[4] + 900;
	} else if (C[0]) {
		ans = C[0] + 800;
	} else if (C[1] && C[2]) {
		ans = C[1] * 10 + C[2] + 700;
	} else if (A[0] == A[4]) {
		ans = B[4] + 600;
	} else if (f) {
		ans = B[4] + 500;
	} else if (C[1]) {
		ans = C[1] + 400;
	} else if (C[3]) {
		ans = C[3] * 10 + C[2] + 300;
	} else if (C[2]) {
		ans = C[2] + 200;
	} else {
		ans = B[4] + 100;
	}
	cout << ans << "\n";
	return 0;
}
