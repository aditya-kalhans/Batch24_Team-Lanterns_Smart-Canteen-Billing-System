# Batch24_Team-Lanterns_Smart-Canteen-Billing-
# Canteen Billing System

## Project Overview

The **Canteen Billing System** is a C-based application developed to simplify canteen operations such as menu management, customer ordering, automatic bill generation, transaction storage, and sales reporting.

The project is divided into three main modules, with each team member responsible for a specific part of the system.

---

## Team Members

| Member | Name | Module |
|---|---|---|
| Member 1 | **Aditya Kalhans** | Menu Management |
| Member 2 | **Aarab Pandey** | Order & Billing Management |
| Member 3 | **Manav Rawat** | Transaction & Sales Management |

---

## Member 1 – Menu Management
**Developer: Aditya Kalhans**

Responsibilities:

- Display the canteen menu
- Add new food items
- Update food item prices
- Change item availability
- Remove food items
- Maintain food item details using structures

---

## Member 2 – Order & Billing Management
**Developer: Aarab Pandey**

Responsibilities:

- Take customer orders
- Accept item IDs and quantities
- Check item availability
- Calculate the total bill
- Apply a **5% discount when the bill exceeds Rs. 300**
- Generate the final customer bill

---

## Member 3 – Transaction & Sales Management
**Developer: Manav Rawat**

Responsibilities:

- Store customer transaction details
- Maintain order IDs
- Save transaction records using file handling
- Display transaction history
- Calculate total sales
- Calculate average bill amount
- Display the daily sales report
- Clear transaction records through the admin panel

---

## Main Features

- Dynamic canteen menu
- Food ordering system
- Automatic bill calculation
- 5% discount on orders above Rs. 300
- Customer name and order ID generation
- Transaction history
- File handling using `customerdetails.txt`
- Daily sales report
- Average bill calculation
- Admin panel
- Menu item availability management

---

## Technologies Used

- **Programming Language:** C
- **Concepts:** Functions, Structures, Arrays, Loops, Conditional Statements, Strings and File Handling
- **Data Storage:** Text file (`customerdetails.txt`)

---

## How to Run

1. Download or clone the project.
2. Open the C source file in a C compiler or IDE such as VS Code, Code::Blocks, Dev-C++, or GCC.
3. Compile the program.
4. Run the executable.
5. Select an option from the main menu.

Example using GCC:

```bash
gcc canteen.c -o canteen
./canteen
```

---

## Program Modules

```text
              CANTEEN BILLING SYSTEM
                       |
       +---------------+---------------+
       |               |               |
       v               v               v
 Menu Management   Order & Billing   Admin Panel
       |               |               |
   Member 1          Member 2          Member 3
       |               |               |
 Add/Update Menu   Generate Bill    Transactions
 Availability      Apply Discount   Sales Reports
 Remove Items      Take Orders      File Handling
```

---

## Discount Policy

Customers receive a **5% discount** when their total order value is greater than **Rs. 300**.

Example:

```text
Total Amount  : Rs. 400.00
Discount (5%) : Rs. 20.00
Final Amount  : Rs. 380.00
```

---

## File Handling

The program stores transaction information inside:

```text
customerdetails.txt
```

Each transaction contains:

- Order ID
- Customer Name
- Final Bill Amount

Example:

```text
1,Aditya,304.00
2,Rahul,190.00
3,Aman,475.00
```

---

## Conclusion

The Canteen Billing System provides a simple solution for managing canteen menus, customer orders, billing, and transaction records. The project demonstrates the practical implementation of fundamental C programming concepts while dividing the system into independent but interconnected modules developed by three team members.
