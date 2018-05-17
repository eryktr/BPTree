#include "Tree.cpp"
int main()
{
    Tree *t = new Tree(3);
    t -> add_element(9);
    std::cout << (t->get_root()->fields[0].first);

}
