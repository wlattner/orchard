#include <algorithm>
#include "feature_splitter.h"


FeatureSplitter::FeatureSplitter(Rcpp::NumericMatrix x,
                                 Rcpp::NumericVector y,
                                 Rcpp::NumericVector w,
                                 Rcpp::IntegerVector inx)
 :
 x(x),
 y(y),
 w(w),
 inx(inx),
 y_sorted(y.length()),
 x_sorted(y.length()) { }

void FeatureSplitter::update_node(int start, int end, double impurity) {
  parent_impurity = impurity;
  y_sorted.resize(0);
  x_sorted.resize(0);
  inx_sorted.resize(0);
  // TODO: should this be end + 1?
  std::copy(inx.begin() + start, inx.begin() + end, std::back_inserter(inx_sorted));
}

Split FeatureSplitter::find_split(int feature) {
  std::sort(inx_sorted.begin(), inx_sorted.end(), [&](int& i, int &j) { return x(i, feature) > x(j, feature);});
  
  for (auto i : inx_sorted) {
    y_sorted.push_back(y[i]);
    x_sorted.push_back(x(i, feature));
  }
  
  // TODO: examine every possible split
  // from [min_samples_split:n - min_samples_split]
  
  Split s;
  return s;
}