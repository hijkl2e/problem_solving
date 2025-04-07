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
	sort(A.begin(), A.end());
	for (auto &s : A) {
		string t = s;
		reverse(t.begin(), t.end());
		if (binary_search(A.begin(), A.end(), t)) {
			cout << s.size() << " " << s[s.size() / 2] << "\n";
			break;
		}
	}
	return 0;
}
