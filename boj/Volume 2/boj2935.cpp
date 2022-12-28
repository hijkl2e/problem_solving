#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	char op{};
	cin >> A >> op >> B;
	string ans;
	if (op == '+') {
		ans = max(A, B);
		if (A.size() == B.size()) {
			ans[0] = '2';
		} else {
			ans[ans.size() - min(A, B).size()] = '1';
		}
	} else {
		ans = string(A.size() + B.size() - 1, '0');
		ans[0] = '1';
	}
	cout << ans << "\n";
	return 0;
}
