#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int admin = 0;
char* key;
char* password_entry;

void check_password(char* key, char* pw) {
    if((strlen(pw) >= 16 && strncmp(key, pw, 16) == 0) || admin == 1){
        puts("Correct password!");
        if(admin){
            puts("Welcome, admin!");
        }
        exit(0);
    }
    else{
        puts("Incorrect password");
    }
}

void get_password() {
    FILE *fp;
    fp = fopen("key.txt", "r");
    if(fp == NULL){
        puts("No key.txt file present");
        exit(-1);
    }
    key = malloc(32*sizeof(char));
    fgets(key, 32, fp);
    char buf[32];
    puts("Password?");
    gets(buf);
    password_entry = malloc(sizeof(char) * 32);
    strncpy(password_entry, buf, 16);
    return;
}

int main() {
    get_password();
    check_password(key, password_entry);
    return 0;
}
