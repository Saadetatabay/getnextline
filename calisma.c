#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    int fd;
    char buffer[30];
    int count;
    fd = open("calisma.txt", O_RDWR| O_CREAT | O_TRUNC, 0644);
    write(fd, "hello world it's saadet\n", 25); //write offseti 25 yaptı
    lseek(fd, 0, SEEK_SET); // Move the file pointer to the beginning
    count=read(fd, buffer, 5);
    buffer[5] = '\0'; // Null-terminate the string
    printf("%s\n", buffer);
    printf("Number of bytes read: %d\n", count);
    count = read(fd, buffer, 10);
    buffer[10] = '\0'; // Null-terminate the string
    printf("%s\n", buffer);
    printf("Number of bytes read: %d\n", count);

    close(fd);
}