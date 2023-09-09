#include <bits/stdc++.h>

using namespace std;

bool cmp(string &s1, string &s2) {
	return s1 + s2 > s2 + s1;
}

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
	priority_queue<string, vector<string>, decltype(&cmp)> pq(cmp);
	for (auto &s : A) {
		pq.push(s);
	}
	string ans;
	while (pq.size()) {
		string s = pq.top(); pq.pop();
		ans += s[0];
		if (s.size() == 1) {
			continue;
		}
		s.erase(s.begin());
		pq.push(s);
	}
	cout << ans << "\n";
	return 0;
}
