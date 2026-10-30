#include<stdio.h>
#include<stdlib.h>
int main(){
    int ch;
    char key;
    printf("Enter key: "); //Key required for decryption
    scanf("%c", &key);

    //Step 1: Read the existing plaintext file 
    FILE *temp=fopen("Newfile.txt","r");
    if(temp==NULL){
        printf("NOTHING IS IN THE FILE");
        return 1;
    }

    //2. Creating and opening Decrypted text file.
    FILE *temp2=fopen("Decrypt.txt","w");
    if(temp2==NULL){
        printf("Memory not available");
        return 1;
    }

    //3. Decryption process
    ch=fgetc(temp);
    while(ch!=EOF){
        ch=ch^key;
        fputc(ch,temp2);
        ch=fgetc(temp);
    }

    fclose(temp);
    fclose(temp2);

    printf("Decryption success!!'\n");
    printf("Check 'Decrypt.txt' file");
    return 0;
    

}