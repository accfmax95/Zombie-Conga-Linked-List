/*
  Author: Maxwell Berry
  Date: July 6, 2021
  Description: This is the main class, which compiles and runs the main prompts within the Zombie conga game. 
               The class calls many of the functions within th other functions to achieve its desired purpose.
*/

#include <iostream>
#include "berry_Zombie.h"
#include "berry_max_list.h"

using namespace std;

 int main() {
    
    LinkedList<Zombie> linkedList; // Linked list object
    Zombie randZombie; // Zombie object to generate random zombie element
    int numRounds = 0, initialRounds = 0, i, randValue, randIndex, index; // Series of ints, used variously throughout the main
    bool partyStatus = true, prompt = false; // Series of booleans used for defense prompts and loop cancelation
    char colors[] = {'R', 'Y', 'G', 'B', 'M', 'C'}; // Available colors for the zombies

    do { // Loop for defense prompts
      
      cout << "Enter the number of rounds you want to generate: ";
      cin >> numRounds;

      if (numRounds > 0) {

        prompt = true;
      } else if (numRounds < 1) {

        cout << "\nError // How do you expect to party that many times?\n";
      }

    } while (prompt == false);

    srand(time(0)); // Allows the random function to be unique each time
    do { // Loop that continues while the party is active

      for (i = initialRounds; i < numRounds; i++) { // Produces the appropriate number of rounds

        int numActions = (rand() % 4) + 2; // Random number between 2 and 5 (generates the step)

        if (i == 0) { // Generates the brain and rainbow brain case for round 1 only (does not occur if user chooses to add more rounds)         
          
          randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
          randZombie = Zombie(colors[randValue]); 

          linkedList.AddToFront(randZombie);
          for (int j = 0; j < 6; j++) {
            if (j == randValue) { // Skips the randomly generated color

            } else {

                linkedList.AddToEnd(Zombie(colors[j]));
            }
          }

          for (int j = 0; j < numActions; j++) { // Repeats based on the number of randomly generated numbers betwwen 2 and 5
            
  
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.AddToFront(randZombie);
            linkedList.AddToEnd(randZombie);

            index = linkedList.Length() / 2;
            linkedList.AddAtIndex(randZombie, index);
          }
        }

        if (((i + 1) % 5) == 0) { // Every 5 rounds the program removes the head and tail

          if (linkedList.Length() < 3) { // If there are only 2 elements in the linked list

            linkedList.Empty(); // Empties it out
          } else {

            linkedList.RemoveFromFront();
            linkedList.RemoveFromEnd();
          }
        }


        cout << "\nRound: " << (i + 1) << endl;
        cout << "The Zombie Party keeps on groaning!" << endl;
        cout << "Size: " << linkedList.Length() << " :: ";
        linkedList.PrintList();
        cout << endl;

        if (linkedList.Length() < 1) { // The party stops if there are no more zombies

          cout << "Everyone has gone home! Party is over." << endl;
          return 0;
        }

        int randAction = rand() % 7; // Generates a random action (0 - 6)
        switch (randAction) { // Goes between each case

          case 0: // This zombie becomes the first Zombie in the conga line
            
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.AddToFront(randZombie);
            cout << randZombie << " zombie jumps in front of the line! (ENGINE)" << endl;
            break;

          case 1: // This zombie becomes the last zombie in the conga line


            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.AddToEnd(randZombie);
            cout << randZombie << " zombie pulls up the rear! (CABOOSE)" << endl;
            break;

          case 2: // This zombie joins the conga line at position X where X <= length of the linked list
            
            randIndex = rand() % linkedList.Length(); // Generates a random number between 0 and the lenght of the list
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 
            
            linkedList.AddAtIndex(randZombie, randIndex);
            cout << randZombie << " zombie joined the party and is now number " << randIndex + 1 << " in line! (JUMP IN THE LINE)" << endl;
            break;

          case 3: // Remove all matching zombies from the linked list
            
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.RemoveAllOf(randZombie);
            cout << randZombie << " zombie and their friends broke the rules! (EVERYONE OUT)" << endl;
            break;

          case 4: // Remove the first matching zombie from the linked list
            
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.RemoveTheFirst(randZombie);
            cout << randZombie << " zombie needs to go! (YOU'RE DONE)" << endl;
            break;

          case 5: // Generate two more matching Zombies and add one to the front, one to the end and one to the middle.
            
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.AddToFront(randZombie);
            linkedList.AddToEnd(randZombie);

            index = linkedList.Length() / 2; // Finds the middle
            linkedList.AddAtIndex(randZombie, index);
            cout << randZombie << " zombie brings its friends to the party! (BRAINS)" << endl;
            break;

          case 6: // Add this zombie to the front, then add one of each zombie color to the end of the conga line.
            
            randValue = rand() % 6; // Generates a random zombie (index 0 - 5)
            randZombie = Zombie(colors[randValue]); 

            linkedList.AddToFront(randZombie);
            for (int j = 0; j < 6; j++) { // Loops through each color
              
              if (j == randValue) {

              } else { // Only selects colors not chosen by rand()

                linkedList.AddToEnd(Zombie(colors[j]));
              }
            }

            cout << randZombie << " zombie brought a whole party itself! (RAINBOW BRAINS)" << endl;
            break;

        } 

        cout << "The conga line is now:" << endl;
        cout << "Size: " << linkedList.Length() << " :: ";
        linkedList.PrintList();
        cout << endl << "*******************\n" << endl;
      
        if (linkedList.Length() < 1) { // The party stops if there are no more zombies

          cout << "Everyone has gone home! Party is over." << endl;
          return 0;
        }

      }

      bool check = false;
      do { // Prompts to ask the user to add more rounds
        
        char response;
        int newRounds;
        cout << "Should the party keep on going? (y/n): ";
        cin >> response;

        if (response == 'y') {

          prompt = false;
          do {
            
            cout << "Enter the number of rounds you want to add: ";
            cin >> newRounds;

            if (newRounds > 0) {

              prompt = true;
            } else if (newRounds < 1) { // To ensure rounds are greater than 0

              cout << "\nError // How do you expect to party that many times?\n";
            }

          } while (prompt == false);

          initialRounds = numRounds; // Recalculates variables so the for loop works properly
          numRounds += newRounds;
          partyStatus = true;
          check = true;
        } else if (response == 'n') {

          partyStatus = false;
          check = true;
        } else { // Defense prompt
          
          cout << "\nError // Enter 'y' or 'n'\n"; 
          check = false;
        }

      } while (check == false); 


    } while (partyStatus == true);

    linkedList.Empty(); // Empties the linked list when the user chooses to stop playing
    return 0;
}