#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ii = pair<int, int>;
using ost = tree<ii, null_type, less<ii>,
			rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{}, Q{};
	cin >> N >> S >> Q;
	vector<ii> A(N + 1);
	ost tree;
	for (int i = 1; i <= N; ++i) {
		A[i] = {0, -i};
		tree.insert(A[i]);
	}
	for (int i = 0; i < Q; ++i) {
		int x{};
		cin >> x;
		tree.erase(A[x]);
		--A[x].first;
		A[x].second = i;
		tree.insert(A[x]);
		int y = tree.order_of_key(A[1]) + 1;
		cout << y << " ";
		cout << (y <= S ? 0 : (A[1].first - tree.find_by_order(S - 1)->first + 1)) << "\n";
	}
	return 0;
}
