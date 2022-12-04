#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ost = tree<pair<int, int>, null_type, less<pair<int, int>>,
			rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		ll ans{};
		ost tree;
		for (int i = 0; i < N; ++i) {
			tree.insert({A[i], i});
			if (i % 2) {
				ans += (tree.find_by_order(i / 2)->first
						+ tree.find_by_order(i / 2 + 1)->first) / 2;
			} else {
				ans += tree.find_by_order(i / 2)->first;
			}		
		}
		cout << ans << "\n";
	}
	return 0;
}
