#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <chrono>
#include "gtest/gtest.h"
#include "mst.h"

using std::string;

const string path_to_tests_dir = "/home/amir/Documents/Algorithms/MST/tests/";
const string path_to_answers_dir = "/home/amir/Documents/Algorithms/MST/answers/";


long long run_prim (std::ifstream & fin, std::ofstream & fout, string & infile) {
    fin.open(infile);
    auto start = std::chrono::high_resolution_clock::now();
    long long res = count_mst_weight_prim(fin);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    fout << "Prim    " << res  << " Time: " << elapsed.count() << '\n';
    fin.close();
}

long long run_kruskal (std::ifstream & fin, std::ofstream & fout, string & infile) {
    fin.open(infile);
    auto start = std::chrono::high_resolution_clock::now();
    long long res = count_mst_weight_kruskal(fin);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    fout << "Kruskal " << res  << " Time: " << elapsed.count() << '\n';
    fin.close();
}

long long run_boruvka (std::ifstream & fin, std::ofstream & fout, string & infile) {
    fin.open(infile);
    auto start = std::chrono::high_resolution_clock::now();
    long long res = count_mst_weight_boruvka(fin);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    fout << "Boruvka " << res  << " Time: " << elapsed.count() << '\n';
    fin.close();
}


TEST(sample, first) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_1.txt";
    string outfile = path_to_answers_dir + "res_1.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}

TEST(sample, second) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_2.txt";
    string outfile = path_to_answers_dir + "res_2.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}

TEST(sample, third) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_3.txt";
    string outfile = path_to_answers_dir + "res_3.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}


TEST(strong, first) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_4.txt";
    string outfile = path_to_answers_dir + "res_4.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}


TEST(strong, second) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_5.txt";
    string outfile = path_to_answers_dir + "res_5.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}


TEST(strong, third) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_6.txt";
    string outfile = path_to_answers_dir + "res_6.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}

TEST(strong, forfth) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_7.txt";
    string outfile = path_to_answers_dir + "res_7.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}


TEST(special, similar_to_tree) {
    std::ifstream fin;
    std::ofstream fout;
    string infile = path_to_tests_dir + "test_8.txt";
    string outfile = path_to_answers_dir + "res_8.txt";
    fout.open(outfile);
    fout << std::setprecision(10) << std::fixed;

    if (!fin)
        exit(1);

    const long long prim_res = run_prim(fin, fout, infile);
    const long long kruskal_res = run_kruskal(fin, fout, infile);
    const long long boruvka_res = run_boruvka(fin, fout, infile);

    EXPECT_EQ(prim_res, boruvka_res);
    EXPECT_EQ(prim_res, kruskal_res);
}
