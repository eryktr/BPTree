#include "Node.cpp"

class Tree
{
    private:
        std::vector<int> values;
        size_t max_num_of_elems;
        Node* root;

    public:
        Tree(size_t max_num_of_elems, std::vector<int> values)
        {
            this -> values = values;
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

            values.push_back(value);
            std::sort(values.begin(), values.end());
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

        std::vector<Node*> nodify(std::vector<int> values)
        {
            size_t num_of_nodes = ceil(values.size() / max_num_of_elems);
            std::vector<Node*> new_nodes;
            for(int i = 0; i < num_of_nodes; i++)
            {
                Node *new_node = new Node(max_num_of_elems);
                new_nodes.push_back(new_node);
            }
        }

        void populate_nodes(std::vector<Node*> higher_nodes, std::vector<Node*> lower_nodes, std::vector<int> values)
        {
            size_t available_nodes = higher_nodes.size();
            size_t available_num_of_elems = values.size();
            for(int i = 0; i < available_nodes; i++)
            {
                size_t num_of_elems_to_add = floor(available_nodes / available_num_of_elems);

            }
        }



};
