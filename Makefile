all: ./a.out
	@clear
	@./a.out

./a.out: main.cpp d_symm.cpp
	@g+++ main.cpp d_symm.cpp

