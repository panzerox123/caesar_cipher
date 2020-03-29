#include<stdio.h>
#include<string.h>

char * encrypt(char *, int);

char * decrypt(char *, int);

int main(){
    char test[50], test2[50];
    printf("Enter the word to be Caesar'd\n");
    scanf("%s", test);
    printf("%s\n",encrypt(test,5));
    scanf("%s", test2);
    printf("%s\n",decrypt(test2,4));
    return 0;
}

char * encrypt(char *message, int shift_key){
    char *index = message;
    while(*index != '\0'){
        if(*index == ' '){
            index++;
            continue;
        }
        if(*index>='A' && *index <='Z'){
            if(*index + shift_key > 'Z')
                *index = *index + shift_key-26;
            else *index = *index+shift_key;
        }
        if(*index>='a'&&*index<='z'){
            if(*index + shift_key > 'z')
                *index = *index + shift_key-26;
            else *index = *index+shift_key;
        }

        index++;
    }
    return message;
}

char * decrypt(char *message, int shift_key){
    char *index = message;
    while(*index != '\0'){
        if(*index == ' '){
            index++;
            continue;
        }
        if(*index>= 'A' && *index <= 'Z'){
            if(*index - shift_key < 'A')
                *index = *index - shift_key+26;
            else
                *index = *index-shift_key;
        }

        if(*index >='a' && *index <='z'){
            if(*index - shift_key < 'a')
                *index = *index - shift_key+26;
            else *index = *index-shift_key;
        }
        index++;
    }
    return message;
}
