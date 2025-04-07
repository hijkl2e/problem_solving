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
	ll N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ost tree;
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		int x = tree.order_of_key(A[i]);
		if (x < i && K <= i - x + 1) {
			if (K == i - x + 1) {
				ans = A[i];
			} else {
				sort(A.begin(), A.begin() + i);
				ans = A[i - K];
			}
			break;
		}
		K -= x == i ? 0 : (i - x + 1);
		tree.insert(A[i]);
	}
	cout << ans << "\n";
	return 0;
}
