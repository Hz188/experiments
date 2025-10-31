 #include <iostream>

// assume int is 4 bytes
int main()
{
	unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n'; // 2 - 3 = -1 -> 0b 11111111....1111 32个1 = 4294967295

    signed int a { -1 };
    unsigned int b { 1 };

    if (a < b) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // this statement executes
	return 0;
}