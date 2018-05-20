#include "Node.cpp"
template <class T>
class Tree
{
    private:
        std::vector<T> values;
        size_t max_num_of_elems;
        Node<T>* root;

    public:
        Tree<T>(size_t max_num_of_elems)
        {
            this -> max_num_of_elems = max_num_of_elems;
            root = new Node<T>(max_num_of_elems);
        }

        void add_element(T value)
        {
            if(this -> contains(value))
            {
                return;
            }
            values.push_back(value);
            std::sort(values.begin(), values.end());
            root = nodify(values);
            std::cout << value << " added" << std::endl;
        }


        void remove_element(T value)
        {
            if(!contains(value))
            {
                std::cout << "Element not found in the tree." << std::endl;
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


        bool contains(T value)
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


        Node<T>* nodify(std::vector<T> values)
        {
            int drawing_helper = 0;

            std::sort(values.begin(), values.end());
            size_t num_of_nodes = ceil(1.0 * values.size() / max_num_of_elems);
            std::vector<Node<T>*> previous_level;
            std::vector<T> values_to_insert = values;
            do
            {
                std::vector<Node<T>*> new_nodes;
                for(int i = 0; i < num_of_nodes; i++)
                {
                    Node<T> *new_node = new Node<T>(max_num_of_elems);
                    (new_nodes).push_back(new_node);
                }
                populate_nodes(new_nodes, previous_level, values_to_insert);
                for(int k = 0; k < drawing_helper; k++)
                {
                    std::cout << "   " ;
                }
                for(int i = 0; i < new_nodes.size(); i++)
                {

                    for(int j = 0; j < new_nodes.at(i) -> current_num_of_elems; j++)
                    {
                        std::cout << "| " << (new_nodes.at(i) -> get_value(j)) << " |";
                    }
                    std::cout << "   ";
                    drawing_helper++;
                }
                std::cout << std::endl << std::endl;
                std::vector<Node<T> *> copy_new_nodes = new_nodes;
                previous_level = copy_new_nodes;
                std::vector<T> updated_values = update_values_vector(previous_level);
                values_to_insert = updated_values;
                num_of_nodes = (num_of_nodes == 1) ? 0 : ceil(1.0 * values_to_insert.size() / max_num_of_elems);
            }
            while(num_of_nodes >= 1);

            return (previous_level).at(0);
        }


        void populate_nodes(std::vector<Node<T> *> higher_nodes, std::vector<Node<T>*> lower_nodes, std::vector<T> values)
        {
            size_t initial_available_nodes = higher_nodes.size();
            size_t available_num_of_elems = values.size();
            size_t available_nodes = initial_available_nodes;
            for(int i = 0; i < initial_available_nodes; i++)
            {
                size_t num_of_elems_to_add = floor(1.0 * available_num_of_elems / available_nodes);

                for(int j = 0; j < num_of_elems_to_add; j++)
                {
                    T value_to_add = values.front();
                    Node<T> *target_node = find_free_node(higher_nodes, num_of_elems_to_add);
                    if(lower_nodes.empty())
                    {
                        target_node -> add_field(value_to_add, nullptr);
                        available_num_of_elems--;
                        if(target_node -> get_num_of_fields() >= num_of_elems_to_add)
                        {
                            available_nodes--;
                            higher_nodes.erase(higher_nodes.begin());
                        }
                        values.erase(values.begin());
                    }
                    else
                    {
                        Node<T> *pointer = find_pointer(lower_nodes, value_to_add);
                        target_node -> add_field(value_to_add, pointer);
                        available_num_of_elems--;
                        if(target_node -> get_num_of_fields() >= num_of_elems_to_add)
                        {
                            available_nodes--;
                            higher_nodes.erase(higher_nodes.begin());
                        }
                        values.erase(values.begin());
                    }

                }
            }
        }


        Node<T>* find_free_node(std::vector<Node<T>*> nodes, int max_capacity)
        {
            for(int i = 0; i < nodes.size(); i++)
            {
                if(nodes.at(i) -> current_num_of_elems < max_num_of_elems && nodes.at(i)->current_num_of_elems < max_capacity)
                {
                    return nodes.at(i);
                }
            }
        }

        Node<T>* find_pointer(std::vector<Node<T> *> nodes, T value)
        {
            for(int i = 0; i < nodes.size(); i++)
            {
                if(i < nodes.at(i) -> current_num_of_elems  && nodes.at(i) -> get_value(0) == value)
                {
                    return nodes.at(i);
                }
            }
        }

        std::vector<T> update_values_vector(std::vector<Node<T>*> previous_nodes)
        {
            std::vector<T> new_values;

            for(int i = 0; i < previous_nodes.size(); i++)
            {
                if(!previous_nodes.at(i) -> fields.empty())
                {
                    new_values.push_back(previous_nodes.at(i) -> get_value(0));
                }
            }

            return new_values;
        }


        Node<T>* get_root()
        {
            return root;
        }


        ~Tree()
        {
            delete(root);
        }



};
