# SimpleDB-Cpp

A basic, from-scratch Database Engine built in C++ for learning purposes. This project demonstrates how command-line parsing, tokenization, and file-based data persistence work in a database environment.

## 🚀 Features
- **Custom Lexer:** Splits user input into commands (tokens) using `stringstream`.
- **Command Parser:** Handles `CREATE`, `INSERT`, and `EXIT` commands.
- **Persistence:** Data is stored in physical `.csv` files on your local machine.
- **Case Insensitive:** Commands work whether you type `create` or `CREATE`.

## 🛠️ How it Works
The engine follows a three-step process for every command:
1. **Tokenize:** The `split()` function breaks the input string into a vector.
2. **Identify:** The `toUpper()` function identifies the action (e.g., INSERT).
3. **Execute:** The `database` class interacts with the file system using `fstream`.

## 📂 Project Structure
- `main.cpp`: Contains the REPL (Read-Eval-Print Loop) and command logic.
- `database class`: Manages file I/O operations.
- `*.csv`: Tables are automatically generated as CSV files.

## 🏃 How to Run
1. Clone the repository.
2. Compile using G++:
   ```bash
   g++ main.cpp -o simpledb
