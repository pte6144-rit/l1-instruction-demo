#include <ctime>
#include <iostream>

#define LINES() "{{LINES}}"

int main(int arg_c, char** arg_v) {
	std::time_t start = std::time(nullptr);

	__asm__ __volatile__ (
		"movl $100, %edx;"
        ".align 4096;"
	"start:"
		"movl $80000000, %ecx;"
	"star:"
		"jmp line;"
		"ret:"
		"jmp line2;"
		"ret2:"
//		"jmp line3;"
//		"ret3:"
		"subl $1, %ecx;"
	"jne star;"
		"subl $1, %edx;"
	"jne start;"
	".rept " LINES() ";"
		"nop;"
	".endr;"
		"line:"
		"jmp ret;"
		".rept 100;"
		"nop;"
		".endr;"
		".rept 3960;"
		"nop;"
		".endr;"
		"line2:"
		".rept 100;"
		"nop;"
		".endr;"
		"jmp ret2;"
//		".rept 3960;"
//		"nop;"
//		".endr;"
//		"line3:"
//		".rept 100;"
//		"nop;"
//		".endr;"
//		"jmp ret3"
	);
	

	std::time_t end = std::time(nullptr);
	std::cout << end - start << std::endl;
	return 0;
}
