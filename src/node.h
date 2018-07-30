#include <vector>

using int_iterator = std::vector<int>::iterator;

struct Node {
    int_iterator begin;
    int_iterator end;
    int parent;
    bool is_left;
    bool is_leaf;
    int depth;
    int split_var;
    double split_val;
    double node_val;
};