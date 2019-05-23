#include <iostream>
#include <random>
#include "../jngen/jngen.h"

using std::string;

const string path_to_generator = "/home/amir/Documents/Algorithms/MST/generate_graphs/";
const string path_to_tests_dir = "/home/amir/Documents/Algorithms/MST/tests/";
const string path_to_answers_dir = "/home/amir/Documents/Algorithms/MST/answers/";
int number_of_edges = 3000, number_of_verticies = 1000, max_weight = 1000000;
const int MAXN = 1e6 + 1e3;

void make_string(int n, string & s) {
    s = "";
    while (n) {
        s = static_cast<char>((n % 10) + '0') + s;
        n /= 10;
    }
}

int main() {
    std::mt19937 rnd(time(0));
    int number;
    std::cin >> number >> number_of_verticies >> number_of_edges;
    string number_as_string;
    make_string(number, number_as_string);

    std::ofstream fout;
    std::ofstream tmp;
    string outfile = path_to_tests_dir + "test_" + number_as_string + ".txt";
    string tmpfile = path_to_generator + "tmp.txt";
    fout.open(outfile);
    tmp.open(tmpfile);

    Graph g = Graph::random(number_of_verticies, number_of_edges).connected();
    tmp << g;
    tmp.close();
    std::ifstream fin;
    fin.open(tmpfile);

    fout << number_of_verticies << ' ' << number_of_edges << '\n';
    for (int j = 0; j < number_of_edges; ++j) {
        int u, v;
        fin >> u >> v;
        fout << u << ' ' << v << ' ' << rnd() % max_weight << '\n';
    }
    fin.close();
    fout.close();
}