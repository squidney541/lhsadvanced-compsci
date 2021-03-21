#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Participants in an activity of Laser Tag can be represented by the C struct Participant:
struct Participant
{
  char* name;
  int laserPower, shieldStrength;

  // int* laserPower;
  // int* shieldStrength;
  // int* shotAccuracy;
};

void printPlayer( struct Participant *player );
void activity( struct Participant *player1, struct Participant *player2);

int main() {
  struct Participant player1;
  struct Participant player2;

  //player 1
  player1.name = (char*)malloc(5*sizeof("Susan"));
  strcpy( (char*)player1.name, "Susan");
  player1.shieldStrength = 10;
  player1.laserPower = 1;
 
  //player 2
  player2.name = (char*)malloc(5*sizeof("Janet"));
  strcpy( (char*)player2.name, "Janet");
  player2.shieldStrength = 10;
  player2.laserPower = 1;
  
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
int flip( )
{
    int i = rand() % 2;
      if (i == 0){
            return 0;
      }
      else{
            return 1; 
      }
}

//run the activity
void activity( struct Participant *player1, struct Participant *player2) {
  do{
      //susan's turn
      if (flip() == 1){
        if(player2->shieldStrength-player1->laserPower<=0){
          printf( "Winner : %s\n", (char*)player1->name);
          break;
        }
        else{player2->shieldStrength = player2->shieldStrength-player1->laserPower;
        }
      }

      //janet's turn
      if (flip() == 0){
        if(player1->shieldStrength-player2->laserPower<=0){
          printf( "Winner : %s\n", (char*)player2->name);
          break;
        }
        else{
          player1->shieldStrength = player1->shieldStrength-player2->laserPower;
        }
      }
  }while(player1->shieldStrength > 0 && player2->shieldStrength > 0);
}

//print player info
void printPlayer( struct Participant *player) {
  printf( "Player name : %s\n", (char*)player->name);
  printf( "Player shieldStrength : %d\n", player->shieldStrength);
  printf( "Player laserPower : %d\n", player->laserPower);
}
