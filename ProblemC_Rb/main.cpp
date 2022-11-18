#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	uint32_t n;
	std::cin >> n;

	uint32_t arr[100];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (size_t ind = 3; ind <= n; ++ind)
		arr[ind] = arr[ind - 1] + arr[ind - 3];

	std::cout << arr[n] << '\n';

	return 0;
}