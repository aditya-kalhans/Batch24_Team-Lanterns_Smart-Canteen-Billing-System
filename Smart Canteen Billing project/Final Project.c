#include <stdio.h>
#include <string.h>

// =====================================================
// STRUCTURES
// =====================================================

// Member 1 - Food Item Structure
struct FoodItem
{
    int id;
    char name[50];
    float price;
    int available;
};

// Member 3 - Transaction Structure
struct Transaction
{
    int orderId;
    char customerName[50];
    float amount;
};


// =====================================================
// GLOBAL VARIABLES
// =====================================================

struct FoodItem menu[100];
int itemCount = 5;

int nextOrderId = 1;


// =====================================================
// MEMBER 1 - MENU MANAGEMENT
// =====================================================

// Display Menu
void displayMenu()
{
    printf("\n=============== CANTEEN MENU ===============\n");
    printf("ID\tItem\t\tPrice\t\tStatus\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < itemCount; i++)
    {
        printf("%d\t%-15s\tRs. %.2f\t",
               menu[i].id,
               menu[i].name,
               menu[i].price);

        if(menu[i].available == 1)
            printf("Available\n");
        else
            printf("Unavailable\n");
    }

    printf("--------------------------------------------\n");
}


// Add Item
void addItem()
{
    if(itemCount >= 100)
    {
        printf("\nMenu is full!\n");
        return;
    }

    printf("\nEnter item ID: ");
    scanf("%d", &menu[itemCount].id);

    printf("Enter item name: ");
    scanf(" %49[^\n]", menu[itemCount].name);

    printf("Enter price: ");
    scanf("%f", &menu[itemCount].price);

    menu[itemCount].available = 1;

    itemCount++;

    printf("\nItem added successfully!\n");
}


// Update Item Price
void updateItem()
{
    int id;
    float newPrice;
    int found = 0;

    printf("\nEnter item ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < itemCount; i++)
    {
        if(menu[i].id == id)
        {
            printf("Enter new price: ");
            scanf("%f", &newPrice);

            menu[i].price = newPrice;

            printf("\nPrice updated successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nItem not found!\n");
    }
}


// Change Availability
void changeAvailability()
{
    int id;
    int found = 0;

    printf("\nEnter item ID: ");
    scanf("%d", &id);

    for(int i = 0; i < itemCount; i++)
    {
        if(menu[i].id == id)
        {
            if(menu[i].available == 1)
            {
                menu[i].available = 0;
                printf("\n%s is now Unavailable.\n", menu[i].name);
            }
            else
            {
                menu[i].available = 1;
                printf("\n%s is now Available.\n", menu[i].name);
            }

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nItem not found!\n");
    }
}


// Remove Item
void removeItem()
{
    int id;
    int found = 0;

    printf("\nEnter item ID to remove: ");
    scanf("%d", &id);

    for(int i = 0; i < itemCount; i++)
    {
        if(menu[i].id == id)
        {
            for(int j = i; j < itemCount - 1; j++)
            {
                menu[j] = menu[j + 1];
            }

            itemCount--;

            printf("\nItem removed successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nItem not found!\n");
    }
}


// Menu Management Panel
void menuManagement()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("          MENU MANAGEMENT\n");
        printf("====================================\n");

        printf("1. Display Menu\n");
        printf("2. Add Item\n");
        printf("3. Update Item Price\n");
        printf("4. Change Availability\n");
        printf("5. Remove Item\n");
        printf("6. Back to Main Menu\n");

        printf("------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayMenu();
                break;

            case 2:
                addItem();
                break;

            case 3:
                updateItem();
                break;

            case 4:
                changeAvailability();
                break;

            case 5:
                removeItem();
                break;

            case 6:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 6);
}


// =====================================================
// MEMBER 3 - TRANSACTION MANAGEMENT
// =====================================================


// Save Transaction
void saveTransaction(int orderId, char customerName[], float amount)
{
    FILE *file = fopen("customerdetails.txt", "a");

    if(file == NULL)
    {
        printf("\nFile couldn't be opened.\n");
        return;
    }

    fprintf(file, "%d,%s,%.2f\n",
            orderId,
            customerName,
            amount);

    fclose(file);

    printf("\nTransaction saved successfully.\n");
}


// Display Transactions
void displayTransaction()
{
    FILE *file = fopen("customerdetails.txt", "r");

    struct Transaction t;

    if(file == NULL)
    {
        printf("\nNo transaction records found.\n");
        return;
    }

    printf("\n============================================\n");
    printf("           TRANSACTION HISTORY\n");
    printf("============================================\n");

    printf("%-10s %-20s %-10s\n",
           "Order ID",
           "Customer",
           "Amount");

    printf("--------------------------------------------\n");

    while(fscanf(file,
                 "%d,%49[^,],%f",
                 &t.orderId,
                 t.customerName,
                 &t.amount) == 3)
    {
        printf("%-10d %-20s Rs. %.2f\n",
               t.orderId,
               t.customerName,
               t.amount);
    }

    printf("--------------------------------------------\n");

    fclose(file);
}


// Calculate Total Sales
float calculateTotalSales()
{
    FILE *file = fopen("customerdetails.txt", "r");

    struct Transaction t;

    float totalSales = 0.0;

    if(file == NULL)
    {
        return 0.0;
    }

    while(fscanf(file,
                 "%d,%49[^,],%f",
                 &t.orderId,
                 t.customerName,
                 &t.amount) == 3)
    {
        totalSales = totalSales + t.amount;
    }

    fclose(file);

    return totalSales;
}


// Count Orders
int countOrders()
{
    FILE *file = fopen("customerdetails.txt", "r");

    struct Transaction t;

    int count = 0;

    if(file == NULL)
    {
        return 0;
    }

    while(fscanf(file,
                 "%d,%49[^,],%f",
                 &t.orderId,
                 t.customerName,
                 &t.amount) == 3)
    {
        count++;
    }

    fclose(file);

    return count;
}


// Sales Report
void salesReport()
{
    float total = calculateTotalSales();

    int orders = countOrders();

    printf("\n====================================\n");
    printf("          DAILY SALES REPORT\n");
    printf("====================================\n");

    printf("Total Orders : %d\n", orders);

    printf("Total Sales  : Rs. %.2f\n", total);

    if(orders > 0)
    {
        printf("Average Bill : Rs. %.2f\n",
               total / orders);
    }
    else
    {
        printf("Average Bill : Rs. 0.00\n");
    }

    printf("====================================\n");
}


// Clear Transactions
void clearTransactions()
{
    char confirm;

    printf("\nAre you sure you want to clear all transactions? (y/n): ");

    scanf(" %c", &confirm);

    if(confirm == 'y' || confirm == 'Y')
    {
        FILE *file = fopen("customerdetails.txt", "w");

        if(file == NULL)
        {
            printf("\nFile couldn't be opened.\n");
            return;
        }

        fclose(file);

        printf("\nTransaction records cleared.\n");
    }
    else
    {
        printf("\nOperation cancelled.\n");
    }
}


// Admin Panel
void adminPanel()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("          CANTEEN ADMIN PANEL\n");
        printf("====================================\n");

        printf("1. View Transaction History\n");
        printf("2. View Daily Sales Report\n");
        printf("3. Clear Transaction Records\n");
        printf("4. Exit Admin Panel\n");

        printf("------------------------------------\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayTransaction();
                break;

            case 2:
                salesReport();
                break;

            case 3:
                clearTransactions();
                break;

            case 4:
                printf("\nExiting Admin Panel...\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while(choice != 4);
}


// =====================================================
// MEMBER 2 - ORDER AND BILLING
// =====================================================

void takeOrder()
{
    int choice;
    int quantity;
    int found;

    float total = 0;
    float discount = 0;
    float finalAmount;

    char more;
    char customerName[50];


    // Ask customer name
    printf("\nEnter Customer Name: ");
    scanf(" %49[^\n]", customerName);


    displayMenu();


    do
    {
        found = 0;

        printf("\nEnter item ID: ");
        scanf("%d", &choice);


        // Search for selected item
        for(int i = 0; i < itemCount; i++)
        {
            if(menu[i].id == choice)
            {
                found = 1;


                // Check Availability
                if(menu[i].available == 0)
                {
                    printf("\nSorry! %s is currently unavailable.\n",
                           menu[i].name);

                    break;
                }


                printf("Enter quantity: ");
                scanf("%d", &quantity);


                if(quantity <= 0)
                {
                    printf("\nInvalid quantity!\n");
                    break;
                }


                float itemTotal;

                itemTotal = menu[i].price * quantity;


                printf("%s x %d = Rs. %.2f\n",
                       menu[i].name,
                       quantity,
                       itemTotal);


                total = total + itemTotal;


                break;
            }
        }


        if(found == 0)
        {
            printf("\nInvalid item ID!\n");
        }


        printf("\nDo you want to order something else? (y/n): ");

        scanf(" %c", &more);


    } while(more == 'y' || more == 'Y');



    // =================================================
    // DISCOUNT CALCULATION
    // =================================================

    finalAmount = total;


    if(total > 300)
    {
        discount = total * 0.05;

        finalAmount = total - discount;
    }



    // =================================================
    // FINAL BILL
    // =================================================

    printf("\n====================================\n");
    printf("             FINAL BILL\n");
    printf("====================================\n");

    printf("Customer Name : %s\n", customerName);

    printf("Order ID      : %d\n", nextOrderId);

    printf("------------------------------------\n");

    printf("Total Amount  : Rs. %.2f\n", total);


    if(total > 300)
    {
        printf("Discount (5%%) : Rs. %.2f\n", discount);
    }


    printf("------------------------------------\n");

    printf("Final Amount  : Rs. %.2f\n",
           finalAmount);

    printf("====================================\n");

    printf("       Thank you! Visit Again\n");

    printf("====================================\n");



    // =================================================
    // AUTOMATICALLY SAVE TRANSACTION
    // =================================================

    saveTransaction(nextOrderId,
                    customerName,
                    finalAmount);


    // Increase Order ID
    nextOrderId++;
}


// =====================================================
// MAIN PROGRAM
// =====================================================

int main()
{
    int choice;


    // Default Menu

    menu[0] = (struct FoodItem)
    {1, "Burger", 80, 1};

    menu[1] = (struct FoodItem)
    {2, "Sandwich", 60, 1};

    menu[2] = (struct FoodItem)
    {3, "Maggi", 50, 1};

    menu[3] = (struct FoodItem)
    {4, "Cold Coffee", 70, 1};

    menu[4] = (struct FoodItem)
    {5, "Tea", 20, 1};



    do
    {
        printf("\n\n====================================\n");
        printf("       CANTEEN BILLING SYSTEM\n");
        printf("====================================\n");

        printf("1. Menu Management\n");

        printf("2. Order Food / Generate Bill\n");

        printf("3. Admin Panel\n");

        printf("4. Exit\n");

        printf("------------------------------------\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);



        switch(choice)
        {
            case 1:

                menuManagement();

                break;


            case 2:

                takeOrder();

                break;


            case 3:

                adminPanel();

                break;


            case 4:

                printf("\nExiting Canteen Billing System...\n");

                break;


            default:

                printf("\nInvalid choice!\n");
        }


    } while(choice != 4);


    return 0;
}