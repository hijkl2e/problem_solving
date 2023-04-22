#include <bits/stdc++.h>

using namespace std;

vector<char> A;
vector<int> B;

bool solve() {
	for (int i = 0; i < A.size(); ++i) {
		if ((A[i] == '<') ^ (B[i] < B[i + 1])) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	A.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i];
	}
	B.resize(K + 1);
	for (int i = 0; i <= K; ++i) {
		B[i] = 9 - i;
	}
	while (!solve() && prev_permutation(B.begin(), B.end()));
	for (int i = 0; i <= K; ++i) {
		cout << B[i];
	}
	cout << "\n";
	for (int i = 0; i <= K; ++i) {
		B[i] = i;
	}
	while (!solve() && next_permutation(B.begin(), B.end()));
	for (int i = 0; i <= K; ++i) {
		cout << B[i];
	}
	cout << "\n";
	return 0;
}
