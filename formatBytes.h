#ifndef _FORMAT_BYTES
#define _FORMAT_BYTES

#include <stdlib.h>
#include <string.h>

#define FORMAT_AUTO "auto"
#define FORMAT_BYTES "bytes"
#define FORMAT_KB "KB"
#define FORMAT_MB "MB"
#define FORMAT_GB "GB"

double convertBytes(unsigned long bytes, char *format) {
	double value = (double)bytes;
	if (format[0] == 'K') return value / 1024;
	if (format[0] == 'M') return value / 1024 / 1024;
	if (format[0] == 'G') return value / 1024 / 1024 / 1024;
	return value;
}

char *formatBytes(unsigned long bytes, char *format) {
	if (strcmp(format, FORMAT_AUTO) == 0) {
		double check = (double)bytes / 1024 / 1024 / 1024;
		if (check >= 1) return formatBytes(bytes, FORMAT_GB);
		check = (double)bytes / 1024 / 1024;
		if (check >= 1) return formatBytes(bytes, FORMAT_MB);
		check = (double)bytes / 1024;
		if (check >= 1) return formatBytes(bytes, FORMAT_KB);
		return formatBytes(bytes, FORMAT_BYTES);
	}
	double value = convertBytes(bytes, format);
	if (strcmp(format, FORMAT_BYTES) == 0) {
		const int n = snprintf(NULL, 0, "%ld bytes", (unsigned long)value);
	        char *buf = malloc(n + 6);
	        int c = snprintf(buf, n + 6, "%ld bytes", (unsigned long)value);
		return buf;
	}
	const int n = snprintf(NULL, 0, "%.02f %s", value, format);
	char *buf = malloc(n + 6);
	int c = snprintf(buf, n + 6, "%.2f %s", value, format);
	return buf;
}


#endif

