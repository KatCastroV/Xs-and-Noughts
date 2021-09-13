//
//  players.cpp
//  Grid Lines
//
//  Created by Katherine Castro on 4/6/21.
//

#include "players.hpp"


#include <string>
#include <iostream>


//Assigns and initial role of first or second player to the user
//and then assigns the other role the AI
bool Players::setRoles()
{
    //Menu menu;
    int attempts = 5;   //max number of attempts allowed
    bool reachedMax;

    do
    {
        std::cout << "Enter a 1 for first player or a 2 for second player: ";
        std::cin >> chosenRole;

        switch(chosenRole)
        {
            case firstPlayer:
                compRole = secondPlayer;
                currPlayer = chosenRole;      //first turn will prompt human
                humanSym = fPlayerSymbol;
                compSym = sPlayerSymbol;
                
                break;

            case secondPlayer:
                compRole = firstPlayer;
                currPlayer = compRole;   //first turn will prompt computer
                humanSym = sPlayerSymbol;
                compSym  = fPlayerSymbol;
                
                break;

            default:
                attempts--;
                std::cout << "Please enter one of the two options. " << attempts << " left.\n";

                if(attempts == 0)
                {
                    std::cout << "Redirecting you to main menu.\n";
                    reachedMax = true;
                    //menu.mainMenu();
                    //main::mainMenu();
                    return reachedMax;
                    
                }
                break;
        }
    } while (chosenRole != firstPlayer && chosenRole != secondPlayer && chosenRole != 0);
    
    
    reachedMax = false;     //returns false to menuOptions() so obj doesnt get deleted
    
    
    
    userName();         //prompts human to enter a username
    
    //Pass player info to Game constructor
    Players playerInfo(user, chosenRole, compRole, currPlayer, humanSym, compSym);
    
    return reachedMax;
}


//Prompts user to enter a name
void Players::userName()
{
    char name[10];      //char array holds username
    
    std::cout << "Enter a name: ";
    std::cin.get();
    std::cin.get(name, 10);

    for(int i=0; i < sizeof(name); i++)
    {
        user = user + name[i];
    }
    
    //std::cout << "Username is " << user << "\n";
    //Game g(human, user, playerSymbol);
    
}

/*Will be done in Game class
//change player roles (1st becomes 2nd and vice versa)
int Players::changeRoles()
{
    if(currentPlayer == human)
    {
        currentPlayer = computer;
    }
    else
    {
        currentPlayer = human;
    }

    return currentPlayer;
}
*/

/*Will be done in Game class
//Assigns roles and corresponding symbols to human and computer players
void Players::assignGameRoles()
{
    switch(human)
    {
        case firstPlayer:
            computer = secondPlayer;
            currentPlayer = firstPlayer;
            break;

        case secondPlayer:
            computer = firstPlayer;
            break;
    }
    
    //Game players(human, computer);
}
 */
