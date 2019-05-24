#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>

#include "fibonacci/fibonacci.hpp"

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

long long power (long long a, long long b) {
    if (!b)
        return (a != 0);

    if (b & 1)
        return power(a, b - 1) * a;

    long long y = power(a, b >> 1);
    return y * y;
}

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

void output_vector (vector <int> & vect) {
    cout << "\n=====\n";
    cout << vect.size() << '\n';
    for (int j = 0; j < vect.size(); ++j) {
        cout << vect[j] << ' ';
    }
    cout << "\n=====\n";
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

void fill_graph_boruvka (std::ifstream & fin, vector <set <pair <long long, long long> > > & edges) {
    fin >> n >> m;
    edges.resize(n);
    long long u, v, w;
    for (int j = 0; j < m; j++) {
        fin >> u >> v >> w;
        edges[u].insert({w, v});
        edges[v].insert({w, u});
    }
}


long long count_mst_weight_prim (std::ifstream & fin) {
    cout << "Prim started\n";
    fill_graph(fin);
    set <pair <long long, long long> > st;
    vector <long long> min_dist(n, inf);
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
            }
        }
    }
    return sum;
}


long long count_mst_weight_boruvka (std::ifstream & fin) {
    cout << "Boruvka started\n";
    long long sum = 0;
    vector <set <pair <long long, long long> > > edges;
    fill_graph_boruvka(fin, edges);
    dsu_par.clear();
    dsu_rnk.clear();
    dsu_rnk.resize(n);
    dsu_par.resize(n);
    set <long long> trees, deleted;
    for (long long j = 0; j < n; ++j) {
        dsu_par[j] = j;
        trees.insert(j);
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


void run_prim(int v, int max_heap_size, int current_components_amount, vector <bool> & used, vector <pair <int, int> > & connections, long long & sum) {
    FibonacciHeap <pair <long long, long long> > fh;
    std::unordered_map <long long, long long> dist;
    std::unordered_map <int, node <pair <long long, long long> > * > nodes(current_components_amount);
    std::unordered_map <long long, bool> used_in_prim;
    used[v] = used_in_prim[v] = true;

    int heap_size = 1;
    fh.insert({0, v});

    long long u, w;
    do {
        auto p = fh.removeMinimum();
        --heap_size;
        u = p.second, w = p.first;
        sum += w;
        connections.push_back({u, v});

        if (used[u] && u != v) {
            return;
        }
        used[u] = used_in_prim[u] = true;
;
        for (int j = 0; j < graph[u].size(); j += 2) {
            long long to = graph[u][j];
            //cout << to << ' ';
            if (used_in_prim[to])
                continue;

            w = graph[u][j + 1];
            if (dist.find(to) == dist.end()) {
                ++heap_size;
                nodes[to] = fh.insert({w, to});
                dist[to] = w;
            }
            else if (dist[to] > w) {
                fh.decreaseKey(nodes[to], {w, to});
                dist[to] = w;
            }
        }

    } while ((u == v || heap_size <= max_heap_size) && heap_size > 0);
}


void update_components (vector <pair <int, int> > & connections, vector <int> & old_components, vector <int> & new_components) {
    for (int j = 0; j < connections.size(); ++j) {
        int u = get_par(connections[j].first);
        int v = get_par(connections[j].second);
        join(u, v);
    }
    connections.clear();

    std::unordered_map <int, vector <int> > tree(old_components.size());

    for (int j = 0; j < old_components.size(); ++j) {
        int v = old_components[j];
        int u = get_par(v);
        tree[u].push_back(v);
    }

    new_components.clear();
    for (int j = 0; j < old_components.size(); j++) {
        int v = old_components[j];
        if (tree[v].empty())
            continue;

        new_components.push_back(v);
        std::unordered_map <int, long long> dist;
        for (int i = 0; i < tree[v].size(); ++i) {
            int u = tree[v][i];
            for (int k = 0; k < graph[u].size(); k += 2) {
                long long to = get_par(graph[u][k]), w = graph[u][k + 1];
                if (to == v)
                    continue;

                if (dist.find(to) != dist.end())
                    dist[to] = std::min(dist[to], w);
                else
                    dist[to] = w;
            }
            graph[u].clear();
        }
        graph[v].clear();
        for (auto it = dist.begin(); it != dist.end(); ++it) {
            graph[v].push_back(it->first);
            graph[v].push_back(it->second);
        }
    }

    old_components.clear();
    old_components = std::move(new_components);
}

long long count_mst_weight_log_star (std::ifstream & fin) {
    cout << "Log star launched\n";

    fill_graph(fin);

    vector <int> old_components(n), new_components;
    vector <bool> used;
    dsu_par.clear();
    dsu_rnk.clear();
    used.clear();
    dsu_par.resize(n);
    dsu_rnk.resize(n);
    used.resize(n);

    for (int j = 0; j < n; ++j) {
        old_components[j] = dsu_par[j] = j;
    }


    vector <pair <int, int> > connections;
    long long sum = 0, max_heap_size = 2;
    while (old_components.size() > 1) {
        //cout << max_heap_size << '\n';
        for (int j = 0; j < old_components.size(); ++j) {
            int v = old_components[j];
            if (used[v])
                continue;

            run_prim(v, max_heap_size, old_components.size(), used, connections, sum);
        }
        max_heap_size = power(2, max_heap_size);
        update_components(connections, old_components, new_components);
        for (int j = 0; j < old_components.size(); ++j)
            used[old_components[j]] = false;

    }
    return sum;
}
