#include <curses.h>
#include <iostream>
#include "players.hpp"
#include "grid.hpp"
//#include "menu.hpp"
#include "game.hpp"



//Function prototypes
void mainMenu();
void menuOptions();
void learn();
void endGame();


int main(int argc, const char * argv[])
{
    //print main menu
    mainMenu();

    return 0;
}


//Prints main menu options and prompts for a selection
void mainMenu()
{
        std::cout << "\n";
        std::cout << "\t\t     =======================     \n";
        std::cout << "\t\t     |         MENU        |     \n";
        std::cout << "\t\t     =======================     \n";
        std::cout << "\t\t       1. Play\n";
        std::cout << "\t\t       2. Learn to play\n";
        std::cout << "\t\t       3. Quit Game\n\n";
        std::cout << "\t\t       Make a selection: ";
        
    menuOptions();
}



//Menu options actions
void menuOptions()
{
    const int PLAY = 1;
    const int LEARN = 2;
    const int QUIT = 3;
    bool valid;             //used to exit do-while loop
    int selection;          //holds menu option entered
    int attempts = 5;       //max number of attempts allowed
    bool restart;
    //Players role;         //assigns player roles, grid size, and starts game
    //Grid size;
    //Game game;
    
    std::cin >> selection;

    do
    {
        switch(selection)
        {
            case PLAY:
            {           //curly brackets needed due to scope of initialized variables
                valid = true;
                
                //set player roles
                //Players *player = new Players();
                //restart = player->setRoles();
                
                Players player;
                restart = player.setRoles();
                
                if(restart == true)
                {
                    //delete player;      //delete instance so it can be reinstantiated
                    menuOptions();      //reprint menu options
                }
                
                //choose size of grid
                Grid *grid = new Grid();
                restart = grid->pickGrid();     //from Grid subclass
                
                if(restart == true)
                {
                    delete grid;
                    menuOptions();
                }
                
                //Start game
                Game *game = new Game();
                restart = game->play();       //from Game class
                
                if(restart == true)
                {
                    delete game;
                    menuOptions();
                }
                
                //delete dynamically created instances
                //delete player;
                delete grid;
                delete game;
                endGame();
                break;
            }
            case LEARN:
                valid = true;
                learn();
                break;
                
            case QUIT:
                valid = true;
                endGame();
                break;
                
            default:
                valid = false;
                attempts--;     //counts down from 5
                std::cout  << "\n*Invalid selection. Please try again.*\n";
                std::cout << "Attempts remaining: " << attempts << "\n";

                //maximum of 5 attempts in a row before game exits
                if(attempts == 0)
                {
                    endGame();  //exits out of program
                }
                else{
                    mainMenu(); //returns to menu for list of options
                }
                
        }
    }while(valid == false);
}

//Prints rules of the game and redirects user to main menu
void learn()
{
    std::cout << "\n";
    
    //Rules heading
    std::cout << "----------------------------------------------------------------------------------------\n";
    std::cout << "                                  ******************\n";
    std::cout << "                                  *      Rules     *\n";
    std::cout << "                                  ******************\n\n";
    
    //Generate example grid
    //generateGrid();
    
    //Game Rules
    std::cout << "- Get the same symbols in a row vertically, horizontally, or across on the chosen grid.\n";
    std::cout << "- First player gets Xs and second player gets Os.\n";
    std::cout << "- You can play as first or second player.\n";
    std::cout << "- Each grid location has a row letter (A, B, C, etc) and a column number (1, 2, 3, etc) assigned to it.\n";
    std::cout << "- To enter a move, type the row letter and column number together as follows:\n";
    std::cout << "      A1, A2, A3, B1, B2, B3, C1, C2, or C3\n";
    std::cout << "              Then, press Enter.\n";
    std::cout << "- Whoever gets three of their symbols in a row wins!\n\n";
    std::cout << "                      ***To return to main menu press Enter***";
    
    //Two ignore statements needed because you hit enter once to select menu option 2
    //A single one does not work
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout << "----------------------------------------------------------------------------------------\n";
    system("clear");
    //Return to main menu
    mainMenu();
}


//Ends the game and exits out of program
void endGame()
{
    std::cout << "\n\tThanks for playing. Goodbye!\n";
    exit(EXIT_SUCCESS);
}
