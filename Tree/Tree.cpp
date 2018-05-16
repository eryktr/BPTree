#include<utility>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<functional>
class Tree
{
    private:

        size_t max_num_of_fields;
        struct Node
        {
            Node *parent;
            int num_of_fields = 0;
            std::vector <std::pair<int, Node*>> fields;

            void sort_fields()
            {
                std::sort(fields.begin(), fields.end(), [](const auto &left, const auto &right){ return left.first < right.first; } );
            }

            Node(Node *parent)
            {
                this->parent = parent;
            }

            Node()
            {
                this->parent = nullptr;
            }
        };

        struct Node *root;

    public:

        void insert(int value)
        {
            if(root == nullptr)
            {
                Node *newRoot = new Node();
                newRoot -> parent = nullptr;
                newRoot -> fields.push_back(std::make_pair(value, nullptr));
                newRoot -> num_of_fields++;
                newRoot -> sort_fields();
                root = newRoot;
                std::cout << "New root created";
            }
            else if(root->num_of_fields < max_num_of_fields)
            {
                root -> fields.push_back(std::make_pair(value, nullptr));
                root -> num_of_fields++;
                root -> sort_fields();
                std::cout << "added";
            }
            else
            {
                int iterator = -1;
                while(iterator + 1 < max_num_of_fields && root -> fields[iterator+1].first < value)
                {
                    iterator++;
                }
                std::cout << iterator;
            }

        }

        void remove(int value)
        {

        }

        bool contains(int value)
        {

        }

        Tree(size_t size)
        {
            max_num_of_fields = size;
            root = nullptr;
        }

        ~Tree()
        {
            delete(root);

        }
};

int main(void)
{
    Tree *tree = new Tree(3);
    tree -> insert(10);
    tree -> insert(10);
    tree -> insert(10);
    tree -> insert(10);
    tree -> insert(10);
}
