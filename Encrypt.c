#include <stdio.h>
#include <stdlib.h>

int main() {
    char data[100];
    int ch; // Changed to int to properly catch EOF
    char key;
    FILE *source, *temp;

    // 1. Get encryption key and text from user
    printf("Enter encryption key: ");
    scanf(" %c", &key); // Space before %c clears any leftover newline characters

    // Clear the leftover newline character out of the input stream
    while ((ch = getchar()) != '\n' && ch != EOF);  
    printf("Enter the text: ");
    fgets(data,sizeof(data),stdin); 

    // 2. Step One: Open data.txt in write mode and save user input
    source = fopen("data.txt", "w");
    if (source == NULL) {
        printf("ERROR: Could not create data.txt\n");
        return 1;
    }
    fprintf(source, "%s", data);
    fclose(source); // Close it to ensure data is written and saved

    // 3. Step Two: Reopen data.txt to read and encrypt into Newfile.txt
    source = fopen("data.txt", "r");
    if (source == NULL) {
        printf("ERROR: File data.txt not found\n");
        return 1;
    }

    temp = fopen("Newfile.txt", "w");
    if (temp == NULL) {
        printf("ERROR: Memory not free or cannot create Newfile.txt\n");
        fclose(source);
        return 1;
    }
    
    // 4. Run the encryption loop
    ch = fgetc(source);
    while (ch != EOF){
        ch = ch ^ key; // XOR encryption operation
        fputc(ch, temp);
        ch = fgetc(source);
    }

    // 5. Clean up and close remaining files
    fclose(source);
    fclose(temp);

    printf("\nSuccess! Raw text saved to 'data.txt'.\n");
    printf("Encrypted text successfully saved to 'Newfile.txt'.\n");

    return 0;
}
