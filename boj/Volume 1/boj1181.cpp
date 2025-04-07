#include <bits/stdc++.h>

using namespace std;

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
	sort(A.begin(), A.end(), [](string &s1, string &s2) {
		return s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2);
	});
	A.resize(unique(A.begin(), A.end()) - A.begin());
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
