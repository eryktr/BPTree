#include <cstdlib>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
template <class T>
struct Node
{
    std::vector<std::pair<T, Node*>> fields;
    size_t max_num_of_elems;
    size_t current_num_of_elems;

    Node(size_t max_num_of_elems)
    {
        this -> max_num_of_elems = max_num_of_elems;
        current_num_of_elems = 0;
    }

    Node<T>()
    {
        this -> current_num_of_elems = 0;
    }

    bool is_full()
    {
        return current_num_of_elems >= max_num_of_elems;
    }

    void add_field(T value, Node *pointer)
    {
        fields.push_back(std::make_pair(value, pointer));
        current_num_of_elems++;
    }

    int get_num_of_fields()
    {
        return fields.size();
    }

    T get_value(int i)
    {
        return fields[i].first;
    }

    Node* get_pointer(int i)
    {
        return fields[i].second;
    }
};
