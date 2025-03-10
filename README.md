# DATA-COMPRESSION-TOOL

COMPANY: CODETECH IT SOLUTIONS

NAME: PRIYADHARSHANI L

INTERN ID: CT08SXS

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS

MENTOR: NEELA SANTHOSH

DESCRIBTION:

Run-Length Encoding (RLE) is a simple compression algorithm that replaces sequences of the same character (or data) that occur consecutively with a single character and a count of its occurrences. This can result in significant compression for data that contains many repeating characters.

This program provides two functionalities:

Compression: Compresses a text file by replacing consecutive occurrences of the same character with the character followed by the number of its repetitions.
Decompression: Restores the original text from a compressed RLE file.
Features
Compression:
Compresses text files by converting repeated characters into the character followed by a count of its occurrences.
Decompression:
Converts the compressed RLE format back into the original text by expanding each character-count pair into repeated characters.
File Handling:
Reads and writes to files, making it easy to work with large text files for compression and decompression tasks.
How the Program Works
Compression:
The program reads the input file character by character and counts how many times each character repeats consecutively.
It then writes the character followed by the count to the output file.
Decompression:
The program reads the compressed file, which consists of characters followed by their counts (e.g., a4 represents "aaaa").
It reconstructs the original text by repeating the character for the specified count and writes it to the output file.
Instructions
1. Clone the Repository
bash
Copy
git clone https://github.com/your-username/rle-compressor.git
2. Compile the Program
To compile the C program, use the gcc compiler:

bash
Copy
gcc rle_compressor.c -o rle_compressor
3. Run the Program
Run the program and choose whether you want to compress or decompress a file.

Compress a File
bash
Copy
./rle_compressor
Choose option 1 to compress a file.
Enter the input file name (the file you want to compress).
Enter the output file name (the file where the compressed data will be stored).
Decompress a File
bash
Copy
./rle_compressor
Choose option 2 to decompress a file.
Enter the input file name (the compressed file).
Enter the output file name (the file where the decompressed data will be stored).
Example
Compressing a file:
Input File (input.txt):

nginx
Copy
aaaabbbccdaa
After compression, Output File (output.txt):

nginx
Copy
a4b3c2d1a2
Decompressing the file:
Input File (output.txt containing a4b3c2d1a2):

nginx
Copy
aaaabbbccdaa
Code Structure
rle_compressor.c
compress(): Function to compress the input file using Run-Length Encoding.
decompress(): Function to decompress the file by expanding the RLE data back to its original form.
main(): Entry point of the program that handles user input and file management.
Limitations
The program assumes that the text file contains printable ASCII characters.
The compressed format (character followed by count) works best when there are significant consecutive repetitions of characters.
The program only handles simple text files and does not handle binary files or special character encodings.
