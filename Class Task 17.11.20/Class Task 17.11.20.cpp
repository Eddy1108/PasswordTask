#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

static constexpr int KEY_UP = 72;
static constexpr int KEY_DOWN = 80;
static constexpr int KEY_LEFT = 75;
static constexpr int KEY_RIGHT = 77;

class Board {
public:
    std::vector<char> password{ 'A', 'B', 'C', 'D', 'E', 'F' };
    std::vector<char> board{ 'A', 'A', 'A', 'A', 'A', 'A' };
    int pos{ 0 };

    void printBoard() {
        for (int i = 0; i < board.size(); i++) {    //Print area that contains the 'V'
            std::cout << '|';
            if (i == pos) {
                std::cout << 'V';
            }
            else {
                std::cout << ' ';
            }
        }

        std::cout << "|\n" << std::endl;

        for (int i = 0; i < board.size(); i++) {    //Print the board
            std::cout << '|' << board.at(i);
        }
        std::cout << "|\n" << std::endl;
    }

    bool checkPassword() {
        for (int i = 0; i < board.size(); i++) {
            if (board.at(i) != password.at(i))
                return false;
        }
        return true;
    }
};

int main()
{
    Board board;   
    while (!board.checkPassword()) {
        system("cls");
        board.printBoard();

        switch (_getch()) {     //Move the arrow or change the letters
        case KEY_UP:
            if (board.board.at(board.pos) != 'Z')
            board.board.at(board.pos)++;
            break;
        case KEY_DOWN:
            if (board.board.at(board.pos) != 'A')
            board.board.at(board.pos)--;
            break;
        case KEY_LEFT:
            if (board.pos > 0)
                board.pos--;
            break;
        case KEY_RIGHT:
            if (board.pos < board.board.size()-1)
                board.pos++;
            break;
        }
    }
    system("cls");  board.printBoard();
    std::cout << "PASSWORD ACCEPTED";
}