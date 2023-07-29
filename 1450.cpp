#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int a, b, w;
};

vector<edge> v;

int main() {
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({.a = a - 1, .b = b - 1, .w = w});
    }

    int s, f;

    cin >> s >> f;
    s--;
    f--;

    vector<int> res(510, -1);

    res[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (res[v[j].a] != -1 && res[v[j].b] < res[v[j].a] + v[j].w) {
                res[v[j].b] = res[v[j].a] + v[j].w;
            }
        }
    }

    if (res[f] != -1) {
        cout << res[f];
    } else {
        cout << "No solution";
    }

    return 0;
}