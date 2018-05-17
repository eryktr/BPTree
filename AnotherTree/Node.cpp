#include <cstdlib>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
struct Node
{
    std::vector<std::pair<int, Node*>> fields;
    size_t max_num_of_elems;
    size_t current_num_of_elems;

    Node(size_t max_num_of_elems)
    {
        this -> max_num_of_elems = max_num_of_elems;
        current_num_of_elems = 0;
    }

    bool is_full()
    {
        return current_num_of_elems >= max_num_of_elems;
    }
};
