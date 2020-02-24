#include "pch.h"
#include <iostream>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)


char* my_memccpy(char* destination, const char* source, int c, size_t n) {
	for (int i = 0; i < n; i++)
	{
		destination[i] = *(source + i);
		if (*(source + i) == c) {
			break;
		}
	}
	return destination;
}

int main(void) {
	setlocale(LC_ALL, "Russian");

	//char buffer[61];
	//int *pdest;
	//char string1[60] = "The quick brown dog jumps over the lazy fox";
	//printf("Source: %s\n", string1);
	//pdest = (int *)(memccpy(buffer, string1, 's', 20));
	//*pdest = '\0';
	//printf("Result: %s\n", buffer);
	//printf("Length: %d characters\n", strlen(buffer));

	// 1
	/*char buffer[61] = "";
	char string1[60] = "textftext";
	memccpy(buffer, string1, 'f', 30);
	printf("Result: %s\n", buffer);*/


	// 2 
	/*char buffer[61] = "12345678";
	char string1[60] = "textftext";
	memccpy(buffer, string1, 'f', 30);
	printf("Result: %s\n", buffer);*/

	//3
	char buffer[61] = "";
	char string1[60] = "textftext";
	my_memccpy(buffer, string1, 'f', 30);
	printf("Result: %s\n", buffer);

	//void* result;
	//printf("Source: %s\n", string1);
	//result = memccpy(buffer, string1, 's', 30);
	//printf("Result: %s\n", buffer);

	/*my_memccpy(buffer, string1, 'f', 60);
	printf(buffer);*/

}


//char* my_memccpy(char* destination, const char* source, int c, int n) {
//	for (size_t i = 0; i < n; i++)
//	{
//		std::cout << "a[" << i << "]: address=" << source + i << "\tvalue=" << *(source + i) << std::endl;
//	}
//	return destination;
//}