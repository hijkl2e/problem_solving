#include <bits/stdc++.h>

using namespace std;

vector<int> B(5);

int cnt(int x) {
	return x * count(B.begin(), B.end(), x);
}

int ones() {
	return cnt(1);
}

int twos() {
	return cnt(2);
}

int threes() {
	return cnt(3);
}

int fours() {
	return cnt(4);
}

int fives() {
	return cnt(5);
}

int sixes() {
	return cnt(6);
}

int four_of_a_kind() {
	return 4 * (B[0] == B[3] ? B[0] : B[1] == B[4] ? B[1] : 0);
}

int choice() {
	return accumulate(B.begin(), B.end(), 0);
}

int full_house() {
	return B[0] == B[1] && B[3] == B[4] && ((B[1] == B[2]) ^ (B[2] == B[3])) ? choice() : 0;
}

int little_straight() {
	return B[0] == 1 && B[1] == 2 && B[2] == 3 && B[3] == 4 && B[4] == 5 ? 30 : 0;
}

int big_straight() {
	return B[0] == 2 && B[1] == 3 && B[2] == 4 && B[3] == 5 && B[4] == 6 ? 30 : 0;
}

int yacht() {
	return B[0] == B[4] ? 50 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	vector<function<int ()>> F{
		ones, twos, threes, fours, fives, sixes, four_of_a_kind,
		full_house, little_straight, big_straight, yacht, choice
	};
	int ans{};
	for (int i = 1; i < 7; ++i) {
		for (int j = 1; j < 7; ++j) {
			copy(A.begin(), A.end(), B.begin());
			B[3] = i, B[4] = j;
			sort(B.begin(), B.end());
			for (int k = 0; k < 12; ++k) {
				if (s[k] == 'Y') {
					ans = max(ans, F[k]());
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
