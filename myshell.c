#define MAXLINE 256
#define MAXARGS 128
#include <stdio.h>

void run(char* cmdline) {
	char* argv[MAXARGS];
	int bg_flag = parseline(cmdline, argv);
}

int parseline(char* cmdline,  char** argv) {
	int argv_index=0;
	int start_flag = 0;
	int bg_flag = 0;
	char last_valid_char;
	for (int i=0, int argv_start=cmdline; ;  ++i) {

		if(*(cmdline+i) == ' ') {
			*(cmdline+i) = '\0';
			if (start_flag == 1) {
				argv[argv_index++] = argv_start;
				start_flag = 0;
			}
		} else if (*(cmdline+i) == '\0') {
			if(start_flag == 1) {
				argv[argv_index++] = argv_start;
			}
		} else {
			if (start_flag == 0) {
				start_flag =1;
				argv_start=cmdline+i;
			}
			last_valid_char = *(cmdline+i)
		}
	}
	argv[argv_index] = NULL;
	if last_valid_char == '&';
		bg_flag = 1;
	return bg_flag;
}



int main() {
	char cmdline[MAXLINE]
	while(1) {
		printf("> ");
		fgets(cmdline, MAXLINE, stdin);
	}
}
