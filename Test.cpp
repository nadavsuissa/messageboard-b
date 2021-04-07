#include<stdlib.h>
#include<ctime>
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;

Board board;



TEST_CASE("Good code") {

    srand(std::time(NULL));
    uint row =0;
    uint colum=0;
    int i =0;
    int ten= 10;

   
    
    CHECK(board.read(5,5,Direction::Horizontal,1).compare("_"));
    CHECK_NOTHROW(board.post(5,5,Direction::Horizontal,"hello1"));
    CHECK(board.read(5,5,Direction::Horizontal,6).compare("hello1"));
    CHECK(board.read(5,11,Direction::Vertical,1).compare("1"));
    CHECK(board.read(5,12,Direction::Horizontal,1).compare("_"));

    CHECK(board.read(5,5,Direction::Vertical,1).compare("_"));
    CHECK_NOTHROW(board.post(5,5,Direction::Vertical,"hello2"));
    CHECK(board.read(5,5,Direction::Vertical,6).compare("hello2"));
    CHECK(board.read(11,5,Direction::Vertical,1).compare("2"));
    CHECK(board.read(12,5,Direction::Vertical,1).compare("_"));

    CHECK_NOTHROW(board.post(5,11,Direction::Horizontal,"3"));
    CHECK(board.read(5,5,Direction::Horizontal,6).compare("hello3"));

    CHECK_NOTHROW(board.post(5,5,Direction::Horizontal,"hdefag"));
    CHECK(board.read(5,5,Direction::Horizontal,6).compare("hdefag"));

    CHECK_NOTHROW(board.post(11,5,Direction::Vertical,"4"));
    CHECK(board.read(5,5,Direction::Vertical,6).compare("hello4"));
    CHECK_NOTHROW(board.post(5,5,Direction::Vertical,"hdefag"));
    CHECK(board.read(5,5,Direction::Vertical,6).compare("hdefag"));
    
    for(; i<ten; i++)
    {
       row= rand() %UINT16_MAX;
       CHECK_NOTHROW(board.post(row,colum,Direction::Horizontal,"hello1"));
       CHECK(board.read(row,colum,Direction::Horizontal,6).compare("hello1"));

       CHECK_NOTHROW(board.post(row,colum,Direction::Vertical,"hello1"));
       CHECK(board.read(row,colum,Direction::Vertical,6).compare("hello1"));    
    }
    for(; i<ten; i++)
    {
       colum= rand() % UINT16_MAX ;
       CHECK_NOTHROW(board.post(row,colum,Direction::Horizontal,"hello1"));
       CHECK(board.read(row,colum,Direction::Horizontal,6).compare("hello1"));

       CHECK_NOTHROW(board.post(row,colum,Direction::Vertical,"hello1"));
       CHECK(board.read(row,colum,Direction::Vertical,6).compare("hello1"));    
    }
     
}



    
    