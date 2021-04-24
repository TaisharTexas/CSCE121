# CSCE121

## Class code for my TAMU software design in C++ class.


get to windows drive from ubuntu shell: cd /mnt/c/Users/bayle/Documents/CSCE121

compile: g++ -std=c++17 -Wall -Wextra -pedantic -Weffc++ program_name_one.cpp program_name_two.cpp
run everything: ./a.out


g++ -std=c++17 -Wall -Wextra -pedantic -Weffc++ FunctionTest.cpp

g++ -std=c++17 -Wall -Wextra -pedantic-errors -Weffc++ -fsanitize=undefined,address *.cpp



g++ -std=c++17 -Wall -Wextra -pedantic -g -fsanitize=address,undefined Network.cpp User.cpp Post.cpp Tag.cpp Cppeers-main.cpp



g++ -std=c++17 -Wall -Wextra -pedantic-errors -Weffc++ -Wno-unused-parameter -fsanitize=undefined,address RoverTest.cpp Rover.cpp MyString.cpp

g++ -std=c++17 -Wall -Wextra -pedantic-errors -Weffc++ -Wno-unused-parameter -fsanitize=undefined,address Main.cpp MyString.cpp