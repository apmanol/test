all: hello-cpp-world

%: %.cc
	g++ -std=c++11 $< -o $@ -pthread 

%: %.c
	gcc $< -o $@

