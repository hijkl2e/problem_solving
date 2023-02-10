#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

void func(stack<ll> &st, ll x, bool add) {
	if (st.size() && st.top() != -1) {
		ll &y = st.top();
		if (add) {
			y = (x + y) % MOD;
		} else {
			y = (x * y) % MOD;
		}
	} else {
		st.push(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	stack<ll> st;
	bool add = true;
	while (N--) {
		string s;
		cin >> s;
		if (s[0] == '(') {
			st.push(-1);
			add ^= true;
		} else if (s[0] == ')') {
			add ^= true;
			ll x = st.top();
			st.pop(); st.pop();
			func(st, x, add);
		} else {
			func(st, stoi(s), add);
		}
	}
	cout << st.top() << "\n";
	return 0;
}
