#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ost = tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		C[B[i]] = i;
	}
	ost tree;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ll x = tree.order_of_key(C[A[i]]);
		ans += x * (N + x - i - C[A[i]] - 1);
		tree.insert(C[A[i]]);
	}
	if (ans) {
		cout << "My heart has gone to paradise\n";
		cout << ans << "\n";
	} else {
		cout << "Attention is what I want\n";
	}
	return 0;
}
