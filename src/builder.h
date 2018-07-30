#include <Rcpp.h>
#include "tree.h"

class TreeBuilder {
public:

    TreeBuilder();

    TreeBuilder& max_depth(int d);
    TreeBuilder& min_samples_leaf(int n);
    TreeBuilder& min_samples_split(int n);
    TreeBuilder& max_features(int n);

    Tree fit(const Rcpp::NumericMatrix& x, const Rcpp::NumericVector& y, const Rcpp::NumericVector& w);

private:
    int max_depth_ = 0;
    int min_samples_leaf_ = 0;
    int min_samples_split_ = 0;
    int max_features_ = -1;
};