#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	istringstream iss(s);
	int K{};
	while (iss >> s) {
		++K;
	}
	int N{};
	cin >> N;
	queue<string> q;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		q.push(s);
	}
	vector<string> A, B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K - 1; ++j) {
			q.push(q.front());
			q.pop();
		}
		s = q.front(); q.pop();
		if (i % 2 == 0) {
			A.push_back(s);
		} else {
			B.push_back(s);
		}
	}
	cout << A.size() << "\n";
	for (auto &s : A) {
		cout << s << "\n";
	}
	cout << B.size() << "\n";
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
