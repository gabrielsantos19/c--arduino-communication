# Command used to compile from command-line
g++ -Wall -o main main.cpp $(find ./serial/src -type f -name "*.cc") -I ./serial/include