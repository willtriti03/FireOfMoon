#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <io.h>
#include <fcntl.h>
#include <stdio.h>

class Console {
public:
	Console() {
		int hCrt;
		FILE *hf;

		AllocConsole();

		hCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
		hf = _fdopen(hCrt, "w");

		*stdout = *hf;
		setvbuf(stdout, NULL, _IONBF, 0);
	}
	~Console() {
		_fcloseall();
		FreeConsole();
	}
};

#endif