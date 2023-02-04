#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

vector<int> A, B;
int ans;

ll pow(int x, int y) {
	ll ret = 1;
	while (y-- && ret < INF) {
		ret *= x;
	}
	return ret;
}

void solve(int sum, int now, int idx) {
	if (idx == A.size()) {
		sum += now;
		auto it = find(B.begin(), B.end(), sum);
		if (it != B.end()) {
			B.erase(it);
			++ans;
		}
		return;
	}
	solve(sum + now, A[idx], idx + 1);
	solve(sum, 10 * now + A[idx], idx + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		getline(cin, s);
		A.resize(s.size());
		for (int i = 0; i < A.size(); ++i) {
			A[i] = s[i] - '0';
		}
		if (count(A.begin(), A.end(), 0) + count(A.begin(), A.end(), 1) == A.size()) {
			cout << "Hello, BOJ 2023!\n";
			continue;
		}
		B.clear();
		for (int i = 1;; ++i) {
			ll sum{};
			for (int j = 0; j < A.size(); ++j) {
				sum += pow(A[j], i);
			}
			if (sum < INF) {
				B.push_back(sum);
			} else {
				break;
			}
		}
		ans = 0;
		solve(0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
