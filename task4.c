#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a text file using Run-Length Encoding (RLE)
void compress(FILE *input, FILE *output) {
    char currentChar, previousChar;
    int count;

    // Read the first character from the file
    previousChar = fgetc(input);
    
    // Continue reading the file and apply Run-Length Encoding
    while (previousChar != EOF) {
        count = 1;

        // Read the next character
        currentChar = fgetc(input);
        
        // Count how many times the previous character repeats consecutively
        while (currentChar == previousChar && currentChar != EOF) {
            count++;
            currentChar = fgetc(input);
        }

        // Write the character and the count to the output file
        fprintf(output, "%c%d", previousChar, count);
        
        // Update previousChar for the next iteration
        previousChar = currentChar;
    }

    printf("Compression complete.\n");
}

// Function to decompress a file compressed with Run-Length Encoding (RLE)
void decompress(FILE *input, FILE *output) {
    char currentChar;
    int count;

    // Read the input file character by character
    while (fscanf(input, "%c%d", &currentChar, &count) != EOF) {
        // Write the character to the output file 'count' times
        for (int i = 0; i < count; i++) {
            fputc(currentChar, output);
        }
    }

    printf("Decompression complete.\n");
}

int main() {
    int choice;
    char inputFileName[100], outputFileName[100];
    FILE *inputFile, *outputFile;

    printf("Run-Length Encoding (RLE) Compressor/Decompressor\n");
    printf("1. Compress a file\n");
    printf("2. Decompress a file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar();  // To consume the newline character after entering the choice

    // Ask for input and output file names
    printf("Enter input file name: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = '\0';  // Remove trailing newline

    printf("Enter output file name: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = '\0';  // Remove trailing newline

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Perform the compression or decompression based on user input
    if (choice == 1) {
        compress(inputFile, outputFile);
    } else if (choice == 2) {
        decompress(inputFile, outputFile);
    } else {
        printf("Invalid choice.\n");
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
