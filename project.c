//pharmacy database management system



/*   group members


1. 2624089042 Md Hasib Sikder 
2.2621565042 Ariful Huda Joy 
3.2121510643 Ziaul Hasan Khan Darpan 
4.2621337642 Md. Arafat Islam 

*/




#include<stdio.h>
#include<string.h>


int adminLogin();
int adminout();
void main_menu();
void loadcustomer();
void loadmedicine();
void loadsales();
int searchMedicine();
void search_customers();
void findMedicineAlternative();
void checkExpiryPriority();
void medicinemanagement();
void mostsellingmedicine();
void customermanagement();
void addcustomer();
void addmedicine();
void savemedicine();
void savecustomer();
void removecustomer();
void editcustomerinfo();
void saveSales();
void generateBill();
void generateSalesReport();
float calculateProfit();
void showOverallStatistics();
void salesmanagement();
void statisticsandreports();




struct expirydate{
 int day;
 int month;
 int year;
};


struct Sale {
    int saleId;
    int medicineId;
    int customerId;
    int quantity;
    float total;
};

struct Customer {
    int customerId;
    char name[50];
    char phone[20];
    float totalSpent;
};



struct Medicine {
    int id;
    char name[50];
    char category[50];
    float buyPrice;
    float sellPrice;
    int quantity;
    int amount_Sold;
    struct expirydate expiryDate;
};

int totalmedicines = 0;
int totalCustomers = 0;
int customerindex=0;
int totalSales = 0;
int loggedin = 0;

struct Medicine medicines[200];
struct Customer customers[200];
struct Sale sales[200];


int main(){

 loadcustomer();


 loadmedicine();


 loadsales();




printf("==================================\n");
printf("  PHARMACY DATABASE MANAGEMENT\n");
printf("==================================\n\n");


if ( adminLogin()){


main_menu();


}





    return 0;
}








int adminLogin(){

char username[50];
char password[50];

printf("Username : ");
gets(username);

printf("password :");
gets(password);

if(strcmp(username,"iamshamsul")==0 && strcmp(password,"world")==0){

loggedin=1;

printf("\n");
printf("logging successful...\n\n\n");

return 1 ;

}
    loggedin=0;

    printf("incorrect username or password \n");

    return 0;
}

int adminout(){

loggedin=0;

printf("logging out successful.... \n");

return 0;
}


void main_menu(){

    int choice;
    
    do{


printf("1. medicine management\n\n");
printf("2. sales management\n\n");
printf("3. customer management\n\n");
printf("4.statistics and reports\n\n");
printf("5. logout\n\n");
printf("6. exit\n\n");


printf(" choice :");
scanf("%d",&choice);


switch (choice){
      
    case 1:
              medicinemanagement();

              break;
    case 2:
              salesmanagement();

              break;

    case 3:
              customermanagement();

              break;

    case 4:
              statisticsandreports();

              break;
    case 5:
              adminout();
                break;

    case 6:
              printf("exiting the program...\n");
      
                break;

    default:
        printf("invalid choice\n");
        break;
}
}while(choice!=5 && choice!=6);

}




void medicinemanagement(){

    int choice;

    do{
        printf("1.add medicine\n");
        printf("2.search medicine\n");
        printf("3.fined medicine alternative\n");
        printf("4.check expiry priority\n");
        printf("5.Most selling medicine\n");
        printf("6.back to main menu\n");

        printf("choice :");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                addmedicine();
                break;

            case 2:
                searchMedicine();
                break;

            case 3:
                findMedicineAlternative();
                break;

            case 4:
                checkExpiryPriority();
                break;

            case 5:
                mostsellingmedicine();
                break;

            case 6:
                printf("Returning...\n");
                break;

            default:
                printf("invalid choice\n");
                break;
        }

    }while(choice != 6);
}


int searchMedicine(){

    int choice;
    int searchId;
    char searchName[50];
    char searchCategory[50];

    printf("\n===== SEARCH MEDICINE =====\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Category\n");

    printf("Choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nEnter ID: ");
        scanf("%d", &searchId);
    }
    else if(choice == 2)
    {
        printf("\nEnter name: ");
        scanf("%49s", searchName);
    }
    else if(choice == 3)
    {
        printf("\nEnter category: ");
        scanf("%49s", searchCategory);
    }
    else
    {
        printf("\nInvalid choice.\n");
        return -1;
    }

    for(int i = 0; i < totalmedicines; i++)
    {
        if((choice == 1 && medicines[i].id == searchId) ||
           (choice == 2 && strcmp(medicines[i].name, searchName) == 0) ||
           (choice == 3 && strcmp(medicines[i].category, searchCategory) == 0))
        {
            printf("\nMedicine found:\n");

            printf("ID : %d\n", medicines[i].id);
            printf("Name : %s\n", medicines[i].name);
            printf("Category : %s\n", medicines[i].category);
            printf("Buy Price : %.2f\n", medicines[i].buyPrice);
            printf("Sell Price : %.2f\n", medicines[i].sellPrice);
            printf("Quantity : %d\n", medicines[i].quantity);

            printf("Expiry Date : %d/%d/%d\n\n",
                   medicines[i].expiryDate.day,
                   medicines[i].expiryDate.month,
                   medicines[i].expiryDate.year);

            return i;
        }
    }

    printf("\n\nMedicine not found.\n\n");
    return -1;
}







void findMedicineAlternative(){


    int found =0;
    char searchcategory[50];

printf("Enter the category of the medicine :");

scanf("%49s",searchcategory);

 for (int i=0;i<totalmedicines;i++){


      if (strcmp(medicines[i].category,searchcategory)==0){


               found++;


      }

 }


printf("===============================");
printf("   %d results found\n\n",found);
printf("================================");



    for (int i=0;i<totalmedicines;i++){

      if (strcmp(medicines[i].category,searchcategory)==0){

       printf("id : %d\n", medicines[i].id);

            printf("Name : %s\n", medicines[i].name);

            printf("Buy Price : %.2f\n", medicines[i].buyPrice);

            printf("Sell Price : %.2f\n", medicines[i].sellPrice);

            printf("Quantity : %d\n", medicines[i].quantity);

            printf("Expiry Date : %d/%d/%d\n\n\n", medicines[i].expiryDate.day, medicines[i].expiryDate.month, medicines[i].expiryDate.year);

      }




    }

}




void checkExpiryPriority(){
    for(int i = 0; i < totalmedicines; i++){
        if(medicines[i].expiryDate.year < 2026 ||
             (medicines[i].expiryDate.year == 2026 && medicines[i].expiryDate.month < 8) ||
         (medicines[i].expiryDate.year == 2026 &&
             medicines[i].expiryDate.month == 8 && medicines[i].expiryDate.day < 19)){
            printf(" Medicine expiared ");
            printf("id : %d\n", medicines[i].id);
            printf("Name : %s\n", medicines[i].name);
            printf("Category : %s\n", medicines[i].category);
            printf("Expiry Date : %d/%d/%d\n\n\n", medicines[i].expiryDate.day, medicines[i].expiryDate.month, medicines[i].expiryDate.year);
        }
        else if((medicines[i].expiryDate.year==2026)&&(medicines[i].expiryDate.month==8)){
            printf("Priority : High (about to expire )");
            printf("id : %d\n", medicines[i].id);
            printf("Name : %s\n", medicines[i].name);
            printf("Category : %s\n", medicines[i].category);
            printf("Expiry Date : %d/%d/%d\n\n\n", medicines[i].expiryDate.day, medicines[i].expiryDate.month, medicines[i].expiryDate.year);
        }
        else if(medicines[i].expiryDate.year == 2026){
            printf("Priority : Moderate");
            printf("id : %d\n", medicines[i].id);
            printf("Name : %s\n", medicines[i].name);
            printf("Category : %s\n", medicines[i].category);
            printf("Expiry Date : %d/%d/%d\n\n\n", medicines[i].expiryDate.day, medicines[i].expiryDate.month, medicines[i].expiryDate.year);
        }
        else if(medicines[i].expiryDate.year == 2027){
            printf("Priority : Medium");
            printf("id : %d\n", medicines[i].id);
            printf("Name : %s\n", medicines[i].name);
            printf("Category : %s\n", medicines[i].category);
            printf("Expiry Date : %d/%d/%d\n\n\n", medicines[i].expiryDate.day, medicines[i].expiryDate.month, medicines[i].expiryDate.year);
        }
        else{
            printf("Priority : Low");
            printf("id : %d\n", medicines[i].id);
            printf("Name : %s\n", medicines[i].name);
            printf("Category : %s\n", medicines[i].category);
            printf("Expiry Date : %d/%d/%d\n\n\n", medicines[i].expiryDate.day, medicines[i].expiryDate.month, medicines[i].expiryDate.year);
        }
    }
}

void customermanagement(){

    int choice;

    do
    {
        printf("\n===== Customer Management =====\n");
        printf("1. Add customer\n");
         printf("2. Remove customer\n");
        printf("3. Search customer\n");
        printf("4. Edit customer info\n");
        printf("5. Back to Main Menu\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addcustomer();
                break;

            case 2:
                removecustomer();
                break;

            case 3:
                search_customers();
                break;

            case 4:
                editcustomerinfo();
                break;

            case 5:
                printf("Returning...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);
}

void addcustomer(){

    if(totalCustomers >= 200){
        printf("Customer storage is full.\n");
        return;
    }

    customerindex = totalCustomers;

    printf("Customer ID: ");
    scanf("%d", &customers[customerindex].customerId);

    // Check duplicate Customer ID
    for(int i = 0; i < totalCustomers; i++){
        if(customers[i].customerId == customers[customerindex].customerId){
            printf("A customer with that ID already exists.\n");
            return;
        }
    }

    printf("Name: ");
    scanf("%49s", customers[customerindex].name);

    printf("Phone: ");
    scanf("%19s", customers[customerindex].phone);

    customers[customerindex].totalSpent = 0.0;

    totalCustomers++;

    savecustomer();

    printf("Customer saved successfully.\n");
}



void addmedicine(){

    if(totalmedicines >= 200)
    {
        printf("Medicine storage is full.\n");
        return;
    }

    printf("Medicine name :");
    scanf("%49s", medicines[totalmedicines].name);

    printf("Medicine id :");
    scanf("%d", &medicines[totalmedicines].id);

    for(int i = 0; i < totalmedicines; i++){
        if(medicines[i].id == medicines[totalmedicines].id){
            printf("A medicine with that ID already exists.\n");
            return;
        }
    }

    printf("Medicine category :");
    scanf("%49s", medicines[totalmedicines].category);

    printf("Medicine Buy price :");
    scanf("%f", &medicines[totalmedicines].buyPrice);

    printf("Medicine sell price :");
    scanf("%f", &medicines[totalmedicines].sellPrice);

    printf("Medicine quantity :");
    scanf("%d", &medicines[totalmedicines].quantity);

    printf("Amount of medicine sold :");
    scanf("%d", &medicines[totalmedicines].amount_Sold);

    printf("Expiry day :");
    scanf("%d", &medicines[totalmedicines].expiryDate.day);

    printf("Expiry month :");
    scanf("%d", &medicines[totalmedicines].expiryDate.month);

    printf("Expiry year :");
    scanf("%d", &medicines[totalmedicines].expiryDate.year);

    totalmedicines++;

    savemedicine();

    printf("Medicine added successfully.\n\n");
}

void search_customers(){
    int id,found=0 ;
    printf("Enter customer id :");
    scanf("%d",&id);
    

    for(int i =0;i<totalCustomers;i++){


  if(customers[i].customerId==id){
 printf("customer name : %s\n" ,customers[i].name);
 printf(" customer ID  : %d\n" ,customers[i].customerId);
 printf("customer phone number : %s\n" ,customers[i].phone);
  found=1;
  break;
  }

    }
if(found==0){

    printf("customer not found");
}

}

void savecustomer(){
   FILE *customerfile = fopen("customer.txt","w");

if(customerfile == NULL)
{
    printf("The file is not opened properly\n");
    return;
}

for(int i =0;i<totalCustomers;i++){

 fprintf(customerfile, "%d %s %s %.2f\n", customers[i].customerId, customers[i].name, customers[i].phone, customers[i].totalSpent);

}

fclose(customerfile);

}



void saveSales(){
  FILE *salesfile=fopen("sales.txt","w");


if(salesfile == NULL)
{
    printf("The file is not opened properly\n");
    return;
}

  for(int i=0;i<totalSales;i++){

  fprintf(salesfile,"%d %d %d %d %.2f\n",sales[i].saleId, sales[i].medicineId,  sales[i].customerId, sales[i].quantity, sales[i].total);

}
fclose(salesfile);

}


void savemedicine(){
    FILE *medicinefile = fopen("medicine.txt","w");

   if(medicinefile == NULL)
{
    printf("The file is not opened properly\n");
    return;
}


for(int i =0;i<totalmedicines;i++){

    fprintf(medicinefile, "%d %s %s %.2f %.2f %d %d %d %d %d\n",  medicines[i].id, 
         medicines[i].name,
          medicines[i].category,
          medicines[i].buyPrice, 
           medicines[i].sellPrice,
           medicines[i].quantity,
            medicines[i].amount_Sold, 
           medicines[i].expiryDate.day, 
           medicines[i].expiryDate.month, 
           medicines[i].expiryDate.year);

}


fclose(medicinefile);

}


void generateBill(){


     int customerid;
    int medicineId;
    int quantity;

    int medicineIndex = -1;
    int customernumber = -1;

    float total;

     if (totalSales >= 200)
    {
        printf("Sales storage is full. Cannot process any more sales.\n");
        return;
    }

    printf("\n===== GENERATE BILL =====\n");

    printf("Customer ID: ");
    scanf("%d", &customerid);

    printf("Medicine ID: ");
    scanf("%d", &medicineId);

    printf("Quantity: ");
    scanf("%d", &quantity);

     for (int i = 0; i < totalmedicines; i++)
    {
        if (medicines[i].id == medicineId)
        {
            medicineIndex = i;
            break;
        }
    }

    if (medicineIndex == -1)
    {
        printf("Medicine not found.\n");
        return;
    }
if (medicines[medicineIndex].quantity < quantity)
    {
        printf("Not enough stock.\n");
        return;
    }



for (int i = 0; i < totalCustomers; i++)
    {
        if (customers[i].customerId == customerid)
        {
            customernumber = i;
            break;
        }
    }


if (customernumber == -1)
    {
        if (totalCustomers >= 200)
        {
            printf("Customer storage is full.\n");
            return;
        }

        customernumber = totalCustomers;

        customers[customernumber].customerId= customerid;

        printf("Enter customer name: ");
        scanf("%49s", customers[customernumber].name);

        printf("Enter customer phone number: ");
    scanf("%19s", customers[customernumber].phone);

        customers[customernumber].totalSpent = 0;

        totalCustomers++;
    }

 total = medicines[medicineIndex].sellPrice * quantity;

    printf("\n========== BILL ==========\n");

    printf("Customer: %s\n",
           customers[customernumber].name);

    printf("Medicine: %s\n",
           medicines[medicineIndex].name);

    printf("Quantity: %d\n", quantity);

    printf("Price: %.2f\n",medicines[medicineIndex].sellPrice);

    printf("--------------------------\n");

    printf("TOTAL: %.2f\n", total);

    printf("==========================\n");


medicines[medicineIndex].quantity -= quantity;

medicines[medicineIndex].amount_Sold += quantity;


customers[customernumber].totalSpent += total;

  
     sales[totalSales].saleId = totalSales + 1;
sales[totalSales].medicineId = medicineId;
sales[totalSales].customerId = customerid;
sales[totalSales].quantity = quantity;
sales[totalSales].total = total;

totalSales++;
    
  savemedicine();
   savecustomer();
    saveSales();

    printf("\nSale recorded successfully!\n");
}



void generateSalesReport(){
     
float total =0.0;

 for (int i = 0; i < totalSales; i++){

 total += sales[i].total;
    }



    printf("total sales : %.2f",total);

 
    
    for (int i = 0; i < totalSales; i++)
    {
        printf("\nSale %d\n", i + 1);

        printf("Medicine ID: %d\n",
               sales[i].medicineId);

        printf("Customer ID: %d\n",
               sales[i].customerId);

        printf("Quantity: %d\n",
               sales[i].quantity);

        printf("Total: %.2f\n",
               sales[i].total);

        }


}
 
float calculateProfit(){

  float profit =0.0;

  for (int i=0; i<totalmedicines;i++){
 

profit+=((medicines[i].sellPrice - medicines[i].buyPrice)* medicines[i].amount_Sold);


  
  }
    

return profit;
}


void showOverallStatistics(){

float profit = calculateProfit();

    printf("Total medicines : %d\n", totalmedicines);
    printf("Total customers : %d\n", totalCustomers);
    printf("Total sales : %d\n", totalSales);
    printf("Total profit : %.2f\n", profit);
}






void mostsellingmedicine(){

   int index =0;

   if(totalmedicines == 0)
{
    printf("No medicines available.\n");
    return;
}

for(int i=0;i<totalmedicines;i++){

   if(medicines[i].amount_Sold > medicines[index].amount_Sold){


         index=i;


}

}


 printf("Medicine: %s\n",
           medicines[index].name);

    printf("Sold Quantity: %d\n",
           medicines[index].amount_Sold);



}


void removecustomer(){

     int id ;
     int found=0;
       printf("Enter customer id :");
       scanf("%d",&id);

   for(int i=0;i<totalCustomers;i++){

  if (customers[i].customerId==id){


   for(int j=i;j<totalCustomers-1;j++){

   
   customers[j] = customers[j + 1];



   }
   totalCustomers--;
   found=1;
    savecustomer();

 printf("Customer removed successfully.\n");
    break;

  }


   }
if(found==0){

printf("customer not found\n");

}


}


void editcustomerinfo(){
     char name[50];
       char  phone[50];
  int id;


  printf("Enter customer id :");
        scanf("%d",&id);
       printf("Enter customer name :");
        scanf("%49s",name);

printf("Enter customer phone number :");
        scanf("%19s",phone);

        for (int i =0;i<totalCustomers;i++){

         if(customers[i].customerId==id){
         strcpy(customers[i].name,name);
         strcpy(customers[i].phone,phone);
        
         }



        }

savecustomer();

}



void loadcustomer(){

    FILE *customerfile = fopen("customer.txt", "r");

    if(customerfile == NULL){
        return;
    }

    totalCustomers = 0;

    while(totalCustomers < 200 &&
          fscanf(customerfile, "%d %49s %19s %f",
                 &customers[totalCustomers].customerId,
                 customers[totalCustomers].name,
                 customers[totalCustomers].phone,
                 &customers[totalCustomers].totalSpent) == 4)
    {
        totalCustomers++;
    }

    fclose(customerfile);
}

void loadmedicine(){

   

   FILE *medicinefile =fopen("medicine.txt","r");

 if(medicinefile == NULL)
{
    return;
}

  totalmedicines = 0;

    while(totalmedicines < 200 &&
      fscanf(medicinefile, "%d %s %s %f %f %d %d %d %d %d",
      &medicines[totalmedicines].id,
      medicines[totalmedicines].name,
      medicines[totalmedicines].category,
      &medicines[totalmedicines].buyPrice,
      &medicines[totalmedicines].sellPrice,
      &medicines[totalmedicines].quantity,
      &medicines[totalmedicines].amount_Sold,
      &medicines[totalmedicines].expiryDate.day,
      &medicines[totalmedicines].expiryDate.month,
      &medicines[totalmedicines].expiryDate.year) == 10)
{
    totalmedicines++;
}

    fclose(medicinefile);
}


void loadsales(){

    FILE *salesfile = fopen("sales.txt", "r");

    if(salesfile == NULL){
        return;
    }

    totalSales = 0;

    while(totalSales < 200 &&
          fscanf(salesfile, "%d %d %d %d %f",
                 &sales[totalSales].saleId,
                 &sales[totalSales].medicineId,
                 &sales[totalSales].customerId,
                 &sales[totalSales].quantity,
                 &sales[totalSales].total) == 5)
    {
        totalSales++;
    }

    fclose(salesfile);
}

void salesmanagement()
{
    int choice;

    do
    {
        printf("\n===== Sales Management =====\n");
        printf("1. Generate Bill\n");
        printf("2. Sales Report\n");
        printf("3. Back to Main Menu\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                generateBill();
                break;

            case 2:
                generateSalesReport();
                break;

            case 3:
                printf("Returning...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3);
}


void statisticsandreports()
{
    int choice;

    do
    {
        printf("\n===== Statistics and Reports =====\n");
        printf("1. Sales Report\n");
        printf("2. Calculate Profit\n");
        printf("3. Overall Statistics\n");
        printf("4. Back to Main Menu\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                generateSalesReport();
                break;

            case 2:
                printf("Total profit: %.2f\n", calculateProfit());
                break;

            case 3:
                showOverallStatistics();
                break;

            case 4:
                printf("Returning...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);
}