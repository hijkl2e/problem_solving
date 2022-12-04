#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ost = tree<iii, null_type, less<iii>,
			rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N + 1);
	ost tree;
	for (int i = 1; i <= N; ++i) {
		tree.insert({0, 0, i});
	}
	while (M--) {
		int t{}, p{};
		cin >> t >> p;
		tree.erase({A[t].first, A[t].second, t});
		--A[t].first;
		A[t].second += p;
		tree.insert({A[t].first, A[t].second, t});
		cout << tree.order_of_key({A[1].first, A[1].second, 1}) + 1 << "\n";
	}
	return 0;
}
