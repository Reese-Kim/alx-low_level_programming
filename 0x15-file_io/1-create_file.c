#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1; // Return -1 if filename is NULL
    }

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    if (text_content != NULL) {
        ssize_t write_result = write(fd, text_content, strlen(text_content));
        if (write_result == -1) {
            perror("Error writing to file");
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}

int main() {
    const char *filename = "example.txt";
    char *text_content = "Hello, this is some text content.";

    int result = create_file(filename, text_content);
    if (result == 1) {
        printf("File created successfully.\n");
    } else if (result == -1) {
        printf("File creation failed.\n");
    }

    return 0;
}
