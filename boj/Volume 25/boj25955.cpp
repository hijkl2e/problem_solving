#include <bits/stdc++.h>

using namespace std;

map<char, int> t2i;

bool solve(string &s1, string &s2) {
	int t1 = t2i[s1[0]];
	int t2 = t2i[s2[0]];
	return t1 < t2 || (t1 == t2 && stoi(s1.substr(1)) > stoi(s2.substr(1)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	t2i = {{'B', 0}, {'S', 1}, {'G', 2}, {'P', 3}, {'D', 4}};
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j > i; --j) {
			if (!solve(A[i], A[j])) {
				cout << "KO\n";
				cout << A[j] << " " << A[i] << "\n";
				return 0;
			}
		}
	}
	cout << "OK\n";
	return 0;
}
