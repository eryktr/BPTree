#include <vector>
#include <algorithm>
#include <iostream>
#include "Node.cpp"

class Tree
{
    private:
        size_t max_num_of_elems;
        Node *root;

    public:
        Tree(size_t max_num_of_elems)
        {
            this -> max_num_of_elems = max_num_of_elems;
            root = new Node(true, max_num_of_elems);
        }

        Node* find_destination_leaf(Node* root, int value)
        {

            if(root != nullptr && root -> is_leaf)
            {
                std::cout << "root returned" << std::endl;
                return root;
            }

            else
            {

                if(value < root->values[0] && root->pointers[0] != nullptr)
                {
                    return find_destination_leaf(root ->get_previous_pointer(0), value);
                }
                std::cout << "The root has " << root->current_num_of_elems << "elements. ";
                for(int i = 1; i < root -> current_num_of_elems - 1; i++)
                {
                    std::cout << "I made it thus far";
                    if(value < root -> values[i] && root -> pointers[i] != nullptr)
                    {
                        return find_destination_leaf(root -> get_previous_pointer(i), value);
                    }
                }
                if(value > root -> values[root -> current_num_of_elems - 1] && root -> pointers[root -> current_num_of_elems - 1] != nullptr)
                {
                    return find_destination_leaf(root -> get_next_pointer(max_num_of_elems - 1), value);
                }
            }
        }
        bool contains(int value) {}

        void insert_into_node(Node *target, int value)
        {
            Node* target = *destination_leaf;

            if(! (target -> is_full()) )
            {

                (target) -> values.push_back(value);
                sort(target->values.begin(), target->values.end());
                std::cout << value << " added!" << std::endl;
                target->current_num_of_elems++;
                destination_leaf = &target;
                std::cout << "The target has " << target->current_num_of_elems << "elements." <<std::endl;
            }

            else if( target -> is_full() && (target -> parent == nullptr || !(target -> parent -> is_full())))
            {
                std::cout << "Yeah! I do work!";
                Node* new_target = new Node(true, max_num_of_elems);
                target -> values.push_back(value);
                target -> current_num_of_elems++;
                for(int i = max_num_of_elems; i > floor(max_num_of_elems / 2); i--)
                {
                    new_target -> values.push_back(target -> values.back());
                    target -> values.pop_back();
                    new_target -> current_num_of_elems++;
                    target -> current_num_of_elems--;
                }
                if(target->parent == nullptr)
                {
                    Node* new_root = new Node(false, max_num_of_elems);
                    target -> parent = new_root;
                    root = new_root;
                }
                target -> parent -> values.push_back(new_target -> values[0]);
                target -> parent -> pointers.push_back(target);
                target -> parent -> pointers.push_back(new_target);
                target -> parent -> current_num_of_elems++;
                std::cout << value << "added" << std::endl;


            }
            else
            {
                std::cout <<"Its me";
                target -> values.push_back(value);
                target -> current_num_of_elems++;
                sort(target->values.begin(), target->values.end());
                Node *new_target = new Node(true, max_num_of_elems);
                for(int i = max_num_of_elems; i > floor(max_num_of_elems / 2); i--)
                {
                    new_target -> values.push_back(target -> values.back());
                    target -> values.pop_back();
                    new_target -> current_num_of_elems++;
                    target -> current_num_of_elems--;
                }
                int new_parent_val = new_target -> values[0];
                Node *target_parent = target -> parent;
                Node *new_larger_node = new Node(false, max_num_of_elems);

                for(int i = max_num_of_elems; i > floor(max_num_of_elems / 2); i--)
                {
                    new_larger_node -> values.push_back(target_parent -> values.back());
                    target_parent -> values.pop_back();
                    new_larger_node -> current_num_of_elems++;
                    target_parent -> current_num_of_elems--;
                }

                if(target_parent -> parent == nullptr)
                {
                    Node* grandparent = new Node(false, max_num_of_elems);
                    grandparent -> values.push_back(new_larger_node -> values[0]);
                    grandparent -> pointers.push_back(new_larger_node);
                    grandparent -> pointers.push_back(target_parent);
                    root = grandparent;


                }
                std::cout << value << "added" << std::endl;
            }
        }

        void insert_into_tree(int value)
        {
            Node *destination_leaf= find_destination_leaf(root, value);
            insert_into_node(destination_leaf, value);

        }

        ~Tree()
        {
            delete(root);
        }
};

int main()
{
    Tree *tree = new Tree(3);
    tree -> insert_into_tree(10);
    tree -> insert_into_tree(20);
    tree -> insert_into_tree(30);
    tree -> insert_into_tree(40);
    tree -> insert_into_tree(50);
    tree -> insert_into_tree(60);
    tree -> insert_into_tree(70);
    tree -> insert_into_tree(80);


}


