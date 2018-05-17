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

            if(this -> contains(value))
            {
                return;
            }
            std::cout << "1" << std::endl;
            values.push_back(value);
            std::sort(values.begin(), values.end());
            std::cout << "2" << std::endl;
            root = nodify(values);
            std::cout << value << " added";
        }


        void remove_element(int value) {}


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
            size_t num_of_nodes = ceil(1.0 * values.size() / max_num_of_elems);
            std::vector<Node*> *previous_level = nullptr;
            std::vector<int> values_to_insert = values;
            do
            {
                std::vector<Node*> new_nodes;
                std::cout << "7" << std::endl;
                for(int i = 0; i < num_of_nodes; i++)
                {
                    Node *new_node = new Node(max_num_of_elems);
                    new_nodes.push_back(new_node);
                }
                std::cout << "8" << std::endl;
                populate_nodes(&new_nodes, previous_level, values_to_insert);
                std::cout << "9" << std::endl;
                previous_level = &new_nodes;
                std::cout << "10" << std::endl;
                values_to_insert = update_values_vector(*previous_level);
                std::cout << "11" << std::endl;
                num_of_nodes = ceil(1.0 * values_to_insert.size() / max_num_of_elems);
            }
            while(num_of_nodes > 1);

            return (*previous_level).at(0);
        }


        void populate_nodes(std::vector<Node*> *higher_nodes, std::vector<Node*>  *lower_nodes, std::vector<int> values)
        {
            size_t available_nodes = (*higher_nodes).size();
            size_t available_num_of_elems = values.size();
            for(int i = 0; i < available_nodes; i++)
            {
                size_t num_of_elems_to_add = floor(1.0 * available_nodes / available_num_of_elems);
                for(int j = 0; j < num_of_elems_to_add; j++)
                {
                    int value_to_add = values[j];
                    Node *target_node = find_free_node(higher_nodes, num_of_elems_to_add);
                    if(lower_nodes == nullptr)
                    {
                        target_node -> add_field(value_to_add, nullptr);
                        available_num_of_elems--;
                        if(target_node -> get_num_of_fields() >= num_of_elems_to_add)
                        {
                            available_nodes--;
                        }
                    }
                    else
                    {
                        Node *pointer = find_pointer(lower_nodes, value_to_add);
                        {
                            target_node -> add_field(value_to_add, pointer);
                            available_num_of_elems--;
                            if(target_node -> get_num_of_fields() >= num_of_elems_to_add)
                            {
                                available_nodes--;
                            }
                        }

                    }
                }
            }
        }


        Node* find_free_node(std::vector<Node *> *nodes, int max_capacity)
        {
            for(int i = 0; i < (*nodes).size(); i++)
            {
                if((*nodes).at(i)->current_num_of_elems < max_capacity)
                {
                    return (*nodes).at(i);
                }
            }
        }

        Node* find_pointer(std::vector<Node *> *nodes, int value)
        {
            for(int i = 0; i < (*nodes).size(); i++)
            {
                for(int j = 0; j < (*nodes).at(i)->current_num_of_elems; j++)
                {
                    if((*nodes).at(i) -> get_value(j) == value)
                    {
                        return (*nodes).at(i) -> get_pointer(j);
                    }
                }
            }
        }

        std::vector<int> update_values_vector(std::vector<Node*> previous_nodes)
        {
            std::vector<int> new_values;

            for(int i = 0; i < previous_nodes.size(); i++)
            {
                new_values.push_back(previous_nodes.at(i) -> get_value(0));
            }
            return new_values;
        }

        Node* get_root()
        {
            return root;
        }



};
