#include <iostream>
#include "Dialogue.h"

int main(int argc, char *argv[]) {
    try
    {
        lab1::Dialogue dialogue(argc, argv);
        dialogue.run();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
