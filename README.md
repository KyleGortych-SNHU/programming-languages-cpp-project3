# programming-languages-cpp-project3
Programming languages class with C++ Project 3.

## Getting Started

<details>
<summary>Commands (click me)</summary>

To build 
```sh
make
```

To run the executable
```sh
make run
```

To clean
```sh
make clean
```

</details>

## Reflection

- Summarize the project and what problem it was solving.

    The project was to create a program that would track items in a file. The
    program on startup would generate an output data file that would layout the
    amounts of items.

- What did you do particularly well?

    I feel I started well by first making the uml via plantuml. By first laying
    out what the header would entail it made it easier to implement.

- Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

    An improvment I could make is to finish implementing the exception handling.

    <details>
    <summary>main.cpp Exception (click me)</summary>
    
    ```cpp
    int main () {
      // adding a try catch exception for future implemented throw
      try {
        ProduceFrequency pf;
        pf.RunMenu();
      } catch(const exception& e) {
        cerr << "iostream error: " << e.what() << "\n";
        return 1;
      }
    
      return 0;
    }
    ```
    
    </details>

- Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

    The most challengin parts I found was implementing the user validation and
    histogram layout. I used the [Python
    Tutor](https://pythontutor.com/cpp.html#) for help visualizing and
    debuging. 


    <details>
    <summary>User Validation Example (click me)</summary>
    
    ```cpp
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
    ```
    
    </details>

- What skills from this project will be particularly transferable to other projects or course work?

    The most transferable part of this project is the directory layout and use of
    the make file. By having specific paths for c++ projects it helps in making it
    easier for implementing the make file and overall simplicity in .


- How did you make this program maintainable, readable, and adaptable?

    I made the program maintainable by adding line comments to describe each part
    and functionality. It was made readable by formating it based on standard
    practices such as adding identifiers to names to indicate what is private vs
    the public. The project was made adaptable as I added in the make file an check
    to see which arrch is being used so the user only has to run **make**.
