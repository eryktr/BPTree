#include "Tree.cpp"
int main()
{
    Tree *t = new Tree(3);
    t -> add_element(9);
    t -> add_element(10);
    t -> add_element(11);
    t -> add_element(12);
    std::cout << t -> get_root() -> get_value(0);
    std::cout << t -> get_root() -> get_value(1);
    std::cout << t -> get_root() -> get_value(2);

}
