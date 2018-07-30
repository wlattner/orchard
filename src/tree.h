#include <Rcpp.h>
#include "node.h"

class Tree {
public:
    Rcpp::IntegerVector left_child;
    Rcpp::IntegerVector right_child;
    Rcpp::IntegerVector split_variable;
    Rcpp::NumericVector split_value;
    Rcpp::NumericVector node_value;

    Tree();

    int add_node(const Node& n);
    Rcpp::NumericVector predict(const Rcpp::NumericMatrix x);

    // TODO: serialize and such
};