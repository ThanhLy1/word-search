# Word Finder Program

This program is a simple command-line tool that helps you find words from a dictionary based on specific constraints. You can input a set of alphabets, and the program will display words from the dictionary that can be formed using those alphabets while adhering to certain length constraints.

## Features

- Find words from the dictionary based on a set of non-repeating alphabets.
- Specify the maximum length of the words to be displayed.
- Add new words to the dictionary.
- Remove words from the dictionary.

## Building and Running

The program can be built and run using the provided Makefile. Here are the available commands:

- `make`: Compiles the program and generates the executable `main`.
- `make clean`: Removes the compiled object files and the executable.
- `make test`: Compiles and runs the program for testing.

The Makefile uses the following variables:

- `CXX`: The C++ compiler.
- `CXXFLAGS`: Compilation flags such as `-std=c++11 -Wall -Wextra`.
- `SRCS`: Source files (e.g., `main.cpp`).
- `OBJS`: Compiled object files.
- `EXEC`: Name of the executable.

Make sure to customize the Makefile according to your project structure and requirements.

## How to Use

Follow the prompts: The program will ask you to input non-repeating alphabets or special commands. You can enter alphabets, use commands like -add to add words, and use -remove to remove words.

View results: The program will display words from the dictionary that can be formed using the provided alphabets and adhere to the specified constraints.

Exit the program: To exit the program, simply enter exit or quit when prompted for alphabets.

## Commands
- `exit` or `quit`: Exits the program.
- `-add`: Allows you to add a new word to the dictionary.
- `-remove`: Allows you to remove a word from the dictionary.

## Notes
- The dictionary is loaded from a file named `dictionary.txt`. Make sure this file is present in the same directory as the program.
- Words in the dictionary should be listed one per line in the `dictionary.txt` file.
- The program checks each word in the dictionary against the provided alphabets and length constraints. Only words that meet the criteria are displayed.
- The program displays words in columns based on their length, with a maximum of 20 characters per column.
- Words must contain only the alphabets provided.

## Contributing
Contributions to this program are welcome! Feel free to fork the repository, make improvements, and submit pull requests.

