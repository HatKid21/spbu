files="sortings.cpp io.cpp main.cpp"

dist="bin/example"

mkdir -p bin

g++ $files -o $dist

./$dist
