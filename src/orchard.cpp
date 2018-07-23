#include <Rcpp.h>
#include "regression_tree.h"


RCPP_EXPOSED_CLASS_NODECL(RegressionTree)
RCPP_MODULE(RegressionTree) {
  Rcpp::class_<RegressionTree>("RegressionTree")
  
    .constructor("default constructor")
  
    .method("fit", &RegressionTree::fit)
    .method("predict", &RegressionTree::predict)
    .method("set_max_depth", &RegressionTree::set_max_depth)
    .method("set_min_samples_split", &RegressionTree::set_min_samples_split)
    .method("set_min_samples_split", &RegressionTree::set_min_samples_leaf)
    .method("set_max_features", &RegressionTree::set_max_features)
    .method("set_min_impurity_decrease", &RegressionTree::set_min_impurity_decrease)
  
    .field_readonly("left", &RegressionTree::left)
    .field_readonly("right", &RegressionTree::right)
    .field_readonly("split_var", &RegressionTree::split_var)
    .field_readonly("split_val", &RegressionTree::split_val)
    .field_readonly("node_val", &RegressionTree::node_val)
  ;
}
