#include "ProduceFrequency.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

// convert string to lowercase
static string ToLower(const string& s) {
    string out = s;
    transform(out.begin(), out.end(), out.begin(),
              [](unsigned char c) { return tolower(c); });
    return out;
}

ProduceFrequency::ProduceFrequency()
    : m_inputFileName("data/CS210_Project_Three_Input_File.txt"),
      m_backupFileName("output/frequency.dat")
{
    LoadDataFromFile();
    WriteBackupFile();
}

void ProduceFrequency::LoadDataFromFile() {
    ifstream inputFile(m_inputFileName);

    // check if input file can be accessed
    if (!inputFile) {
        cerr << "Error: Unable to open the input file: " << m_inputFileName << endl;
        return;
    }

    string item;
    while (inputFile >> item) {
        ++m_itemFrequency[ToLower(item)];
    }

    inputFile.close();
}

void ProduceFrequency::WriteBackupFile() const {
    ofstream outFile(m_backupFileName);

    // check if output file can be accessed
    if (!outFile) {
        cerr << "Error: Unable to open backup file: " << m_backupFileName << endl;
        return;
    }

    for (const auto& pair : m_itemFrequency) {
        outFile << pair.first << " " << pair.second << "\n";
    }

    outFile.close();
}

int ProduceFrequency::GetItemFrequency(const string& item) const {
    auto it = m_itemFrequency.find(ToLower(item));

    if (it != m_itemFrequency.end()) {
        return it->second;
    }

    // Item not found
    return 0;
}

void ProduceFrequency::PrintAllFrequencies() const {
    if (m_itemFrequency.empty()) {
        cout << "No data available to display frequencies.\n";
        return;
    }

    cout << "\nProduce Purchase Frequencies:\n";
    for (const auto& pair : m_itemFrequency) {
        cout << pair.first << ": " << pair.second << '\n';
    }
}

void ProduceFrequency::PrintHistogram() const {
    if (m_itemFrequency.empty()) {
        cout << "No data available to display histogram.\n";
        return;
    }

    cout << "\nProduce Purchase Frequency Histogram:\n";
    for (const auto& pair : m_itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << " (" << pair.second << ")\n";
    }
}

void ProduceFrequency::RunMenu() {
    int choice = 0;
    bool running = true;

    while (running) {
        cout << "\n===== Produce Purchase Frequency Analyzer =====\n";
        cout << "1. Search for item frequency\n";
        cout << "2. Print all frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        string inputLine;
        getline(cin, inputLine);

        // check for empty input or non number
        if (inputLine.empty() || inputLine.find_first_not_of(" \t") == string::npos) {
            cout << "No input entered. Please enter a number between 1 and 4.\n";
            continue;
        }

        // try block for choice
        try {
            choice = stoi(inputLine);
        } catch (...) {
            cout << "Invalid input. Please enter an integer between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "Enter produce item to search: ";
                string item;
                getline(cin, item);

                if (item.empty() || item.find_first_not_of(" \t") == string::npos) {
                    cout << "No item entered. Please try again.\n";
                    break;
                }

                int freq = GetItemFrequency(item);
                if (freq > 0) {
                    cout << item << " was purchased " << freq << " times.\n";
                } else {
                    cout << "Item \"" << item << "\" not found.\n";
                }
                break;
            }
            case 2:
                PrintAllFrequencies();
                break;
            case 3:
                PrintHistogram();
                break;
            case 4:
                cout << "Exiting program.\n";
                running = false;
                break;
            default:
                cout << "Please enter an integer between 1 and 4.\n";
                break;
        }
    }
}
