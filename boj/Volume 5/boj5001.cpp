#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ost = tree<pair<int, int>, null_type, less<pair<int, int>>,
			rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ost tree;
	string tok;
	for (int i = 0; cin >> tok; ++i) {
		if (tok == "#") {
			auto it = tree.find_by_order(tree.size() / 2);
			cout << it->first << "\n";
			tree.erase(it);
		} else {
			int d = stoi(tok);
			tree.insert({d, i});
		}	
	}
	return 0;
}
