# 🏦 Bank Management System (C++ OOP Console App)

> A modular, menu-driven **C++ console application** implementing a complete **Bank Management System** using **Object-Oriented Programming (OOP)** principles — built with scalability, security, and maintainability in mind.

---

## 📌 Overview

This project simulates a real-world banking environment that supports:
- **User Authentication and Role-Based Authorization**
- **Client Account Management**
- **Currency Exchange and Rate Tracking**
- **Secure Transactions with Logging and Validation**

It is designed with clear separation of concerns and encapsulated classes for screens, users, clients, and currencies — making it **extensible**, **testable**, and ideal for showcasing **advanced C++ skills**.

---

## ✨ Features

### 👥 User Management
- 🔐 **Authentication with Encrypted Passwords**
- 🧑‍💼 **Role-Based Access Control** (Admin/User)
- 📋 List All Users (Username, Permission, Encrypted Passwords)
- ➕ Add New User
- ✏️ Update Existing User
- ❌ Delete User with Confirmation
- 🔎 Find User by Username
- 🛡️ Security:
  - Password encryption (stored in files)  
  - Lock system after **3 failed login attempts**

---

### 🧾 Client Management
- 📋 List All Clients (Text-file backed database)
- ➕ Add New Client
- ✏️ Update Client Information
- ❌ Delete Client Safely
- 🔎 Find Client by Account Number
- 💳 Financial Transactions:
  - Deposit / Withdraw  
  - Transfer funds between clients  
  - View transaction logs
- 🔒 Validations:
  - Email format  
  - Phone number  
  - Pin code strength  
  - Duplicate checks

---

### 💱 Currency Management
- 📋 List All Supported Currencies
- 🔎 Find by Code or Country
- ✏️ Update USD Rate
- 🔁 Convert Between Currencies
- 📂 Currency data persisted in text files
- ✅ Input validation & error handling

---

## ⚙️ System Architecture

### 🧱 Object-Oriented Design

Fully modular design with **layered architecture**, applying principles of:
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction


### 📁 Project Structure


### Object-Oriented Architecture

📦 Bank system project/
├── 📂 Source Files
│   └── Course 11 OOP Application.cpp

├── 📂 Header Files
│   ├── Global.h
│   


├── 📂 Core
│   │   ├── clsBankClient.h
│   │   ├── clsCurrency.h
│   │   ├── clsPerson.h
│   │   └── clsUser.h
│   



├── 📂 Screens
│   │   ├── clsMainScreen.h
│   │   ├── clsScreen.h
│   │  





├── 📂 Client
│   │   │   
├── clsAddNewClientScreen.h
│   │   │   
├── clsClientListScreen.h
│   │   │   
├── clsDeleteClientScreen.h
│   │   │  
├── clsUpdateClientScreen.h
│   │   │   
├── clsFindClientScreen.h
│   │   │  
├── clsDepositScreen.h
│   │   │   
├── clsTotalBalancesScreen.h
│   │   │   
├── clsTransacrionsScreen.h
│   │   │   
├── clsTransferLogScreen.h
│   │   │   
├── clsTransferScreen.h
│   │   │   
└── clsWithdrawScreen.h
│   │   





├── 📂 User
│   │   │   
├── clsAddNewUserScreen.h
│   │   │   
├── clsDeleteUserScreen.h
│   │   │   
├── clsFindUsersScreen.h
│   │   │   
├── clsListUsersScreen.h
│   │   │   
├── clsLoginRegisterScreen.h
│   │   │   
├── clsLoginScreen.h
│   │   │   
├── clsManageUsersScreen.h
│   │   │   
└── clsUpdateUserScreen.h
│   │   


└── 📂 Currency
│   │       
├── clsCurrenciesListScreen.h
│   │       
├── clsCurrencyCalculatorScreen.h
│   │       
├── clsCurrencyExchangeScreen.h
│   │       
├── clsFindCurrencyScreen.h
│   │       
└── clsUpdateCurrencyRateScreen.h
│   └──


📂 Libraries
│       ├── clsDate.h
│       ├── clsUtil.h
│       ├── clsInputValidate.h
│       ├── clsString.h
│       └── clsPeriod.h
 


---

## 🧪 Validation & Security

- 🔄 Input validation (empty, numeric, string, email)
- 🔐 Encrypted password storage with decoding logic
- ✅ Role-based access enforcement
- 🛑 Lockout mechanism on login failure
- 🧼 Safe deletion confirmations

---

## 💻 User Interface

- Text-based UI with screen clearing for clean transitions
- Organized menus for:
  - 👤 User Operations
  - 👥 Client Operations
  - 💲 Currency Tools
- Keyboard prompts, inline hints, and console formatting

---

## 🛠️ Technologies Used

| Category         | Tools/Concepts                     |
|------------------|------------------------------------|
| Language         | Modern C++ (C++11 and above)       |
| Programming Style| Object-Oriented Programming (OOP)  |
| Libraries        | `<iostream>`, `<vector>`, `<string>`, `<fstream>`, `<iomanip>`, `<cstdlib>` |
| Concepts Applied | Classes, Inheritance, Encapsulation, Polymorphism, File I/O , Abstraction|

---

## ▶️ Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Youssef-Abu-Abdallah/Bank-system-OOP.git
cd Bank-system-OOP
```
To login please check premade users in `Users.txt` and pick any one and login with his acces status **0 means has no access , -1 means has full access (admin)**

## Contact Info :
- LinkedIn [Youssef Abu-Abdallah](https://www.linkedin.com/in/youssef-abu-abdallah-467b202a6/)
- Email youssef.abu.abdallah1@gmail.com
