#include <Rcpp.h>

class RegressionTree {
public:
  int max_depth;
  int min_samples_split;
  int min_samples_leaf;
  int max_features;
  double min_impurity_decrease;
  
  Rcpp::IntegerVector left;
  Rcpp::IntegerVector right;
  Rcpp::IntegerVector split_var;
  Rcpp::NumericVector split_val;
  Rcpp::NumericVector node_val;
  
  RegressionTree();
  
  void fit(Rcpp::NumericMatrix x, Rcpp::NumericVector y, Rcpp::NumericVector w);
  Rcpp::NumericVector predict(Rcpp::NumericMatrix x);
  
  RegressionTree& set_max_depth(int n);
  RegressionTree& set_min_samples_split(int n);
  RegressionTree& set_min_samples_leaf(int n);
  RegressionTree& set_max_features(int n);
  RegressionTree& set_min_impurity_decrease(double d);
};