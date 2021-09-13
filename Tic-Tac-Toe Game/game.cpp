//
//  game.cpp
//  Grid Lines
//
//  Created by Katherine Castro on 4/6/21.

#include "game.hpp"
//#include "menu.hpp"
#include "players.hpp"
#include "grid.hpp"


//Game loop
bool Game::play()
{
    bool forceRestart = false;
    
    setGrid();
    printGameGrid();
    
    while(turnCount != maxMoves || gameWon != true || failedAttempts != true)
    {
        std::cout << "Entered game loop!\n";
        //Calculate current turn
        turnCount++;
        
        //Decide who's turn it is and assign appropriate symbol
        if(turnCount != 1)
        {
            switchPlayers();
            //symbol = assignSymbol();
        }
        
        //Current player enters move
        logMoves();
        
        //Determines if game will continue or quit due to max failed attempts reached
        if(failedAttempts == true)
        {
            forceRestart = true;
        }
        else
        {
            //Move is added to grid
            printGameGrid();
            
            //Check to see if game has been won
            //If game has been won, break out of while loop
            gameWon = checkWin();
            
            //Quit Game or Play Again
            //endGame();
        }
    }
    
    return forceRestart;    //used to determine if game will restart from menu
}

//switches players after each turn
void Game::switchPlayers()
{
    if(currentPlayer == human)
    {
        currentPlayer = computer;
        symbol = computerSymbol;
    }
    else
    {
        currentPlayer = human;
        symbol = humanSymbol;
    }
}


void Game::setGrid()
{
    for(int i = 0; i < vectorSize; i++)
    {
        movesLeft[i];
    }
}

void Game::printGameGrid()
{
    int count;
    
    switch(sizeOfGrid)
    {
        case 3:
            //Prints 3x3 grid
            for(int i = 0; i < mRows - (2 * sRows); i++)
            {
                count = 0;
                for(int j = 0; j < mColumns - ( 2 * sColumns) ; j++)
                {
                    count++;
                    
                    if(i == r && j == c)
                    {
                        grid[r][c] = symbol;
                        std::cout << grid[r][c];
                    }
                    else
                    {
                        std::cout << grid[i][j];
                    }
                    
                    if(count == mColumns - (2*sColumns))
                        std::cout << "\n";
                }
                std::cout << "\n";
            }
            
            break;
            
        case 6:
            //Prints 6x6 grid
            for(int i = 0; i < mRows - sRows; i++)
            {
                count = 0;
                for(int j = 0; j < mColumns - sColumns; j++)
                {
                    count++;
                    
                    if(i == r && j == c)
                    {
                        grid[r][c] = symbol;;
                        std::cout << grid[r][c];
                    }
                    else
                    {
                        std::cout << grid[i][j];
                    }
                    
                    if(count == mColumns - sColumns)
                        std::cout << "\n";
                }
                std::cout << "\n";
            }
            break;
            
        case 9:
            //prints 9x9 grid
            for(int i = 0; i < mRows; i++)
            {
                for(int j = 0; j < mColumns; j++)
                {
                    count++;
                    
                    if(i == r && j == c)
                    {
                        grid[r][c] = symbol;;
                        std::cout << grid[r][c];
                    }
                    else
                    {
                        std::cout << grid[i][j];
                    }
                    
                    if(count == mColumns)
                        std::cout << "\n";
                }
                std::cout << "\n";
            }
        default:
            break;
    }
}


bool Game::checkMove(std::string position)
{
    std::cout << "Comparing " << position << " to all possible moves.\n";
    std::cout << "movesLeft has " << movesLeft.size() << " elements.\n";
    std::cout << "Which means, there are " << maxMoves << " left.\n";
    bool found = false;
    
    for(int i = 0; i < maxMoves; i++)
    {
        std::cout << "Entered for loop.\n";
        if(i%sizeOfGrid == 0 && i != 0)
            std::cout << "\n";
        
        if(movesLeft[i] == position)
        {
            std::cout << symbol;
            found = true;            //if move is found, function will return true
        }
        else
            std::cout << movesLeft[i];
    }
    
    std::cout << "Move found: " << found << "\n";
    return found;       //if move not found, function will return false
}


void Game::logMoves()
{
    std::string gridPosition;       //holds the move entered by user
    bool validMove = false;
    int attempts = 10;
    
    if(currentPlayer == human)
    {
        std::cout << userName << " turn: \n";
        //check if valid move with while loop
        while(validMove == false || attempts != 0)
        {
            std::cout << "Enter move: ";
            std::cin >> gridPosition;
            
            std::cout << "Chosen move is " << gridPosition << ".\n";
            
            validMove = checkMove(gridPosition);
            
            if(validMove == false)
            {
                attempts--;
                std::cout << "Invalid move. " << attempts << " attemps left before game quits.\n";
                if(attempts == 0)
                {
                    failedAttempts = true;
                    checkWin();
                }
            }
            
        }
    }
    else if(currentPlayer == computer)
    {
        //computer makes move
    }
    
    
    
    
    
    //Translate move string into grid position indeces
    switch(gridPosition[0])
    {
        case 'A':
            r = corrRowLetters[0];
        case 'B':
            r = corrRowLetters[1];
        case 'C':
            r = corrRowLetters[2];
        case 'D':
            r = corrRowLetters[3];
        case 'E':
            r = corrRowLetters[4];
        case 'F':
            r = corrRowLetters[5];
        case 'G':
            r = corrRowLetters[6];
        case 'H':
            r = corrRowLetters[7];
        case 'I':
            r = corrRowLetters[8];
    }
    
    
    switch(gridPosition[1])
    {
        case '1':
            c = corrColNumbers[0];
        case '2':
            c = corrColNumbers[1];
        case '3':
            c = corrColNumbers[2];
        case '4':
            c = corrColNumbers[3];
        case '5':
            c = corrColNumbers[4];
        case '6':
            c = corrColNumbers[5];
        case '7':
            c = corrColNumbers[6];
        case '8':
            c = corrColNumbers[7];
        case '9':
            c = corrColNumbers[8];
    }
    
    printGameGrid();
    //translate gridPosition to position on gameGrid
    //addDeleteMoves(gridPosition);
}

bool Game::checkWin()
{
    
    
    return false;
}

/*
//Gameplay method with game loop
std::string Game::play()
{
    Players* player, symbol, playerName;
    //name = playerName.userName();

        while(turn < MAX_MOVES)
        {
            turn++;
            std::cout << "\n***Turn " << turn << "***" << std::endl;
            
                                    
            turnPlayer = player->changeRoles();
            sym = symbol.assignSymbol();
            

            //human player makes a move
            if(human == turnPlayer)
            {
                humanTurn();
                found = false;       //redefinition of found to be used
            }
            
            
            //computer makes a move
            if(computer == turnPlayer)
            {
                if(turn < 9)
                {
                    randomNumber = (rand() % (computerOptions.size() - 1));
                    move = computerOptions[randomNumber];
                }
                else
                {
                    randomNumber = (rand() % (computerOptions.size()));
                    move = computerOptions[randomNumber];
                }
                
                
                std::cout << ai << " move: " << move << "\n\n";
                
                //Search algorithm for move in the vector
                while(index < computerOptions.size() && !found)
                {
                    if(computerOptions[index] == move)
                    {
                        found = true;       //set the flag
                        position = index;   //record the value's subscript
                    }
                    index++;                //go to next element
                }
                index = 0;      //resets index to 0
                found = false;  //resets found condition to false
            }
        
            
            //match move made with grid position
            for(int i = 0; i < possMoves.size(); i++)
            {
                if(computerOptions[position] == possMoves[i])
                {
                    switch(i)
                    {
                        case 0:
                            r = 2; c = 4;
                            break;
                        case 1:
                            r = 2; c = 8;
                            break;
                        case 2:
                            r = 2; c = 12;
                            break;
                        case 3:
                            r = 4; c = 4;
                            break;
                        case 4:
                            r = 4; c = 8;
                            break;
                        case 5:
                            r = 4; c = 12;
                            break;
                        case 6:
                            r = 6; c = 4;
                            break;
                        case 7:
                            r = 6; c = 8;
                            break;
                        case 8:
                            r = 6; c = 12;
                            break;
                        default:
                            break;
                    }
                }
            }
            
            //generates play grid
            generateGrid(r,c, playerSymbol, turn);

            
            //deletes element of corresponding move to position played in current turn
            computerOptions.erase(computerOptions.begin() + position);
            
            
            //switch players
            if(player == 1)
            {
                player = 2;
            }
            else
            {
                player = 1;
            }
            
            player.changeRoles();   //switches players after each turn
        }

        
        
        return score;
}



void Game::humanTurn()
{
    int maxAttempts = 5;
    Menu m;

    do
                {
                    std::cout << name << " move: ";
                    std::cin >> move;
                    std::cout << "\n";
                    
                    //Search algorithm for move in the vector
                    while(index < computerOptions.size() && !found)
                    {
                        if(computerOptions[index] == move)
                        {
                            found = true;       //set the flag
                            position = index;   //record the value's subscript
                        }
                        index++;                //go to next element
                    }
                    index = 0;
                    
                    //If move not found to be the same as any element, it is not a possible move
                    //Warning issued for three invalid attempts
                    //Game ends after three invalid attempts and goes back to main menu
                    if(!found)
                    {
                        //count++;
                        maxAttempts--;

                        std::cout << "Invalid move. " << maxAttempts << "remaining\n";
                        if(maxAttempts == 0)
                        {
                            "Redirecting you back to main menu...\n\n";
                            m.mainMenu();
                        }
                    }
                }while(!found);
}

void Game::computerTurn()
{

}

*/
