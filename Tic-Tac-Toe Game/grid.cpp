#include "grid.hpp"

#include <iostream>
#include <vector>

bool Grid::pickGrid()
{
    const int small = 3;        //small grid size (9 moves)
    const int med = 6;          //med grid size   (36 moves)
    const int large = 9;        //large grid size (81 moves)
    int attempts = 5;
    bool reachedMax;
    
    do{
        std::cout << "Enter grid size (3 for 3x3, 6 for 6x6, 9 for 9x9): \n>";
        std::cin >> gridSize;
        std::cout << "\n";
        
        if(gridSize == small || gridSize == med || gridSize == large)
        {
            attempts = 0;
            maxMoves = gridSize * gridSize;
            std::cout << "Grid size selected is " << gridSize << std::endl;
            std::cout << "Max moves possible are " << maxMoves << std::endl;
            
            generateGrid(gridSize);
            generateMoves(gridSize);
            
        }
        else
        {
            attempts--;
            std::cout << "Please enter one of the three options. " << attempts << " left.\n";

            if(attempts == 0)
            {
                std::cout << "Redirecting you to main menu.\n";
                reachedMax = true;
                return reachedMax;
                //m.mainMenu();
            }
        }
        
        //Game grid(maxMoves); //call game constructor to set maximum number of moves possible
    }while(attempts != 0);
    
    reachedMax = false;     //returns false to menuOptions() so obj doesnt get deleted
    
    
    setGridInfo();
    
    
    return reachedMax;
}



//Generates play grid by copying a portion or all of basicGrid and replacing characters
//with moves taken throughout the game
void Grid::generateGrid(int size)
{
    int count;
    
    std::cout << "\nGenerating Grid\n";
    switch(size)
    {
        case 3:
            //Prints 3x3 grid
            std::cout << "Generating 3x3 Grid\n";
            //Copy basicGrid into gameGrid vector
            gameGrid = basicGrid;
            //resize gameGrid to a 3x3 grid
            gameGrid.resize(mainRows-(2*subRows), std::vector<char>(mainCols-(2*subCols)));
            //print generated grid
            
            for(int i = 0; i < mainRows-(2*subRows); i++)
            {
                count = 0;
                for(int j = 0; j < mainCols-(2*subCols); j++)
                {
                    count++;
                    
                    std::cout << gameGrid[i][j];
                    
                    if(count == mainCols-(2*subCols))
                        std::cout << "\n";
                }
            }
            //std::cout << "Generated 3x3 Grid\n";
            break;
            
        case 6:
            //Prints 6x6 grid
            std::cout << "Generating 6x6 Grid\n";
            
            //copy basicGrid into gameGrid vector
            gameGrid = basicGrid;
            
            //resize gameGrid to a 6x6 grid
            gameGrid.resize(mainRows-subRows, std::vector<char>(mainCols-subCols));
            
            //print generated grid
            for(int i = 0; i < mainRows-subRows; i++)
            {
                count = 0;
                for(int j = 0; j < mainCols-subCols; j++)
                {
                    count++;
                    
                    std::cout << gameGrid[i][j];
                    
                    if(count == mainCols-subCols)
                        std::cout << "\n";
                }
            }
            //std::cout << "Generated 6x6 Grid\n";
            break;
            
        case 9:
            //prints 9x9 grid
            std::cout << "Generating 9x9 Grid\n";
            
            gameGrid = basicGrid;
            //resize gameGrid to a 9x9 grid
            gameGrid.resize(mainRows, std::vector<char>(mainCols));
            //print generated grid
            
            for(int i = 0; i < mainRows; i++)
            {
                count = 0;
                for(int j = 0; j < mainCols; j++)
                {
                    count++;
                    
                    std::cout << gameGrid[i][j];
                    
                    if(count == mainCols)
                        std::cout << "\n";
                }
            }
            //std::cout << "Generated 9x9 Grid\n";
            break;
            
        default:
            break;
    }
}


//Generates a vector full of possible moves for the chosen grid size
void Grid::generateMoves(int gridSize)
{
    const char rowLetters[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    const char colNumbers[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    //Each move will be comprised of a letter and an integer, making up a string
    //So that when the user enters a move (i.e. A3), we can compare it to all the possible moves available
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridSize; j++)
        {
            possMoves.push_back(std::string(1,rowLetters[i]) + colNumbers[j]);
        }
    }
    
    //Print List of Possible Moves
    std::cout << "All Possible Moves:\n";
    for(int i = 0; i < possMoves.size(); i++)
    {
        if(i % gridSize == 0 && i != 0)
            std::cout << "\n";
        
        std::cout << possMoves[i] << " ";
    }
        
    std::cout << "\n";
}

/*Will be done in Game class function
//Add and delete moves from possible moves vector
void Grid::addDeleteMoves(std::string gridPosition)
{
    //print all possible moves
    int count = gridSize;
    std::cout << "\n****All Possible Moves****\n";
    for(auto value: possMoves)
    {
        
        if(count == 0)
        {
            std::cout << "\n";
            count = gridSize;
        }
        
        std::cout << value << " ";
        count--;

    }
    std::cout << "\n";
}
 */

/*Will be done in GAme class function
void Grid::enterMove()
{
    std::cout << "Enter move: ";
    std::cin >> gridPosition;
    
    
    
    int corrRowLetters[9] = {3, 5, 7, 9, 11, 13, 15, 17, 19};
    int corrColNumbers[9] = {5, 9, 13, 17, 21, 25, 29, 33, 37};
    
    
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
    
    
    //translate gridPosition to position on gameGrid
    addDeleteMoves(gridPosition);
    
    
}
 */

/*Will be done in Game class
void Grid::printGameGrid(char symbol)
{
    switch(gridSize)
    {
        case 3:
            //Prints 3x3 grid
            for(int i = 0; i < ROWS - (2 * subRows); i++)
            {
                for(int j = 0; j < COLUMNS - ( 2 * subCols) ; j++)
                {
                    if(i == r && j == c)
                    {
                        gameGrid[r][c] = symbol;
                        std::cout << gameGrid[r][c];
                    }
                    else
                    {
                        std::cout << gameGrid[i][j];
                    }
                }
                std::cout << "\n";
            }
            break;
            
        case 6:
            //Prints 6x6 grid
            for(int i = 0; i < ROWS - subRows; i++)
            {
                for(int j = 0; j < COLUMNS - subCols; j++)
                {
                    if(i == r && j == c)
                    {
                        gameGrid[r][c] = symbol;;
                        std::cout << gameGrid[r][c];
                    }
                    else
                    {
                        std::cout << gameGrid[i][j];
                    }
                }
                std::cout << "\n";
            }
            break;
            
        case 9:
            //prints 9x9 grid
            for(int i = 0; i < ROWS; i++)
            {
                for(int j = 0; j < COLUMNS; j++)
                {
                    if(i == r && j == c)
                    {
                        gameGrid[r][c] = symbol;;
                        std::cout << gameGrid[r][c];
                    }
                    else
                    {
                        std::cout << gameGrid[i][j];
                    }
                }
                std::cout << "\n";
            }
        default:
            break;
    }
}
*/

void Grid::setGridInfo()
{
    int vecSize = possMoves.size();
    
    //calls Game constructor to set grid and move specifications
    //passes chosen game grid and total possible moves
    Game gridMoveInfo(possMoves, vecSize, gameGrid);
}
