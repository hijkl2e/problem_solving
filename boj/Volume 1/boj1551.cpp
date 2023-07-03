#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s, ',');
		A[i] = stoi(s);
	}
	while (K--) {
		for (int i = 0; i < A.size() - 1; ++i) {
			A[i] = A[i + 1] - A[i];
		}
		A.erase(--A.end());
	}
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : ",");
	}
	return 0;
}
