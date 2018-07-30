#include <vector>
#include <tuple>
#include <Rcpp.h>

class Criterion {
public:

    Criterion() = delete;
    Criterion(const Rcpp::NumericVector& y, const Rcpp::NumericVector& w);

    void reset_node(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void update(int next_pos);
    double node_impurity();
    std::tuple<double, double> child_impurity();

private:
    const Rcpp::NumericVector& y;
    const Rcpp::NumericVector& w;
};