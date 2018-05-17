#include <vector>
#include <stdlib.h>
struct Node
{

    bool is_leaf;
    size_t current_num_of_elems;
    size_t max_num_of_elems;

    Node *parent;
    std::vector<int> values;
    std::vector<Node*> pointers;

    Node(bool is_leaf, size_t max_num_of_elems)
    {
        this -> max_num_of_elems = max_num_of_elems;
        this -> is_leaf = is_leaf;
        this -> current_num_of_elems = 0;
        parent = nullptr;
    }

    Node* get_previous_pointer(int index)
    {
        return pointers[index];
    }

    Node* get_next_pointer(int index)
    {
        return pointers[index + 1];
    }

    bool is_full()
    {
        return current_num_of_elems >= max_num_of_elems;
    }


};
