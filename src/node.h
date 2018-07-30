#include <vector>

struct Node {
    std::vector<int>::iterator begin;
    std::vector<int>::iterator end;
    int parent;
    bool is_left;
    bool is_leaf;
    int depth;
    int split_var;
    double split_val;
    double node_val;
};