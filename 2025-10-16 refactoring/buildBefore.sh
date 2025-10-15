mkdir -p bin

dist="bin/before"

g++ before_refactoring_1.cpp -o $dist

./$dist
