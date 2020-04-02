#include<stdio.h>
#include<string.h>
#include"cypher.h"

/*
int main(){
    int case_no; FILE *fPointer;
    printf("### CAESAR_CYPHER ###\n");
    printf("Enter your name\n"); char name[50];
    scanf("%s",name);
    printf("Type 1 to encrypt your data \nType 2 to decrypt your data\nType 3 to exit\n");
    scanf("%d",&case_no);
    switch (case_no)
    {
    case 1:
        fPointer=fopen("data.xlsx","a");
        printf("Enter data to be encrypted\n");
        char data_encrypt[100]; scanf(" ");gets(data_encrypt); fprintf(fPointer,"%s",name);
        printf("Enter encryption number\n"); int n; scanf("%d",&n); fprintf(fPointer,",%s,%d,%s","encryption",n,data_encrypt);
        char temp1[100]; strcpy(temp1,encrypt(data_encrypt,n));
        printf("%s\n",temp1);
        fprintf(fPointer,",%s\n",temp1);
        fclose(fPointer);
        break;
    case 2:
        fPointer=fopen("data.xlsx","a");
        printf("Enter data to be decrypted\n");
        char data_decrypt[100]; gets(data_decrypt); fprintf(fPointer,"%s",name);
        printf("Enter decryption number\n"); int m; scanf("%d",&m);fprintf(fPointer,",%s,%d,%s","decryption",m,data_decrypt);
        char temp2[100]; strcpy(temp2,decrypt(data_decrypt,m));
        printf("%s\n",temp2);
        fprintf(fPointer,",%s\n",temp2);
        fclose(fPointer);
        break;
      case 3:
        printf("exiting...\n");
        break;
    default:
        {printf("invalid choice, please enter your choice again\n");
        main();}
    }
    return 0;
}
*/

char * encrypt(char *message, int shift_key){
    char *index = message;
    while(*index != '\0'){
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

void write_to_file(char * word, int key, char * out, char * type){
    FILE * fPointer = fopen("Data.xlsx","a");
    fprintf(fPointer,"%s,%s,%d,%s\n",type,word,key,out);
    fclose(fPointer);
}

