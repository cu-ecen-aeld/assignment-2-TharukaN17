#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Check if both arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Error: Both arguments (file and string) are required.\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    char *content = argv[2];

    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file '%s' for writing.", filename);
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write the content to the file
    fprintf(file, "%s\n", content);

    // Close the file
    fclose(file);

    // Log the write operation
    openlog("writer", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", content, filename);
    closelog();

    return EXIT_SUCCESS;
}

