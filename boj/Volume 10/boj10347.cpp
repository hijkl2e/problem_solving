#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<char> A;
	A.reserve(28);
	for (char c = 'A'; c <= 'Z'; ++c) {
		A.push_back(c);
	}
	A.push_back('_');
	A.push_back('.');
	int N{};
	while (cin >> N, N) {
		map<char, char> c2c;
		for (int i = 0; i < 28; ++i) {
			c2c[A[i]] = A[(i + N) % 28];
		}
		string S;
		cin >> S;
		reverse(S.begin(), S.end());
		for (char c : S) {
			cout << c2c[c];
		}
		cout << "\n";
	}
	return 0;
}
