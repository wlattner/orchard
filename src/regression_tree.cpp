#include "regression_tree.h"


RegressionTree::RegressionTree() : left(0), right(0), split_var(0), split_val(0), node_val(0) {
  // TODO: set defaults for the hyperparams
}

RegressionTree& RegressionTree::set_max_depth(int n) {
  max_depth = n;
  return *this;
}

RegressionTree& RegressionTree::set_min_samples_split(int n) {
  min_samples_split = n;
  return *this;
}

RegressionTree& RegressionTree::set_min_samples_leaf(int n) {
  min_samples_leaf = n;
  return *this;
}

RegressionTree& RegressionTree::set_max_features(int n) {
  max_features = n;
  return *this;
}

RegressionTree& RegressionTree::set_min_impurity_decrease(double d) {
  min_impurity_decrease = d;
  return *this;
}

void RegressionTree::fit(Rcpp::NumericMatrix x, Rcpp::NumericVector y, Rcpp::NumericVector w) {
  // TODO: fill this in...
}

Rcpp::NumericVector RegressionTree::predict(Rcpp::NumericMatrix x) {
  Rcpp::NumericVector pred(x.rows(), 1.0);
  return pred;
}