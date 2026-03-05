#include <iostream>

extern int yyparse();

int main() {
    std::cout << "Running parser..." << std::endl;

    int result = yyparse();

    if (result == 0) {
        std::cout << "Parse OK" << std::endl;
    } else {
        std::cout << "Parse FAILED" << std::endl;
    }
    return result;
}