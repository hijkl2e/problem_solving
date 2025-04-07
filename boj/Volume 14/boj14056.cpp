#include <bits/stdc++.h>

using namespace std;

bool find(const string &s1, const string &s2) {
	for (int i = 0, j = 0; i < s1.size(); ++i) {
		if (s1[i] == s2[j] && ++j == s2.size()) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int K{};
	getline(cin, S);
	cin >> K;
	queue<string> q;
	if (find(S, "()")) {
		q.push("()");
	}
	vector<string> A;
	while (q.size()) {
		string s = q.front(); q.pop();
		string t = s;
		while (true) {
			string u = "(" + t + ")";
			if (find(S, u)) {
				q.push(u);
			} else {
				break;
			}
			t += s;
		}
		A.push_back(s);
	}
	sort(A.begin(), A.end());
	if (A.size() < K) {
		cout << "-1\n";
	} else {
		cout << A[K - 1] << "\n";
	}
	return 0;
}
