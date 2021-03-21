#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*salesperson struct declaration*/
struct Salesperson
{
  char* name;
  int* numCars;
  int* numMinivans;
  int* numUtilityVehicles;
};

/*function declarations*/
void menu(struct Salesperson *salespersons, int aa);
int decide();

/*function declarations for functions in menu*/
struct Salesperson  * addSales( struct Salesperson *salespersons, int index );
void display( int index, struct Salesperson salespersons[] );
void displayAllEmployees(int sizeOfArray, struct Salesperson salespersons[]);
void sortByName(int sizeOfArray, struct Salesperson salespersons[]);
void sortBySalesofVehicleType(int sizeOfArray, struct Salesperson salespersons[], int vehicleChoice);
void sortByTotalSales(int sizeOfArray, struct Salesperson salespersons[]);

/*function definitions*/
void menu(struct Salesperson salespersons[], int aa)
{
  int menuchoice;
  printf( "main menu : \n");
  printf("options: \n");
  printf("1. add a number of vehicle sales for a given salesperson\n");
  printf("2. Display the sales for a given employee\n");
  printf("3. Display all employees and their sales\n");
  printf("4. Sort by name\n");
  printf("5. Sort by sales of a certain type of vehicle\n"); 
  printf("6. Sort by total sales\n");
  printf("7. quit\n");
  scanf("%d", &menuchoice);
  switch(menuchoice) {
    //add sales for given salesperson
    case 1 :
      printf( "who would you like to add sales for? : ");
      for(int x = 0; x<aa; x++){
        printf("%d %s \n", x+1, salespersons[x].name);
      }
      int whichChoiceToAddSales;
      scanf("%d", &whichChoiceToAddSales);
      addSales(salespersons, whichChoiceToAddSales-1);
      menu(salespersons, aa);
      break;

    //see sales of given salesperson
    case 2 :
      printf("who would you like to see sales of : \n");
      for(int i = 0; i < aa; i++) {
        printf("%d %s\n", i, salespersons[i].name);
      }
      int s;
      scanf("%d", &s);
      display(s, salespersons);
      menu(salespersons, aa);

    //see sales of all salespersons
    case 3 :
        displayAllEmployees(aa, salespersons);
        menu(salespersons, aa);
        break;

    //sort salespersons by name
    case 4 :
        sortByName(aa, salespersons);
        menu(salespersons, aa);
        break;

    //sort salespersons by type of vehicle sales
    case 5 :
      printf("what type of vehicle would you like to sort by? : \n");
      printf("1. cars \n");
      printf("2. minivans \n");
      printf("3. sports utility vehicles \n");
      int vehicleType;
      scanf("%d", &vehicleType);
      sortBySalesofVehicleType(aa, salespersons, vehicleType);
      menu(salespersons, aa);
      break;

    //sort salespersons by total sales
    case 6 :
        sortByTotalSales(aa, salespersons);
        menu(salespersons, aa);
        break;

    //quit menu
    case 7 :
        printf("bye!\n" );
        break;
    
    //rerun menu if invalid option entered
    default :
        printf("disgusting. try again\n" );
        menu(salespersons, aa);
        break;
   }
}

//rerun/ask number of salespersons if number greater than 7 entered
int decide(){
  int numsalespersons;
  printf( "Enter the number of salespersons : ");
  scanf("%d", &numsalespersons);
  return numsalespersons;
}

struct Salesperson * addSales(struct Salesperson salespersons[], int index)
{
  int typeOfVehicleToAddSalesFor;
  // printf("who would you like to add sales for?");
  printf( "what type of vehicle would you like to add sales for? : \n");
  printf( "1. car \n");
  printf( "2. minivan \n");
  printf( "3. sport utility vehicle \n");
  scanf("%d", &typeOfVehicleToAddSalesFor);
  int numSalesC, numSalesM, numSalesS, tempSumC, tempSumM, tempSumS;
  switch(typeOfVehicleToAddSalesFor) {
    case 1 :
      printf( "how many sales would you like to add? : \n");
      scanf("%d", &numSalesC);
      *salespersons[index].numCars+=numSalesC;
      printf("%d", *salespersons[index].numCars);
      break;
    case 2 :
      printf( "how many sales would you like to add? : \n");
      scanf("%d", &numSalesM);
      *salespersons[index].numCars+=numSalesM;
      printf("%d", *salespersons[index].numMinivans);
      break;
    case 3 :
      printf( "how many sales would you like to add? : \n");
      scanf("%d", &numSalesS);
      *salespersons[index].numCars+=numSalesS;
      printf("%d", *salespersons[index].numUtilityVehicles);
      break;
  }
return salespersons;
}

void display(int index, struct Salesperson salespersons[])
{
  printf("name : %s\n", (char*)salespersons[index].name);
  printf("cars sold :  %d\n", *salespersons[index].numCars);
  printf("minivans sold : %d\n", *salespersons[index].numMinivans);
  printf("sports utility vehicles sold : %d\n", *salespersons[index].numUtilityVehicles);
}

void displayAllEmployees(int sizeOfArray, struct Salesperson salespersons[]){
    for(int b=0; b<sizeOfArray; b++){
      printf("name : %s\n", (char*)salespersons[b].name);
      printf("cars sold :  %d\n", *salespersons[b].numCars);
      printf("minivans sold : %d\n", *salespersons[b].numMinivans);
      printf("sports utility vehicles sold : %d\n", *salespersons[b].numUtilityVehicles);
    }  
  }

void sortByName(int sizeOfArray, struct Salesperson salespersons[]){
  struct Salesperson sortedNames[sizeOfArray];
  for(int x = 0; x < sizeOfArray; x++){
    sortedNames[x].name=malloc(sizeof(salespersons[x].name));
		strcpy((char*)sortedNames[x].name, (char*)salespersons[x].name);

    sortedNames[x].numCars = malloc(5*sizeof(salespersons[x].numCars));
    sortedNames[x].numCars=salespersons[x].numCars;

    sortedNames[x].numMinivans = malloc(5*sizeof(salespersons[x].numMinivans));
    sortedNames[x].numMinivans=salespersons[x].numMinivans;

    sortedNames[x].numUtilityVehicles = malloc(5*sizeof(salespersons[x].numUtilityVehicles));
    sortedNames[x].numUtilityVehicles=salespersons[x].numUtilityVehicles;  
     
	}

  char temp[256];
  for(int i = 0; i < sizeOfArray - 1; i++){
		for(int j = i+1; j < sizeOfArray; j++){
			if(strcmp(sortedNames[i].name, sortedNames[j].name) > 0){
				strcpy(temp, sortedNames[i].name);
				strcpy(sortedNames[i].name, sortedNames[j].name);
				strcpy(sortedNames[j].name, temp);
			}
		}
	}

	printf("Salespersons sorted by name :\n");
	for(int k = 0; k< sizeOfArray; k++){
    printf("name : %s\n", (char*)sortedNames[k].name);
    printf("cars sold :  %d\n", *sortedNames[k].numCars);
    printf("minivans sold : %d\n", *sortedNames[k].numMinivans);
    printf("sports utility vehicles sold : %d\n", *sortedNames[k].numUtilityVehicles);
  }

}

void sortBySalesofVehicleType(int sizeOfArray, struct Salesperson salespersons[], int vehicleChoice){
  struct Salesperson sortedTypeSale[sizeOfArray];
 for(int x = 0; x < sizeOfArray; x++){
    sortedTypeSale[x].name=malloc(sizeof(salespersons[x].name));
		strcpy((char*)sortedTypeSale[x].name, (char*)salespersons[x].name);

    sortedTypeSale[x].numCars = malloc(5*sizeof(salespersons[x].numCars));
    sortedTypeSale[x].numCars=salespersons[x].numCars;

    sortedTypeSale[x].numMinivans = malloc(5*sizeof(salespersons[x].numMinivans));
    sortedTypeSale[x].numMinivans=salespersons[x].numMinivans;

    sortedTypeSale[x].numUtilityVehicles = malloc(5*sizeof(salespersons[x].numUtilityVehicles));
    sortedTypeSale[x].numUtilityVehicles=salespersons[x].numUtilityVehicles;  
     
	}

  switch(vehicleChoice) {
    int temp;
      //cars
      case 1 :
        for(int i = 0; i < sizeOfArray - 1; i++){
          for(int j = i+1; j < sizeOfArray; j++){
            if (sortedTypeSale[i].numCars > sortedTypeSale[j].numCars)
            {
              temp = *sortedTypeSale[i].numCars;
              *sortedTypeSale[i].numCars = *sortedTypeSale[j].numCars;
              *sortedTypeSale[j].numCars = temp;
            }
          }
      }
      printf("Salespersons sorted by vehicletype :\n");
      for(int k = 0; k< sizeOfArray; k++){
        printf("name : %s\n", (char*)sortedTypeSale[k].name);
        printf("cars sold :  %d\n", *sortedTypeSale[k].numCars);
        printf("minivans sold : %d\n", *sortedTypeSale[k].numMinivans);
        printf("sports utility vehicles sold : %d\n", *sortedTypeSale[k].numUtilityVehicles);
      }
      break;
        
      //minivans
      case 2 :
        for(int i = 0; i < sizeOfArray - 1; i++){
          for(int j = i+1; j < sizeOfArray; j++){
            if (sortedTypeSale[i].numMinivans > sortedTypeSale[j].numMinivans)
            {
              temp = *sortedTypeSale[i].numMinivans;
              *sortedTypeSale[i].numMinivans = *sortedTypeSale[j].numMinivans;
              *sortedTypeSale[j].numMinivans = temp;
            }
          }
        }
       
        printf("Salespersons sorted by vehicletype :\n");
        for(int k = 0; k< sizeOfArray; k++){
          printf("name : %s\n", (char*)sortedTypeSale[k].name);
          printf("cars sold :  %d\n", *sortedTypeSale[k].numCars);
          printf("minivans sold : %d\n", *sortedTypeSale[k].numMinivans);
          printf("sports utility vehicles sold : %d\n", *sortedTypeSale[k].numUtilityVehicles);
        }
        break;
      
      //sports utility vehicles
      case 3 :
        for(int i = 0; i < sizeOfArray - 1; i++){
          for(int j = i+1; j < sizeOfArray; j++){
            if (sortedTypeSale[i].numUtilityVehicles > sortedTypeSale[j].numUtilityVehicles)
            {
              temp = *sortedTypeSale[i].numUtilityVehicles;
              *sortedTypeSale[i].numUtilityVehicles = *sortedTypeSale[j].numUtilityVehicles;
              *sortedTypeSale[j].numUtilityVehicles = temp;
            }
          }
        }
       
        printf("Salespersons sorted by vehicletype :\n");
        for(int k = 0; k< sizeOfArray; k++){
          printf("name : %s\n", (char*)sortedTypeSale[k].name);
          printf("cars sold :  %d\n", *sortedTypeSale[k].numCars);
          printf("minivans sold : %d\n", *sortedTypeSale[k].numMinivans);
          printf("sports utility vehicles sold : %d\n", *sortedTypeSale[k].numUtilityVehicles);
        }
        break;	
}
}

void sortByTotalSales(int sizeOfArray, struct Salesperson salespersons[]){
  int temp;
  struct Salesperson sortedTotalSale[sizeOfArray];
    for(int x = 0; x < sizeOfArray; x++){

      sortedTotalSale[x].name=malloc(sizeof(salespersons[x].name));
      strcpy((char*)sortedTotalSale[x].name, (char*)salespersons[x].name);

      int sum = *salespersons[x].numCars+*salespersons[x].numUtilityVehicles+*salespersons[x].numMinivans;

      sortedTotalSale[x].numCars = malloc(5*sizeof(sum));
      sortedTotalSale[x].numCars=&sum;

      sortedTotalSale[x].numMinivans = malloc(5*sizeof(sum));
      sortedTotalSale[x].numMinivans=&sum;

      sortedTotalSale[x].numUtilityVehicles = malloc(5*sizeof(sum)); 
      sortedTotalSale[x].numUtilityVehicles=&sum;
      
    }

    for(int i = 0; i < sizeOfArray - 1; i++){
      for(int j = i+1; j < sizeOfArray; j++){
        if (sortedTotalSale[i].numUtilityVehicles > sortedTotalSale[j].numUtilityVehicles)
        {
          temp = *sortedTotalSale[i].numUtilityVehicles;
          *sortedTotalSale[i].numUtilityVehicles = *sortedTotalSale[j].numUtilityVehicles;
          *sortedTotalSale[j].numUtilityVehicles = temp;
        }
      }
    }

    printf("Salespersons sorted by total sales :\n");
    for(int k = 0; k< sizeOfArray; k++){
      printf("name : %s\n", (char*)sortedTotalSale[k].name);
      printf("total sales :  %d\n", *sortedTotalSale[k].numCars);
    }
        
}

/*main function*/
int main(void) {  
  int howManySalespersons = decide();

  while(howManySalespersons>7){
    printf( "disgusting. Try again. : ");
    howManySalespersons = decide();
  }

  struct Salesperson salespersons[howManySalespersons];

  printf("\nLet's Initialize an array of size %d!!\n", howManySalespersons);
  struct Salesperson tempSale;
  for(int a=0; a<howManySalespersons; a++){
    char* name = malloc(sizeof(char)*(256));
    int carsSold=0;
    int minivansSold=0;
    int utilityVehiclesSold=0;
    
    printf("Enter the name of the salesperson at salespersons : \n");
    scanf("%s", name);
    tempSale.name = name;

    printf("Enter the number of cars sold : \n");
    scanf("%d", &carsSold);
    //you don't need to malloc for the integers
    //tempSale.numCars = malloc(5*sizeof(carsSold));
    tempSale.numCars= &carsSold;

    printf("Enter the number of minivans sold : \n");
    scanf("%d", &minivansSold);
    //tempSale.numMinivans = malloc(5*sizeof(minivansSold));
    tempSale.numMinivans= &minivansSold;

    printf("Enter the number of sports utility vehicles sold : \n");
    scanf("%d", &utilityVehiclesSold);
    //tempSale.numUtilityVehicles = malloc(5*sizeof(utilityVehiclesSold));
    tempSale.numUtilityVehicles= &utilityVehiclesSold;

    salespersons[a] = tempSale;
  }
  printf("name : %s\n", (char*)salespersons[0].name);
  printf("cars sold :  %d\n", *salespersons[0].numCars);
  printf("minivans sold : %d\n", *salespersons[0].numMinivans);
  printf("sports utility vehicles sold : %d\n", *salespersons[0].numUtilityVehicles);

   printf("name : %s\n", (char*)salespersons[1].name);
  printf("cars sold :  %d\n", *salespersons[1].numCars);
  printf("minivans sold : %d\n", *salespersons[1].numMinivans);
  printf("sports utility vehicles sold : %d\n", *salespersons[1].numUtilityVehicles);

  menu(salespersons, howManySalespersons); 
  for(int q=0;q<howManySalespersons; q++){
    free(&salespersons[q]);
  }

  return 0;
}