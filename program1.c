#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Participants in an activity of Laser Tag can be represented by the C struct Participant:
struct Participant
{
  char* name;
  int* shieldStrength;
  int* laserPower;
  int* shotAccuracy;
};

void printPlayer( struct Participant *player );
void activity( struct Participant *player1, struct Participant *player2);
int flip(int shot);

int main() {
  struct Participant player1;
  struct Participant player2;
  srand(time(0));

  //player 1
    char str0[100];
    int i0;
    int j0;
    printf( "Enter the name of player 1 : ");
    scanf("%s", str0);
    player1.name = malloc(sizeof(str0));
    strcpy( (char*)player1.name, str0);
    printf( "Enter the shield strength of p1 : ");
    scanf("%d", &i0);
    player1.shieldStrength = malloc(5*sizeof(i0));
    player1.shieldStrength=&i0;
    printf( "Enter the laser power of p1 : ");
    scanf("%d", &j0);
    player1.laserPower = malloc(5*sizeof(j0));
    player1.laserPower = &j0;

    int r0 = (rand() % 
    (60 - 40 + 1)) + 40; 
    player1.shotAccuracy = malloc(5*sizeof(r0));
    player1.shotAccuracy=&r0;

  //player 2
    char str[100];
    int i;
    int j;
    printf( "Enter the name of player 2 : ");
    scanf("%s", str);
    player2.name = malloc(sizeof(str));
    strcpy( (char*)player2.name, str);
    printf( "Enter the shield strength of p2 : ");
    scanf("%d", &i);
    player2.shieldStrength = malloc(5*sizeof(i));
    player2.shieldStrength=&i;
    printf( "Enter the laser power of p1 : ");
    scanf("%d", &j);
    player2.laserPower = malloc(5*sizeof(j));
    player2.laserPower = &j;
    
    int r = (rand() % 
    (60 - 40 + 1)) + 40; 
    player2.shotAccuracy = malloc(5*sizeof(r));
    player2.shotAccuracy=&r;

  /* print player1 info */
  printPlayer( &player1 );

  /* print player2 info */
  printPlayer( &player2 );

  srand(time(0));

  /* activity */
  activity(&player1, &player2);
  return 0;

}  

//pick if a player is gotten
int flip(int s)
{
  int num = (rand() % 
  (100 - 1 + 1)) + 1; 
  if(num<=s){
    return 1;
  }
  else{
    return 0;
  }
}

//run the activity
void activity( struct Participant *player1, struct Participant *player2) {
  do{
      //player 1's turn
      if (flip(*player1->shotAccuracy) == 1){
        *player2->shieldStrength = *player2->shieldStrength-*player1->laserPower;
        if((*player2->shieldStrength-*player1->laserPower)<=0){
          printf( "Winner : %s\n", (char*)player1->name);
          break;
        }
       
      }

      //player 2's turn
      if (flip(*player2->shotAccuracy) == 1){
      *player1->shieldStrength = *player1->shieldStrength-*player2->laserPower;
        if(*player1->shieldStrength-*player2->laserPower<=0){
          printf( "Winner : %s\n", (char*)player2->name);
          break;
        }
       
      }
  }while(*player1->shieldStrength > 0 && *player2->shieldStrength > 0);
}

//print player info
void printPlayer( struct Participant *player) {
  printf( "Player name : %s\n", (char*)player->name);
  printf( "Player shieldStrength : %d\n", *player->shieldStrength);
  printf( "Player laserPower : %d\n", *player->laserPower);
  printf( "Player shotAccuracy : %d\n", *player->shotAccuracy);
}
