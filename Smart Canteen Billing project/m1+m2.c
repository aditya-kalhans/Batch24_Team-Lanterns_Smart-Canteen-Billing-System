#include <stdio.h>
#include <string.h>

// ==========================================
// STRUCTURE USED BY MENU AND BILLING
// ==========================================

struct FoodItem
{
    int id;
    char name[50];
    float price;
    int available;
};

struct FoodItem menu[100];
int itemCount = 5;


// ==========================================
// MEMBER 1 - MENU MANAGEMENT
// ==========================================

// Display menu
void displayMenu()
{
    printf("\n========== CANTEEN MENU ==========\n");
    printf("ID\tItem\t\tPrice\tStatus\n");
    printf("------------------------------------------\n");

    for(int i = 0; i < itemCount; i++)
    {
        printf("%d\t%-15s\t%.2f\t",
               menu[i].id,
               menu[i].name,
               menu[i].price);

        if(menu[i].available == 1)
            printf("Available\n");
        else
            printf("Unavailable\n");
    }
}


// Add new item
void addItem()
{
    printf("\nEnter item ID: ");
    scanf("%d", &menu[itemCount].id);

    printf("Enter item name: ");
    scanf(" %[^\n]", menu[itemCount].name);

    printf("Enter price: ");
    scanf("%f", &menu[itemCount].price);

    menu[itemCount].available = 1;

    itemCount++;

    printf("\nItem added successfully!\n");
}


// Update item price
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

            printf("Price updated successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Item not found!\n");
}


// Change availability
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
                menu[i].available = 0;
            else
                menu[i].available = 1;

            printf("Availability changed successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Item not found!\n");
}


// Remove item
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

            printf("Item removed successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Item not found!\n");
}


// Member 1 menu management screen
void menuManagement()
{
    int choice;

    do
    {
        printf("\n====== MENU MANAGEMENT ======\n");
        printf("1. Display Menu\n");
        printf("2. Add Item\n");
        printf("3. Update Item Price\n");
        printf("4. Change Availability\n");
        printf("5. Remove Item\n");
        printf("6. Back to Main Menu\n");

        printf("\nEnter your choice: ");
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
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);
}


// ==========================================
// MEMBER 2 - ORDER AND BILLING
// ==========================================

void takeOrder()
{
    int choice, quantity;
    int found;
    float total = 0;
    char more;

    displayMenu();

    do
    {
        found = 0;

        printf("\nEnter item ID: ");
        scanf("%d", &choice);

        // Search for item in Member 1's menu
        for(int i = 0; i < itemCount; i++)
        {
            if(menu[i].id == choice)
            {
                found = 1;

                // Check availability
                if(menu[i].available == 0)
                {
                    printf("Sorry! %s is currently unavailable.\n",
                           menu[i].name);
                    break;
                }

                printf("Enter quantity: ");
                scanf("%d", &quantity);

                if(quantity <= 0)
                {
                    printf("Invalid quantity!\n");
                    break;
                }

                float itemTotal = menu[i].price * quantity;

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
            printf("Invalid item ID!\n");
        }

        printf("\nDo you want to order something else? (y/n): ");
        scanf(" %c", &more);

    } while(more == 'y' || more == 'Y');


    // Final Bill
// Final Bill

printf("\n==================================\n");
printf("           FINAL BILL\n");
printf("==================================\n");

printf("Total Amount: Rs. %.2f\n", total);

// 5% discount if total is above Rs. 300
if(total > 300)
{
    float discount = total * 0.05;
    float finalAmount = total - discount;

    printf("Discount (5%%): Rs. %.2f\n", discount);
    printf("----------------------------------\n");
    printf("Final Amount: Rs. %.2f\n", finalAmount);
}
else
{
    printf("Final Amount: Rs. %.2f\n", total);
}

printf("==================================\n");
printf("       Thank you! Visit Again\n");
printf("==================================\n");
}


// ==========================================
// MAIN PROGRAM
// ==========================================

int main()
{
    int choice;

    // Default canteen menu
    menu[0] = (struct FoodItem){1, "Burger", 80, 1};
    menu[1] = (struct FoodItem){2, "Sandwich", 60, 1};
    menu[2] = (struct FoodItem){3, "Maggi", 50, 1};
    menu[3] = (struct FoodItem){4, "Cold Coffee", 70, 1};
    menu[4] = (struct FoodItem){5, "Tea", 20, 1};


    do
    {
        printf("\n\n==================================\n");
        printf("      CANTEEN BILLING SYSTEM\n");
        printf("==================================\n");

        printf("1. Menu Management\n");
        printf("2. Order Food / Generate Bill\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
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
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}