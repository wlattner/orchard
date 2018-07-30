#include <vector>
#include <tuple>
#include <Rcpp.h>
#include "node.h"

class Splitter {
public:

    Splitter() = delete;
    Splitter(const Rcpp::NumericMatrix& x, const Rcpp::NumericVector& y, const Rcpp::NumericVector& w, std::vector<int>& samples);
    std::tuple<Node, Node, Node, bool> split(Node n);

private:
    const Rcpp::NumericMatrix& x;
    const Rcpp::NumericVector& y;
    const Rcpp::NumericVector& w;

    // we keep this sorted/partitioned
    std::vector<int>& samples;
};