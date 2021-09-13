//
//  players.hpp
//  Grid Lines
//
//  Created by Katherine Castro on 4/6/21.
//

#ifndef players_hpp
#define players_hpp

#include "game.hpp"
//#include "players.hpp"
//#include "menu.hpp"


#include <stdio.h>
#include <string>
#include <iostream>

/*
class Players : public Game
{
    private:
        static const int firstPlayer = 1;   //integer ID of first player
        static const int secondPlayer = 2;  //integer ID of second player

    public:
        int human;                          //1 or 2
        int computer;                       //1 or 2
        int currentPlayer;                  //holds current players ID
        std::string user;                   //holds human player's name
        char playerSymbol;                  //holds either a cross or nought
        char cross = 'X';                   //symbol assigned to first player
        char nought = 'O';                  //symbol assigned to second player
    
        
    
        //Class methods
        void userName();
        void pickRole();
        void assignGameRoles();
        int changeRoles();
        char assignSymbol();
};
*/

class Players : public Game
{
    private:
        static const int firstPlayer = 1;
        static const int secondPlayer = 2;
        int chosenRole;   //1 or 2, for first and second player respectively
        int compRole;
        int currPlayer;
        std::string user;   //holds user name entered
        static const char cross = 'X';
        static const char nought = 'O';
        char fPlayerSymbol;
        char sPlayerSymbol;
        char humanSym;
        char compSym;

    public:
        Players()
        {
            fPlayerSymbol = cross;
            sPlayerSymbol = nought;
        }
        Players(std::string user, int chosenRole, int compRole, int currPlayer, const char humanSym, const char compSym) : Game(user, chosenRole, compRole, currPlayer, humanSym, compSym)
        {
        
        }

        bool setRoles();    //set player roles and corresponding symbols
        void userName();    //enter a username
};


#endif /* players_hpp */
