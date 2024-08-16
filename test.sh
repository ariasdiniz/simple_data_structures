#!/bin/bash

# Created by Aria Diniz on January 5, 2024
# This script was created with the objective of simplifying the compilation of C programs from command line.
# Created for GCC compiler on Linux. Can be used for other compilers and OSs with minor modifications.

# Directory with the files to compile. It will search for files with extension .c and .h on every dir 
# inside this directory.
# Caution, when pointed to the software's main folder it can compile the tests along with the program.
directory="src"
test_dir="test"

# Find all files with the specified extension in the directory and its subdirectories
# and read them into an array
readarray -t files < <(find "$directory" -type f \( -name "*.c" -o -name "*.h" \))
readarray -t testfiles < <(find "$test_dir" -type f \( -name "*.c" -o -name "*.h" \))

# Initialize an empty string to hold all file names
all_files=""

# Loop through the array and append each file name to the string
for file in "${files[@]}"; do
    all_files+="$file "
done
for file in ${testfiles[@]}; do
    all_files+="$file "
done

# Compile the result
echo "Compiling..."
gcc -o tests $all_files
echo "Compilation finished."

# Run the program
echo "Running..."
chmod u+x tests

valgrind --leak-check=yes ./tests
# ./tests
echo "Program finished."

# Remove the executable
rm tests

