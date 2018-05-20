#include "Tree.cpp"
int main()
{
    bool continue_program = true;
    enum Type {intType, stringType, doubleType};
    bool tree_exists = false;

    Type t;
    size_t tree_size;

    while(!tree_exists)
    {
        std::cin.clear();
        std::cout << "Welcome to the Quasi-B+ -Tree Simulator. " << std::endl
                  << "To start using this program, simply choose one of the numbers: " << std::endl
                  << "[1] New <int> Tree" << std::endl
                  << "[2] New <std::string> Tree" << std::endl
                  << "[3] New <double> Tree" << std::endl
                  << "choice: ";
        int choice;
        std::cin  >> choice;

        switch(choice)
        {
        case 1:
            t = intType;
            tree_exists = true;
            break;

        case 2:
            tree_exists = true;
            t = stringType;
            break;

        case 3:
            tree_exists = true;
            t = doubleType;
            break;
        default:
            std::cout << "Invalid choice!" <<std::endl;
            break;

        }
    }

    std::cout << "Size of the tree: ";
    std::cin  >> tree_size;

    if(t == intType )
    {
        int choice;
        Tree<int> *tree = new Tree<int>(tree_size);
        while(continue_program)
        {
            int element_to_add;
            int element_to_delete;
            int element_to_find;

            std::cout << "[1] Add Element" << std::endl
                      << "[2] Remove element" << std::endl
                      << "[3] Look for element" << std::endl
                      << "[4] Exit" << std::endl
                      << "choice: " << std::endl;
            std::cin  >> choice;

            switch(choice)
            {
            case 1:
                std::cout << "integer to add: ";
                std::cin >> element_to_add;
                tree -> add_element(element_to_add);
                break;

            case 2:
                std::cout << "integer to remove: ";
                std::cin >> element_to_delete;
                tree -> remove_element(element_to_delete);
                break;

            case 3:
                std::cout << "integer to look for: ";
                std::cin >> element_to_find;
                tree -> contains(element_to_find);
                break;

            case 4:
                continue_program = false;
                break;
            }
        }
    }
    else if(t == stringType )
    {
        int choice;
        Tree<std::string> *tree = new Tree<std::string>(tree_size);
        while(continue_program)
        {
            std::string element_to_add;
            std::string element_to_delete;
            std::string element_to_find;

            std::cout << "[1] Add Element" << std::endl
                      << "[2] Remove element" << std::endl
                      << "[3] Look for element" << std::endl
                      << "[4] Exit" << std::endl
                      << "choice: " << std::endl;
            std::cin  >> choice;

            switch(choice)
            {
            case 1:
                std::cout << "string to add: ";
                std::cin >> element_to_add;
                tree -> add_element(element_to_add);
                break;

            case 2:
                std::cout << "string to remove: ";
                std::cin >> element_to_delete;
                tree -> remove_element(element_to_delete);
                break;

            case 3:
                std::cout << "string to look for: ";
                std::cin >> element_to_find;
                tree -> contains(element_to_find);
                break;

            case 4:
                continue_program = false;
                break;
            }
        }
    }

    else
    {
        int choice;
        Tree<double> *tree = new Tree<double>(tree_size);
        while(continue_program)
        {
            double element_to_add;
            double element_to_delete;
            double element_to_find;

            std::cout << "[1] Add Element" << std::endl
                      << "[2] Remove element" << std::endl
                      << "[3] Look for element" << std::endl
                      << "[4] Exit" << std::endl
                      << "choice: " << std::endl;
            std::cin  >> choice;

            switch(choice)
            {
            case 1:
                std::cout << "double to add: ";
                std::cin >> element_to_add;
                tree -> add_element(element_to_add);
                break;

            case 2:
                std::cout << "double to remove: ";
                std::cin >> element_to_delete;
                tree -> remove_element(element_to_delete);
                break;

            case 3:
                std::cout << "double to look for: ";
                std::cin >> element_to_find;
                tree -> contains(element_to_find);
                break;

            case 4:
                continue_program = false;
                break;
            }
        }
        }

    }


