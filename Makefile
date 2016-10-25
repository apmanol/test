all: hello-cpp-world

%: %.cc
	${CXX} -std=c++11 $< -o $@ -pthread 

%: %.c
	${CC} $< -o $@

