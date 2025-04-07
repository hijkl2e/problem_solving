#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	S += " " + S;
	string T = S;
	for (int i = 0; i < T.size(); i += 2) {
		T[i] = (T[i] - '1' + 2) % 4 + '1';
	}
	reverse(T.begin(), T.end());
	int M{};
	cin >> M;
	cin.ignore();
	vector<string> A(M);
	for (int i = 0; i < M; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B;
	for (int i = 0; i < M; ++i) {
		if (S.find(A[i]) != -1 || T.find(A[i]) != -1) {
			B.push_back(i);
		}
	}
	cout << B.size() << "\n";
	for (int k : B) {
		cout << A[k] << "\n";
	}
	return 0;
}
