#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		S = "#" + S;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			A[i] = A[i - 1] + (S[i] == '(' ? 1 : -1);
		}
		vector<int> B(A.begin(), A.end());
		sort(B.begin(), B.end());
		ll ans{};
		for (int i = 0; i <= N; ++i) {
			ans += i * B[i];
		}
		map<int, int> prev;
		ll sum{};
		for (int i = 0; i <= N; ++i) {
			if (S[i] == ')') {
				sum -= i - prev[A[i]];
			}
			ans -= sum;
			sum += A[i];
			prev[A[i]] = i + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
