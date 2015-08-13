run: run.cpp
	g++ -g -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE $^ -o run
