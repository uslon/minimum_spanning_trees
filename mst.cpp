#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

const long long inf = 1e17;

using std::vector;
using std::set;
using std::pair;
using std::swap;
using std::cout;
using std::endl;

vector <vector <long long> > graph;
vector <pair <long long, pair <long long, long long> > > edges;

vector <int> dsu_par, dsu_rnk;
int n, m;

int get_par (int a) {
    if (dsu_par[a] == a)
        return a;
    return dsu_par[a] = get_par(dsu_par[a]);
}

void join (int a, int b) {
    if (dsu_rnk[a] > dsu_rnk[b])
        swap(a, b);
    dsu_rnk[b] += (dsu_rnk[a] == dsu_rnk[b]);
    dsu_par[a] = b;
}

int join (int a, int b, set <pair <long long, long long> > & sta, set <pair <long long, long long> > & stb) {
    if (dsu_rnk[a] > dsu_rnk[b]) {
        dsu_par[b] = a;
        sta.insert(stb.begin(), stb.end());
        stb.clear();
        return b;
    }
    else {
        dsu_par[a] = b;
        stb.insert(sta.begin(), sta.end());
        sta.clear();
        dsu_rnk[b] += (dsu_rnk[b] == dsu_rnk[a]);
        return a;
    }
}


void output_graph () {
    for (int j = 0; j < n; j++) {
        cout << j << ": ";
        for (int i = 0; i < graph[j].size(); i ++) {
            cout << graph[j][i] << ' ';
        }
        cout << '\n';
    }
}

void fill_graph (std::ifstream & fin) {
    graph.clear();
    fin >> n >> m;
    graph.resize(n);
    long long u, v, w;
    for (int j = 0; j < m; j++) {
        fin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        graph[u].push_back(w);
        graph[v].push_back(w);
    }
}

void fill_graph_edges (std::ifstream & fin) {
    fin >> n >> m;
    edges.clear();
    edges.resize(m);
    long long u, v, w;
    for (int j = 0; j < m; j++) {
        fin >> u >> v >> w;
        edges[j] = {w, {u, v}};
    }
}


long long count_mst_weight_prim (std::ifstream & fin) {
    cout << "Prim started\n";
    fill_graph(fin);
    set <pair <long long, long long> > st;
    vector <long long> min_dist(n, inf), from(n);
    vector <bool> used(n);
    min_dist[0] = 0;
    st.insert({0, 0});
    long long sum = 0;

    for (int j = 0; j < n; j++) {

        int v = st.begin()->second;
        sum += st.begin()->first;
        st.erase(st.begin());
        used[v] = true;

        for (int i = 0; i < graph[v].size(); i += 2) {
            int u = graph[v][i];
            int w = graph[v][i + 1];
            if (used[u])
                continue;

            if (min_dist[u] > w) {
                auto p = st.find({min_dist[u], u});
                if (p != st.end())
                    st.erase(p);
                min_dist[u] = w;
                st.insert({min_dist[u], u});
                from[u] = v;
            }
        }
    }
    return sum;
}


long long count_mst_weight_boruvka (std::ifstream & fin) {
    cout << "Boruvka started\n";
    long long sum = 0;
    fill_graph(fin);
    dsu_par.clear();
    dsu_rnk.clear();
    dsu_rnk.resize(n);
    dsu_par.resize(n);
    set <long long> trees, deleted;
    for (long long j = 0; j < n; ++j) {
        dsu_par[j] = j;
        trees.insert(j);
    }

    vector <set <pair <long long, long long> > > edges(n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < graph[j].size(); i += 2) {
            long long u = graph[j][i];
            long long w = graph[j][i + 1];
            edges[j].insert({w, u});
        }
    }

    while (trees.size() > 1) {
        auto it = trees.begin();
        while (it != trees.end()) {
            long long v = *it;
            auto jt = edges[v].begin();
            while (jt != edges[v].end() && get_par(jt->second) == v) {
                edges[v].erase(jt);
                jt = edges[v].begin();
            }

            if (edges[v].empty()) {
                ++it;
                continue;
            }

            sum += jt->first;
            long long u = get_par(jt->second);
            edges[v].erase(edges[v].begin());
            int erased = join(v, u, edges[v], edges[u]);
            deleted.insert(erased);
            ++it;
        }
        while (!deleted.empty()) {
            auto it = trees.find(*deleted.begin());
            //if (it != trees.end())
            trees.erase(it);
            deleted.erase(deleted.begin());
        }
    }
    return sum;
}


long long count_mst_weight_kruskal (std::ifstream & fin) {
    cout << "Kruskal started\n";
    long long sum = 0;
    fill_graph_edges(fin);
    sort(edges.begin(), edges.end());
    dsu_par.clear();
    dsu_rnk.clear();
    dsu_rnk.resize(n);
    dsu_par.resize(n);
    for (int j = 0; j < n; ++j)
        dsu_par[j] = j;

    int components = n;
    for (int j = 0; components > 1 && j < m; ++j) {
        auto p = edges[j];
        long long v = p.second.first, u = p.second.second, w = p.first;
        v = get_par(v);
        u = get_par(u);
        if (u == v)
            continue;
        sum += w;
        join(u, v);
        --components;
    }
    if (components > 1)
        throw "Graph is not connected!\n";

    return sum;
}



