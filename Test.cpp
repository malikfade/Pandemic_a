#include "doctest.h"
#include <string>
#include <iostream>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"


using namespace std;
using namespace pandemic;


Board board;

OperationsExpert builder_research_station{board, Manila};
OperationsExpert operationsExpert{board, Manila};
Dispatcher dispatcher{board, Manila};
Scientist scientist{board, Manila, 4};
Researcher researcher{board, Manila};
Medic medic{board, Manila};
Virologist virologist{board, Manila};
GeneSplicer geneSplicer{board, Manila};
FieldDoctor fieldDoctor{board, Manila};

void TakingCard(City c) {
    operationsExpert.take_card(c);
    dispatcher.take_card(c);
    scientist.take_card(c);
    researcher.take_card(c);
    medic.take_card(c);
    virologist.take_card(c);
    geneSplicer.take_card(c);
    fieldDoctor.take_card(c);
}

void new_diff_start_pos(){

    operationsExpert.take_card(SanFrancisco);
        operationsExpert.fly_direct(SanFrancisco);
    dispatcher.take_card(Washington);
        operationsExpert.fly_direct(Washington);
    scientist.take_card(LosAngeles);
        operationsExpert.fly_direct(LosAngeles);
    researcher.take_card(Lagos);
        operationsExpert.fly_direct(Lagos);
    medic.take_card(Algiers);
        operationsExpert.fly_direct(Algiers);
    virologist.take_card(Chennai);
        operationsExpert.fly_direct(Chennai);
    geneSplicer.take_card(Tokyo);
        operationsExpert.fly_direct(Tokyo);
    fieldDoctor.take_card(Sydney);
        operationsExpert.fly_direct(Sydney);
   
        
}

void take_diff_card(){

    operationsExpert.take_card(SanFrancisco);
    dispatcher.take_card(Washington);
    scientist.take_card(LosAngeles);
    researcher.take_card(Lagos);
    medic.take_card(Algiers);
    virologist.take_card(Chennai);
    geneSplicer.take_card(Tokyo);
    fieldDoctor.take_card(Sydney);
   
        
}

void build_in_research_station(City city) {
    builder_research_station.take_card(city);
    builder_research_station.fly_direct(city);
    builder_research_station.build();
}



TEST_CASE("BOARD TEST")
{
    CHECK(board.is_clean() == true);

    board[SanFrancisco] = 4;
            CHECK(board[SanFrancisco] == 4);

    board[LosAngeles] = 4;
            CHECK(board[LosAngeles] == 4);
            
    board[Moscow] = 4;
            CHECK(board[Moscow] == 4);

    board[Beijing] = 4;
            CHECK(board[Beijing] == 4);

    board[Chicago] = 4;
            CHECK(board[Chicago] == 4);

    board[MexicoCity] = 4;
            CHECK(board[MexicoCity] == 4);

    board[Istanbul] = 4;
            CHECK(board[Istanbul] == 4);

    board[Seoul] = 4;
            CHECK(board[Seoul] == 4);


    //able to change
    board[SanFrancisco] = 3;
            CHECK(board[SanFrancisco] == 3);

    board[LosAngeles] = 2;
            CHECK(board[LosAngeles] == 2);
            
    board[Moscow] = 3;
            CHECK(board[Moscow] == 3);

    board[Beijing] = 2;
            CHECK(board[Beijing] == 2);

    board[Chicago] = 3;
            CHECK(board[Chicago] == 3);

    board[MexicoCity] = 2;
            CHECK(board[MexicoCity] == 2);

    board[Istanbul] = 3;
            CHECK(board[Istanbul] == 3);

    board[Seoul] = 2;
            CHECK(board[Seoul] == 2);

    CHECK(board.is_clean() == false);

}


TEST_CASE ("FlyShuttleTest") 
{
     build_in_research_station(BuenosAires);
     build_in_research_station(Miami);
    CHECK_NOTHROW(operationsExpert.fly_shuttle(Miami));
    CHECK_NOTHROW(dispatcher.fly_shuttle(Miami));
    CHECK_THROWS(operationsExpert.fly_shuttle(Chicago));
    CHECK_THROWS(dispatcher.fly_shuttle(Chicago));


}

TEST_CASE("DriveTest")
{
            CHECK_NOTHROW(operationsExpert.drive(Bangkok));
            CHECK_NOTHROW(dispatcher.drive(Bangkok));
            CHECK_NOTHROW(operationsExpert.drive(Kolkata));
            CHECK_NOTHROW(dispatcher.drive(Kolkata));
            CHECK_THROWS(operationsExpert.drive(Istanbul));
            CHECK_THROWS(dispatcher.drive(Istanbul));
            CHECK_THROWS(operationsExpert.drive(Paris));
            CHECK_THROWS(dispatcher.drive(Paris));
}

TEST_CASE ("FlyChartetTest")
{
            CHECK_NOTHROW(operationsExpert.fly_charter(BuenosAires));
            CHECK_NOTHROW(dispatcher.fly_charter(BuenosAires));

    TakingCard(Taipei);
            CHECK_THROWS(operationsExpert.fly_charter(Taipei));
            CHECK_THROWS(dispatcher.fly_charter(Taipei));
}

TEST_CASE ("FlyDirecttTest") 
{
    TakingCard(Miami);
    CHECK_NOTHROW(operationsExpert.fly_direct(Miami));
    CHECK_NOTHROW(dispatcher.fly_direct(Miami));

    TakingCard(Miami);
    CHECK_THROWS(operationsExpert.fly_direct(Santiago));
    CHECK_THROWS(dispatcher.fly_direct(Santiago));
}