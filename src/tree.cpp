#include "tree.h"

Tree::Tree()
    : left_child(0), right_child(0), split_variable(0), split_value(0), node_value(0) {

}

int Tree::add_node(const Node& n) {
    int node_id = left_child.size();

    left_child.push_back(-1);
    right_child.push_back(-1);
    split_variable.push_back(n.split_var);
    split_value.push_back(n.split_val);
    node_value.push_back(n.node_val);

    // and update the parent
    if (n.is_left) {
        left_child[n.parent] = node_id;
    } else {
        right_child[n.parent] = node_id;
    }

    return node_id;
}

Rcpp::NumericVector Tree::predict(const Rcpp::NumericMatrix x) {
    Rcpp::NumericVector y_hat(x.rows());
    
    // TODO: we probably had a nicer way of doing this
    for (int i = 0; i < x.rows(); ++i) {
        int next = 0, previous = 0;
        while (next >= 0) {
            previous = next;
            if (x(i, split_variable[next]) > split_value[next]) {
                next = right_child[next];
            } else {
                next = left_child[next];
            }
        }
        y_hat[i] = node_value[previous];
    }

    return y_hat;
}