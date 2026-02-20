Bank Management System - C++ Console Application
📋 Project Overview
A comprehensive Bank Management System developed in C++ that provides a complete solution for banking operations, user management, and currency exchange. This console-based application demonstrates professional software engineering practices with object-oriented design, file-based data persistence, and role-based access control.

✨ Key Features
💰 Core Banking Operations
Client Management: Add, update, delete, and search client records

Account Transactions: Deposit, withdraw, and transfer funds between accounts

Balance Tracking: Real-time balance updates with transaction validation

Transaction History: Complete audit trail of all transfers with timestamps

👥 User Management System
Multi-level Access Control: Granular permissions system for different user roles

User Administration: Create, update, delete system users with specific permissions

Login Security: Password encryption and failed login attempt tracking (3 trials max)

Login Register: Complete log of all system access with timestamps

💱 Currency Exchange Module
Real-time Currency Rates: Manage and update exchange rates for multiple currencies

Currency Calculator: Convert amounts between different currencies

Currency Search: Find currencies by country name or currency code

Rate Management: Update currency rates with proper validation

📊 Reporting & Analytics
Client Lists: Comprehensive view of all clients with sorting options

Balance Reports: Total balances across all accounts with number-to-text conversion

User Activity Logs: Complete audit trail of system access

Transfer Logs: Detailed record of all money transfers

🏗️ Technical Architecture
Object-Oriented Design
Base Classes: clsPerson (foundation for all person entities)

Inheritance: clsBankClient and clsUser inherit from clsPerson

Encapsulation: Private members with controlled access through public methods

Polymorphism: Method overriding for specialized behaviors

Data Management
File-based Storage: All data persisted in text files with custom separators

Data Encryption: Sensitive information (passwords) encrypted before storage

CRUD Operations: Complete Create, Read, Update, Delete functionality

Screen Hierarchy
Base Screen Class: clsScreen provides common UI elements and access control

Specialized Screens: Each functional area has dedicated screen classes

Consistent UI: Uniform interface design across all modules

🔒 Security Features
Password Encryption: Using custom encryption/decryption algorithms

Permission-based Access: 7 distinct permission levels + full access

Login Protection: 3-attempt lockout to prevent brute force attacks

Audit Trail: Complete logging of all system access

📁 File Structure
ClientsData.txt - Client records storage

Users.txt - System user accounts (encrypted passwords)

Login Register.txt - User login history

TransferLog.txt - Money transfer records

Currencies.txt - Currency exchange rates

🚀 Getting Started
Compile the application using any C++ compiler (C++11 or later)

Default login credentials: Admin account with full permissions

Navigate menus using numeric options (1-10)

Manage clients, perform transactions, and configure currency rates

💼 Business Value
Enterprise-ready: Scalable architecture suitable for small to medium banking operations

Audit Compliance: Complete transaction and access logging for regulatory requirements

Multi-currency Support: Ideal for international banking operations

User-friendly Interface: Intuitive console menus with clear navigation

Extensible Design: Easy to add new features or integrate with databases

🏆 Why Choose This System?
Professional Code Quality: Clean, maintainable, well-documented code

Real-world Functionality: Covers actual banking operations

Security-focused: Built with data protection in mind

Comprehensive Reporting: All data accessible through organized reports

Modular Design: Easy to enhance and customize
