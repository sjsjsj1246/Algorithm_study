#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	if (n % 300 % 60 % 10) std::cout << -1;
	else std::cout << n / 300 << " " << n % 300 / 60 << " " << n % 300 % 60 / 10;
}