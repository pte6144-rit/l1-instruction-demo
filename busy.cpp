#include <ctime>
#include <iostream>

int main(int arg_c, char** arg_v) {
	std::time_t start = std::time(nullptr);

	__asm__ __volatile__ (
		"movl $1285930, %eax;"
		"movl $5, %edx;"
		"start:"
        ".align 4096;"
        ".rept 1313;"
        "nop;"
        ".endr;"
        "movl $10000000, %ecx;"
		"star:"
		".rept 1000;"
		"nop;"
		".endr;"
		"addl $1205432, %eax;"
		"subl $1, %ecx;"
		"jne star;"
		"subl $1, %edx;"
		"jne start;"
	);

	std::time_t end = std::time(nullptr);
	std::cout << end - start << std::endl;
	return 0;
}
