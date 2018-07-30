#include <vector>
#include <stack>
#include "node.h"
#include "builder.h"
#include "splitter.h"

TreeBuilder::TreeBuilder() {}

TreeBuilder& TreeBuilder::max_depth(int d) {
    max_depth_ = d;
    return *this;
}

TreeBuilder& TreeBuilder::min_samples_split(int m) {
    min_samples_split_ = m;
    return *this;
}

TreeBuilder& TreeBuilder::min_samples_leaf(int m) {
    min_samples_leaf_ = m;
    return *this;
}

TreeBuilder& TreeBuilder::max_features(int n) {
    max_features_ = n;
    return *this;
}

std::vector<int> nonzero_samples(const Rcpp::NumericVector& w) {
    std::vector<int> v;
    for (int i = 0; i < w.length(); ++i) {
        if (w[i] > 0) {
            v.push_back(i);
        }
    }

    return v;
}

Tree TreeBuilder::fit(const Rcpp::NumericMatrix& x, const Rcpp::NumericVector& y, const Rcpp::NumericVector& w) {
    Tree tree;
    auto samples = nonzero_samples(w);
    // TODO: the splitter also needs to know the split params
    Splitter splitter(x, y, w, samples);

    auto n = Node{
        .begin = samples.begin(),
        .end = samples.end(),
        .parent = -1,
    };

    std::stack<Node> stack;
    stack.push(n);
    while (!stack.empty()) {
        n = stack.top();
        stack.pop();

        Node left, right;
        bool found_split;
        std::tie(n, left, right, found_split) = splitter.split(n);

        // at this point, we should have the node value and such
        auto node_id = tree.add_node(n);

        if (!found_split) {
            continue;
        }

        // we now know the parent, so update the left and right child
        // nodes.
        left.parent = node_id;
        right.parent = node_id;
        
        stack.push(left);
        stack.push(right);
    }

    return tree;
}