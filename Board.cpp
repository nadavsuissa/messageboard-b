#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length)
    {
        string textbuilder; // The String that we will Build - Should not be Initialized - Redundant(Tidy..)!
        int i = 0; // For While
        while (i < length)
        {
            if (board.find(row) == board.end() || board[row].find(col) == board[row].end()|| board.empty()) // If Either Col or Row at End then add Blank...(Validity)
            {
                textbuilder.append("_");
            }
            else // Otherwise Add/Build text to Answer
            {
                textbuilder.append(board[row][col]);
            }
            if (direction == Direction::Vertical) // Depending on direction Update Index...
            {
                row++;
            }
            else
            {
                col++;
            }
            i++;
        }

        return textbuilder;
    }
    void Board::post(unsigned int row, unsigned int col, Direction direction, string const &data)
    {
        unsigned int i = 0; // For While
        int looplength = data.length(); // For While

        // This part Updates all The Board Limits in order to avoid exceptions and Valid Reading and Posting

        // Obviously if Vertical Post then Update Row Aspect
        if (direction == Direction::Vertical)
        {

            maximumRow = max(maximumRow, row + unsigned(data.length()));
            if (col > maximumColumn)
            {
                maximumColumn = col;
            }
        }

        // Obviously if Horizontal Post then Update Columns Aspect
        else
        {
            maximumColumn = max(maximumColumn, col + unsigned(data.length()));
            if (row > maximumRow)
            {
                maximumRow = row;
            }
        }

        if (minimumRow > row)
        {
            minimumRow = row;
        }

        if (minimumColumn > col)
        {
            minimumColumn = col;
        }
        // Iterate over Word - Data and Post while Updating Rows and Columns Aspect
        while (i < looplength)
        {
            board[row][col] = data.at(i);
            // Like Above if Vertical Then Rows Update
            if (direction == Direction::Vertical)
            {
                row++;
            }
            // Else we are posting Horizontal and we need to update Columns 
            else
            {
                col++;
            }
            i++;
        }
    }

    void Board::show()
    {
        unsigned int i = minimumRow;
        unsigned int j = minimumColumn;

        // simple 2 while loop to iterate over Board 
        while (i < maximumRow+1)
        {

            while (j < maximumColumn)
            {
                // If not Empty then obviously Print
                if (!board[i][j].empty())
                {
                    cout << board[i][j];
                }
                // Blank..
                else
                {
                    cout << "_";
                }
                j++;
            }
            j = minimumColumn; // Important - must Update J in order to have a Valid indicator 
            cout << endl;
            i++;
        }
    }
}