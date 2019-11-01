#include <iostream>
#include <vector>
#include <array>
#include <limits.h>
int main(int argc, char const *argv[])
{
	std::vector<bool> v;
	bool * tab;
	tab = new bool[ULLONG_MAX];
	std::cout << v.max_size();
	return 0;
}