#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iomanip>

#define MAX_ALPHABETS 26

// Function to check if a word contains only the given alphabets
bool containsOnlyAlphabets(const std::string& word, const std::string& inputAlphabets) {
    std::unordered_map<char, int> inputAlphabetCount;
    for (char c : inputAlphabets) {
        inputAlphabetCount[c]++;
    }

    for (char c : word) {
        if (inputAlphabetCount.find(c) == inputAlphabetCount.end() || inputAlphabetCount[c] == 0) {
            return false;
        }
        inputAlphabetCount[c]--;
    }

    return true;
}

int main() {
    // Open the dictionary file for reading
    std::ifstream readFile("dictionary.txt");
    if (!readFile) {
        std::cout << "Error opening the dictionary file." << std::endl;
        return 1;
    }

    // Read the dictionary from the file
    std::vector<std::string> dictionary;
    std::string word;
    while (std::getline(readFile, word)) {
        // Remove the newline character at the end of each word
        word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());
        dictionary.push_back(word);
    }

    // Close the reading file
    readFile.close();

    while (true) {
        // Get the input for non-repeating alphabets or special commands
        std::cout << "Enter non-repeating alphabets or 'exit'/'quit' to end, '-add' to add a word: ";
        std::string inputAlphabets;
        std::cin >> inputAlphabets;

        if (inputAlphabets == "exit" || inputAlphabets == "quit") {
            break; // Exit the loop if "exit" or "quit" is entered
        }

        if (inputAlphabets == "-add") {
            std::string newWord;
            std::cout << "Enter the word you want to add: ";
            std::cin >> newWord;

            // Open the dictionary file for appending
            std::ofstream writeFile("dictionary.txt", std::ios_base::app);
            writeFile << newWord << "\n";
            writeFile.close();

            // Add the word to the in-memory dictionary
            dictionary.push_back(newWord);

            std::cout << "Word added to dictionary." << std::endl;
            continue; // Continue to the next iteration
        }

        if (inputAlphabets == "-remove") {
    std::string wordToRemove;
    std::cout << "Enter the word you want to remove: ";
    std::cin >> wordToRemove;

    // Remove the word from the in-memory dictionary
    dictionary.erase(std::remove(dictionary.begin(), dictionary.end(), wordToRemove), dictionary.end());

    // Write the updated dictionary back to the file
    std::ofstream writeFile("dictionary.txt");
    for (const std::string& dictWord : dictionary) {
        writeFile << dictWord << "\n";
    }
    writeFile.close();

    std::cout << "Word removed from dictionary." << std::endl;
    continue; // Continue to the next iteration
}

        // Convert the input alphabets to a set for efficient lookup
        std::unordered_set<char> chosenAlphabets(inputAlphabets.begin(), inputAlphabets.end());

        // Check each word in the dictionary for the chosen alphabets and length constraint
        // Sort words by their length
        std::map<int, std::vector<std::string>, std::greater<int>> wordsByLength;
        for (const std::string& dictWord : dictionary) {
            if (containsOnlyAlphabets(dictWord, inputAlphabets) &&
                dictWord.length() <= inputAlphabets.length() && dictWord.length() > 2) {
                wordsByLength[dictWord.length()].push_back(dictWord);
            }
        }

        // Print words by length in separate columns
        size_t maxRows = 0;
        for (const auto& pair : wordsByLength) {
            maxRows = std::max(maxRows, pair.second.size());
        }

        for (size_t row = 0; row < maxRows; ++row) {
            for (const auto& pair : wordsByLength) {
                if (row < pair.second.size()) {
                    std::cout << std::setw(20) << std::left << pair.second[row];
                } else {
                    std::cout << std::setw(20) << " ";
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}

