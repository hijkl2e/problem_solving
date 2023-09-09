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
	string ans;
	int p = find(A.begin(), A.end(), "KBS2") - A.begin();
	ans += string(p, '1') + string(p, '4');
	rotate(A.begin(), A.begin() + p, A.begin() + p + 1);
	p = find(A.begin(), A.end(), "KBS1") - A.begin();
	ans += string(p, '1') + string(p, '4');
	cout << ans << "\n";
	return 0;
}
