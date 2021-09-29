#include <iostream>
#include "Dialogue.h"

int main() {
    std::ifstream in("abc.txt");
    yyFlexLexer a(&in);
    while (in.good())
        std::cout << a.yylex() << " " << a.YYText() << std::endl;
    return 0;
}
