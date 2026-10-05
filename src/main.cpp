#include <iostream>

int main(int argc, char* argv[]){
    std::cout << argc << std::endl;
    
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    if (argv[1] == "--option") {
        std::cout << "input -> --option" << std::endl;
    }

    return 0;
}
