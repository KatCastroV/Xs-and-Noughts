

#ifndef game_hpp
#define game_hpp

//#include "menu.hpp"
//#include "players.hpp"
//#include "grid.hpp"

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

/*
class Game
{
    private:
        int n = 0;                      //counter moves played in a single game
        int turn = 0;                   //keeps track of number of turns
        int turnPlayer;
        int randomNumber;
        int index = 0;                  //subscript to search the array
        int r, c;                       //array[] rows and columns
        int numOfTurns;
        int sizeOfGrid;
        int numOfMoves;
        char sym;
        //bool found = false;
        bool gameWon;
        std::string ai = "Computer";
        std::string name;
        std::string move;
        std::string title;
        int humanPlayer;
        char symbol1;
        
        

    public:
    /*
        const int MAX_MOVES;            //max moves in a 3x3 grid game
        
        
        Game() : MAX_MOVES(0)
        {
            
        }
        Game(int maxMoves) : MAX_MOVES(maxMoves)
        {
            numOfTurns = 0;
            gameWon = false;
        }
     */
    /*
        Game(int humanRole, std::string user, char sym)
        {
            humanPlayer = humanRole;
            name = user;
            symbol1  = sym;
        }
        Game(int moves)
        {
            numOfMoves = moves;
        }
        
        //passed from Grid class
        void setGrid()
        {
            
        }
       
        void play();
        //std::string play();     //gameplay - returns move in a string
        void humanTurn();
        void computerTurn();
        void possibleMoves(int);
};*/




class Game
{
    private:
        int sizeOfGrid;
        int mRows;
        int mColumns;
        int sColumns;
        int sRows;
        int human;              //1 or 2 for first or second player respectively
        int computer;           //1 or 2 for first or second player respectively
        int currentPlayer;      //switches between 1 and 2 each turn
        int gameCount;          //keeps track of number of games played
        int turnCount;          //keeps track of number of turns taken in a game
        std::string move;       //holds move taken by human player
        std::string userName;   //holds username of player
        char humanSymbol;       //holds cross or nought
        char computerSymbol;    //holds cross or nought
        char symbol;
        char r, c;              //used to split move (string) to two chars
        std::vector<std::string> movesLeft;
        std::vector<std::vector<char>> grid;
        int vectorSize;
        int maxMoves;
        bool gameWon;
        bool failedAttempts;
        const int corrRowLetters[9] = {3, 5, 7, 9, 11, 13, 15, 17, 19};
        const int corrColNumbers[9] = {5, 9, 13, 17, 21, 25, 29, 33, 37};
        

    public:
        Game(){};
        //defined by the grid class
        Game(const int mainRows, const int mainCols, const int subCols, const int subRows) :
        mRows(mainRows), mColumns(mainCols), sColumns(subCols), sRows(subRows)
        {
            std::cout << "Initial constructor call by Grid class.\n";
            
        }
        //defined by players class
        Game(std::string user, int chosenRole, int compRole, int currPlayer, char humanSym, char compSym)
        {
            
            turnCount = 0;
            userName = user;
            std::cout << "User name is " << userName << std::endl;
            human = chosenRole;
            computer = compRole;
            humanSymbol = humanSym;
            computerSymbol = compSym;
            currentPlayer = currPlayer;
            std::cout << "Constructor called by players class.\n";
        }
    
        //defined by grid class
        Game(std::vector<std::string> possMoves, int vecSize, std::vector<std::vector<char>> gameGrid)
        {
            std::cout << "Second constructor call by Grid class.\n";
            movesLeft = possMoves;
            vectorSize = vecSize;
            maxMoves = vecSize;
            grid = gameGrid;
        }
        
        bool play();
        void logMoves();            //adds and deletes moves from list of all possible moves
        bool checkMove(std::string position);
        void switchPlayers();       //changes player roles and symbols
        void setGrid();             //sets the chosen grid size
        void printGameGrid();       //displays the game grid with moves
        bool checkWin();            //check if game has been won
};

#endif
