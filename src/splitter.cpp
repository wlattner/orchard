#include <tuple>
#include <algorithm>
#include "splitter.h"
#include "node.h"

Splitter::Splitter(const Rcpp::NumericMatrix& x, const Rcpp::NumericVector& y,
                   const Rcpp::NumericVector& w, std::vector<int>& samples)
    : x(x), y(y), w(w), samples(samples) {}

struct Split {
    int variable;
    double value;
    int n_left;
    int n_right;
    double impurity;
    double impurity_left;
    double impurity_right;
};

std::tuple<Node, Node, Node, bool> Splitter::split(Node n) {
    Node left, right;
    auto found = false;
    Split best_split;

    // this is where we do all the things

    // we also need to partition samples so left and right
    // correspond to the best split
    auto mid = std::partition(n.begin, n.end, [&](int i) { return x(i, best_split.variable) <= best_split.value;});
    left.begin = n.begin;
    left.end = mid;
    right.begin = mid;
    right.end = n.end;

    return std::make_tuple(n, left, right, found);
}