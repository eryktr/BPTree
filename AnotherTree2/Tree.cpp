#include "Node.cpp"

class Tree
{
    private:
        std::vector<int> values;
        size_t max_num_of_elems;
        Node* root;

    public:
        Tree(size_t max_num_of_elems)
        {
            this -> max_num_of_elems = max_num_of_elems;
            root = new Node(max_num_of_elems);
        }


        void create_tree(std::vector<int> values)
        {

        }


        void add_element(int value)
        {
            std::cout << "Adding " << value << std::endl << std::endl;
            if(this -> contains(value))
            {
                return;
            }
            values.push_back(value);
            std::sort(values.begin(), values.end());
            root = nodify(values);
            std::cout << value << " added" << std::endl;
        }


        void remove_element(int value)
        {
            if(!contains(value))
            {
                std::cout << "Element not found in tree." << std::endl;
                return;
            }
            else
            {
                for(int i = 0; i < values.size(); i++)
                {
                    if(values[i] == value)
                    {
                        values.erase(values.begin() + i);
                        break;
                    }
                }
                root = nodify(values);
                std::cout << value << "deleted" <<std::endl;
            }

        }


        bool contains(int value)
        {
            for(int i = 0; i < values.size(); i++)
            {
                if(values[i] == value)
                {
                    return true;
                }
            }
            return false;
        }


        Node* nodify(std::vector<int> values)
        {
            std::sort(values.begin(), values.end());
            size_t num_of_nodes = ceil(1.0 * values.size() / max_num_of_elems);
            std::vector<Node*> *previous_level = nullptr;
            std::vector<int> values_to_insert = values;
            do
            {
                std::cout << num_of_nodes << "nodes created" << std::endl;
                std::vector<Node*> new_nodes;
                for(int i = 0; i < num_of_nodes; i++)
                {
                    Node *new_node = new Node(max_num_of_elems);
                    (new_nodes).push_back(new_node);
                }
                populate_nodes(&new_nodes, previous_level, values_to_insert);
                std::vector<Node *> copy_new_nodes = new_nodes;
                previous_level = &copy_new_nodes;
                std::vector<int> updated_values = update_values_vector(*previous_level);
                values_to_insert = updated_values;
                num_of_nodes = (num_of_nodes == 1) ? 0 : ceil(1.0 * values_to_insert.size() / max_num_of_elems);
            }
            while(num_of_nodes >= 1);

            return (*previous_level).at(0);
        }


        void populate_nodes(std::vector<Node*> *higher_nodes, std::vector<Node*>  *lower_nodes, std::vector<int> values)
        {
            size_t initial_available_nodes = (*higher_nodes).size();
            size_t available_num_of_elems = values.size();
            size_t available_nodes = initial_available_nodes;
            for(int i = 0; i < initial_available_nodes; i++)
            {
                size_t num_of_elems_to_add = floor(1.0 * available_num_of_elems / available_nodes);
                std::cout << "I got here. i = " << i << std::endl;

                for(int j = 0; j < num_of_elems_to_add; j++)
                {
                    int value_to_add = values.front();
                    Node *target_node = find_free_node(higher_nodes, num_of_elems_to_add);
                    if(lower_nodes == nullptr)
                    {
                        target_node -> add_field(value_to_add, nullptr);
                        std::cout << value_to_add << "pushed" << std::endl;
                        available_num_of_elems--;
                        if(target_node -> get_num_of_fields() >= num_of_elems_to_add)
                        {
                            available_nodes--;
                        }
                        values.erase(values.begin());
                    }
                    else
                    {
                        std::cout << "I got here. j = " << j << std::endl;
                        Node *pointer = find_pointer(lower_nodes, value_to_add);
                        std::cout << "I got here. i = " << j << std::endl;
                        target_node -> add_field(value_to_add, pointer);
                        available_num_of_elems--;
                        if(target_node -> get_num_of_fields() >= num_of_elems_to_add)
                        {
                            available_nodes--;
                        }
                        values.erase(values.begin());
                    }

                }
                previous_num_of_elems_to_add = num_of_elems_to_add;
            }
        }


        Node* find_free_node(std::vector<Node *> *nodes, int max_capacity)
        {
            for(int i = 0; i < (*nodes).size(); i++)
            {
                if((*nodes).at(i) -> current_num_of_elems < max_num_of_elems && (*nodes).at(i)->current_num_of_elems < max_capacity)
                {
                    std::cout << "Node number " << i << "returned." << std::endl;
                    return (*nodes).at(i);
                }
            }
        }

        Node* find_pointer(std::vector<Node *> *nodes, int value)
        {
            std::cout << "Looking for pointer for " << value << std::endl;
            std::cout << "We have " << (*nodes).size() << "nodes" <<std::endl;
            for(int i = 0; i < (*nodes).size(); i++)
            {
                std::cout << "This time i = " << i << std::endl;
                if(i < (*nodes).at(i) -> current_num_of_elems  && (*nodes).at(i) -> get_value(0) == value)
                {
                    std::cout << "Got it!";
                    return (*nodes).at(i);
                }
            }
            std::cout << "Not found:(";
        }

        std::vector<int> update_values_vector(std::vector<Node*> previous_nodes)
        {
            std::vector<int> new_values;

            for(int i = 0; i < previous_nodes.size(); i++)
            {
                if(!previous_nodes.at(i) -> fields.empty())
                {
                    new_values.push_back(previous_nodes.at(i) -> get_value(0));
                }
            }

            return new_values;
        }

        Node* get_root()
        {
            return root;
        }

        ~Tree()
        {
            delete(root);
        }



};
