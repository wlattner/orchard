#include <vector>
#include <Rcpp.h>

struct Split {
  double impurity_left;
  double impurity_right;
  double impurity_improvement;
  double split_value;
  int feature;
};

class FeatureSplitter {
public:
  
  FeatureSplitter() = delete;
  FeatureSplitter(Rcpp::NumericMatrix x, Rcpp::NumericVector y, Rcpp::NumericVector w, Rcpp::IntegerVector inx);
  
  void update_node(int start, int end, double impurity);
  Split find_split(int feature);
  
private:
  Rcpp::NumericMatrix x;
  Rcpp::NumericVector y;
  Rcpp::NumericVector w;
  Rcpp::IntegerVector inx;
  
  double parent_impurity;
  std::vector<double> y_sorted;
  std::vector<double> x_sorted;
  std::vector<int> inx_sorted;
};