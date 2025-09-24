CPP_FILES="generator.cpp io.cpp sortings.cpp main.cpp"
APP=bin/example

if [ -f $APP ]; then rm $APP
fi

g++ -Wall $CPP_FILES -o $APP

./$APP
