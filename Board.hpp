#include <string>
#include "Direction.hpp"
#include <map>
#define maxLimit INT32_MAX // Big Enough Board
#define minLimit 0

using namespace std;

namespace ariel{
    class Board{
    private:
    // Limits: must be private to avoid exceptions(Imagine Expandable Board)
    // Defined this since this will not Change at Beginning
        unsigned int maximumRow=minLimit;
        unsigned int minimumRow=maxLimit;
        unsigned int maximumColumn=minLimit;
        unsigned int minimumColumn=maxLimit;
        std::map<unsigned int,std::map<unsigned int,string>> board; // A Map that will Represent the Board (Map of int and another map that stores the data)
    public:
        void post(unsigned int row, unsigned int col, Direction direction, string const & data); // Post Data Based on Given arg
        string read(unsigned int row, unsigned int col, Direction direction, unsigned int length); // Print Specific data based on given arg
        void show(); // Print Whole Board
    };
}