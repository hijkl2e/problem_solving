#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

vector<int> get_sa(string &S) {
	vector<si> A(S.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = {S.substr(i), i};
	}
	sort(A.begin(), A.end());
	vector<int> sa(A.size());
	for (int i = 0; i < sa.size(); ++i) {
		sa[i] = A[i].second;
	}
	return sa;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	string S(N, 'A');
	for (int i = 0; i < N; ++i) {
		S[A[i]] = 'A' + i;
	}
	vector<int> sa = get_sa(S);
	for (int i = 0; i < N; ++i) {
		int x = sa[i];
		while (S[x] > 'A') {
			--S[x];
			if (get_sa(S) != sa) {
				++S[x];
				break;
			}
		}
	}
	int ans = *max_element(S.begin(), S.end()) - 'A' + 1;
	cout << ans << "\n";
	return 0;
}
