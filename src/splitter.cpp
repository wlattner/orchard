#include "splitter.h"
#include "node.h"

Splitter::Splitter(const Rcpp::NumericMatrix& x, const Rcpp::NumericVector& y,
                   const Rcpp::NumericVector& w, std::vector<int>& samples)
    : x(x), y(y), w(w), samples(samples) {}

std::tuple<Node, Node, Node, bool> Splitter::split(Node n) {
    Node left, right;
    auto found = false;

    // this is where we do all the things

    return std::make_tuple(n, left, right, found);
}