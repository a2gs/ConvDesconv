# ConvDesconv
Convert a binary file to HEX ASCII values and desconvert to binary again.

Usage:

$ ./conv BINARY_File.bin > out

Now, out is a 'ASCII' (printable) file.

$ cat out | ./desconv BINARY_File_AGAIN.bin

BINARY_File.bin and BINARY_File_AGAIN.bin MUST be (same hash) the same file.
