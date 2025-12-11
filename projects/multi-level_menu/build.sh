CPP_FILES="menuItems.cpp menuFunctions.cpp main.cpp"
APP=bin/example

mkdir -p bin

if [ -f $APP ]; then rm $APP
fi

g++ -Wall $CPP_FILES -o $APP

./$APP
