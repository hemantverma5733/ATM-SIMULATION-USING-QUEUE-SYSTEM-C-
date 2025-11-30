🏧 ATM Management System (C++)

This project is a console-based ATM Simulation System built using C++ and Object-Oriented Programming (OOP) concepts. It demonstrates how a basic ATM works in real life, including authentication, secure transactions, maintaining history, and a PIN change system using OTP verification. The project is designed to be simple, easy to understand, and highly suitable for beginners learning OOP in C++.


🚀 Project Overview

The ATM system allows a user to log in using a PIN, perform basic banking operations, and view their account and bank details. It uses C++ classes, objects, vectors, structures, and clean menu-driven navigation. The main purpose is to provide a real-world simulation of ATM functionalities within a command-line environment.



🧩 Key Features

✅ 1. User Authentication
	•	Secured login using a 4-digit PIN.
	•	Access denied if PIN is incorrect.

✅ 2. Balance Enquiry
	•	Displays live account balance using formatted output.

✅ 3. Cash Withdrawal
	•	Withdraw specific amount.
	•	Checks for insufficient balance.
	•	Updates balance and logs transaction.

✅ 4. Cash Deposit
	•	Allows user to deposit any valid amount.
	•	Automatically updates balance.
	•	Saves transaction to history.

✅ 5. Transaction History
	•	Uses vector<Transaction> to store past actions.
	•	Displays type, amount, and balance after each transaction.

✅ 6. Bank Account Details
	•	Shows the following details:
	•	Account Holder Name
	•	Account Number
	•	Bank Name
	•	Branch Name
	•	IFSC Code
	•	Registered Mobile Number

✅ 7. Change ATM PIN (OTP-Based Security)
	•	Generates a secure 4-digit OTP.
	•	OTP is “sent” to registered mobile (simulation).
	•	New PIN can be set only after successful OTP verification.

⸻

🛠️ Technologies & Concepts Used
	•	C++ Classes & Objects
	•	Encapsulation
	•	Structures
	•	Vectors (dynamic storage)
	•	Conditional statements and loops
	•	Random OTP generation
	•	Input/Output formatting using iomanip

⸻

📌 Conclusion

This ATM Management System provides a realistic implementation of core ATM functions in a simple C++ program. With features like transaction history, bank details display, and OTP-based PIN change, it gives a strong understanding of OOP principles and real-world banking system workflows.
