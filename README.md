
# Invoice Generator – School Project

This is a simple C project for generating, validating, and managing invoices. It was developed as part of a university assignment and demonstrates core programming concepts such as structures, file I/O, string manipulation, and dynamic memory allocation.

---

## 📁 Files

- **`main.c`**  
  A sample file that demonstrates how to use the invoice functions: generating invoices, checking their validity, saving to file, and reading from file.

- **`invoice.c`**  
  Contains the core logic for:
  - Generating invoices using specific attribute algorithms.
  - Printing invoices and their attributes.
  - Saving invoices to a file and loading them.
  - Validating invoice dates (e.g., not in the future and if the date previously exists).

- **`invoice.h`**  
  Header file defining constants, data structures, and function prototypes used across the project.

---

## 🧠 Features

- ✅ Automatically generates fake invoice data using predefined rules.
- 🖨️ Prints invoices or just specific attributes.
- 💾 Saves invoices to a file and reads them back.
- 🔍 Validates invoice data:
  - Checks if the invoice date is valid based on a list of invoice dates (not after current month/year).
  - Checks if the invoice date is valid (not after current month/year).

---

## 🚀 How to Run

1. Compile the project:
   ```bash
   gcc main.c invoice.c -o invoicegen
   ```

2. Run the program:
   ```bash
   ./invoicegen
   ```

> Make sure you have `gcc` installed and you're in the correct folder.

---

## 📌 Notes

- This is a **basic academic project**.
- The invoice generation logic is based on simple patterns and hardcoded values (e.g., current month/year as `06/25`).
- Output is printed to console and saved to `invoices.txt`.

---

## 📚 License

This project is shared for educational purposes only. No license.
