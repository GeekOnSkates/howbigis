#include <stdio.h>
#include "formatBytes.h"

int main(int argc, const char **argv) {
	if (argc < 2) {
		printf("Usage: howbigis [filename]\n");
		return 1;
	}
	FILE *fp;
	fp = fopen(argv[1],"r");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}
	fseek(fp, 0, SEEK_END);
	unsigned long size = ftell(fp);
	fclose(fp);
	if(size == -1) {
		perror("Error getting file size");
		return 1;
	}
	char format[6];
	strcpy(format, FORMAT_AUTO);
	if (argc == 3 && argv[2][0] == '-') {
		if (argv[2][1] == 'b' || argv[2][1] == 'B')
			strcpy(format, FORMAT_BYTES);
		else if (argv[2][1] == 'k' || argv[2][1] == 'K')
			strcpy(format, FORMAT_KB);
		else if (argv[2][1] == 'm' || argv[2][1] == 'M')
			strcpy(format, FORMAT_MB);
		else if (argv[2][1] == 'g' || argv[2][1] == 'G')
			strcpy(format, FORMAT_GB);
	}
	char *bytes = formatBytes(size, format);
        if (bytes == NULL) {
		perror("Error calculating file size");
                return 1;
	}
	printf("%s\n", bytes);
	free(bytes);
	return 0;
}
