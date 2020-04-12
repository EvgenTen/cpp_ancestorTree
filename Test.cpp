#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;
using namespace std;

TEST_CASE("Test addMother+relation+find"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    CHECK(T.relation("Betsy")=="mother");
    CHECK(T.find("mother")=="Betsy");
}
TEST_CASE("Test addFather+relation+find"){
    Tree T("Bobbie");
    T.addFather("Bobbie","James");
    CHECK(T.relation("James")=="father");
    CHECK(T.find("father")=="James");
}
TEST_CASE("Test relation not found"){
    Tree T("Bobbie");
    T.addMother("Julian","Betsy");
    T.addFather("Julian","James");
    T.addMother("Bet","Elizabet");
    T.addFather("Tal","Jam");
    T.addMother("Bet","Elizabet");
    T.addFather("Bil","Jame");
    CHECK(T.relation("Carter")=="unrelated");
    CHECK(T.relation("Grayson")=="unrelated");
    CHECK(T.relation("Mason")=="unrelated");
    CHECK(T.relation("Lincoln")=="unrelated");
    CHECK(T.relation("Hudson")=="unrelated");
    CHECK(T.relation("Christian")=="unrelated");
    CHECK(T.relation("Carter")=="unrelated");
    CHECK(T.relation("Easton")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Roben")=="unrelated");
}
TEST_CASE("Test relation :father, mother, grandmother, great-grandfather, great-great-grandmother"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    T.addFather("Bobbie","James");
//Betsy-mother-
    T.addMother("Betsy","Beverly");
    T.addFather("Betsy","Colton");
//James-father-
    T.addMother("James","Camilla");
    T.addFather("James","Greyson");
//Beverly-grandmother-
    T.addMother("Beverly","Cara");
    T.addFather("Beverly","Robert");
//Colton-grandfather-
    T.addMother("Colton","Charlotte");
    T.addFather("Colton","Greyson");
//Camilla-grandmother-
    T.addMother("Camilla","Austin");
    T.addFather("Camilla","Chloe");
//Greyson-grandfather-
    T.addMother("Greyson","Chelsea");
    T.addFather("Greyson","Cooper");
//Cara-great-grandmother-
    T.addMother("Cara","Clara");
    T.addFather("Cara","Parker");
//Robert-great-grandfather-
    T.addMother("Robert","Clarisa");
    T.addFather("Robert","Jhon");
//Charlotte-great-grandmother-
    T.addMother("Charlotte","Claudia");
    T.addFather("Charlotte","Wesley");
//Greyson-great-grandfather-
    T.addMother("Greyson","Ann");
    T.addFather("Greyson","Beni");
//Austin-great-grandmother-
    T.addMother("Austin","Fali");
    T.addFather("Austin","Han");
//Chloe-great-grandfather-
    T.addMother("Chloe","Many");
    T.addFather("Chloe","Stiw");
//Chelsea-great-grandmother-
    T.addMother("Chelsea","Len");
    T.addFather("Chelsea","Andre");
//Cooper-great-grandfather-
    T.addMother("Cooper","Ira");
    T.addFather("Cooper","Sasha");
//Clara-great-great-grandmother-
    T.addMother("Clara","Iris");
    T.addFather("Clara","Martin");
//Parker-great-great-grandfather-
    T.addMother("Parker","April");
    T.addFather("Parker","Silas");
//Clarisa-great-great-grandmother-
    T.addMother("Clarisa","Arlene");
    T.addFather("Clarisa","Miles");
//Jhon-great-great-grandfather-
    T.addMother("Jhon","Ava");
    T.addFather("Jhon","Harrison");
//Claudia-great-great-grandmother-
    T.addMother("Claudia","Emma");
    T.addFather("Claudia","Brandon");
//Wesley-great-great-grandfather-
    T.addMother("Wesley","Nina");
    T.addFather("Wesley","Braxton");
//Ann-great-great-grandmother-
    T.addMother("Ann","Molly");
    T.addFather("Ann","Brooks");
//Beni-great-great-grandfather-
    T.addMother("Beni","Vera");
    T.addFather("Beni","Dean");
//Fali-great-great-grandmother-
    T.addMother("Fali","Lucy");
    T.addFather("Fali","Hayden");
//Han-great-great-grandfather-
    T.addMother("Han","Alexia");
    T.addFather("Han","Karter");
//Many-great-great-grandmother-
    T.addMother("Many","Debra");
    T.addFather("Many","Dean");
//Stiw-great-great-grandfather-
    T.addMother("Stiw","Rosa");
    T.addFather("Stiw","Myles");
//Len-great-great-grandmother-
    T.addMother("Len","Debra");
    T.addFather("Len","Dean");
//Andre-great-great-grandfather-
    T.addMother("Andre","Lucia");
    T.addFather("Andre","Jeremy");
//Ira-great-great-grandmother-
    T.addMother("Ira","Amanda");
    T.addFather("Ira","Oscar");
//Sasha-great-great-grandfather-
    T.addMother("Sasha","Traci");
    T.addFather("Sasha","Legend");

    CHECK(T.relation("Bobbie")=="name");
    CHECK(T.relation("Betsy")=="mother");
    CHECK(T.relation("James")=="father");
    CHECK(T.relation("Beverly")=="grandmother");
    CHECK(T.relation("Colton")=="grandfather");
    CHECK(T.relation("Camilla")=="grandmother");
    CHECK(T.relation("Greyson")=="grandfather");
    CHECK(T.relation("Cara")=="great-grandmother");
    CHECK(T.relation("Robert")=="great-grandfather");
    CHECK(T.relation("Charlotte")=="great-grandmother");
    CHECK(T.relation("Greyson")=="great-grandfather");
    CHECK(T.relation("Austin")=="great-grandmother");
    CHECK(T.relation("Chloe")=="great-grandfather");
    CHECK(T.relation("Chelsea")=="great-grandmother");
    CHECK(T.relation("Cooper")=="great-grandfather");
    CHECK(T.relation("Clara")=="great-great-grandmother");
    CHECK(T.relation("Parker")=="great-great-grandfather");
    CHECK(T.relation("Clarisa")=="great-great-grandmother");
    CHECK(T.relation("Jhon")=="great-great-grandfather");
    CHECK(T.relation("Claudia")=="great-great-grandmother");
    CHECK(T.relation("Wesley")=="great-great-grandfather");
    CHECK(T.relation("Ann")=="great-great-grandmother");
    CHECK(T.relation("Beni")=="great-great-grandfather");
    CHECK(T.relation("Fali")=="great-great-grandmother");
    CHECK(T.relation("Han")=="great-great-grandfather");
    CHECK(T.relation("Many")=="great-great-grandmother");
    CHECK(T.relation("Stiw")=="great-great-grandfather");
    CHECK(T.relation("Len")=="great-great-grandmother");
    CHECK(T.relation("Andre")=="great-great-grandfather");
    CHECK(T.relation("Ira")=="great-great-grandmother");
    CHECK(T.relation("Sasha")=="great-great-grandfather");
    
}
TEST_CASE("Test function - remove"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    T.addFather("Bobbie","James");
//Betsy-mother-
    T.addMother("Betsy","Beverly");
    T.addFather("Betsy","Colton");
//James-father-
    T.addMother("James","Camilla");
    T.addFather("James","Greyson");
//Beverly-grandmother-
    T.addMother("Beverly","Cara");
    T.addFather("Beverly","Robert");
//Colton-grandfather-
    T.addMother("Colton","Charlotte");
    T.addFather("Colton","Greyson");
//Camilla-grandmother-
    T.addMother("Camilla","Austin");
    T.addFather("Camilla","Chloe");
//Greyson-grandfather-
    T.addMother("Greyson","Chelsea");
    T.addFather("Greyson","Cooper");
    T.remove("Greyson");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Cooper")=="unrelated");
    CHECK(T.relation("Chelsea")=="unrelated");
    T.remove("Camilla");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Austin")=="unrelated");
    CHECK(T.relation("Chloe")=="unrelated");
    T.remove("Colton");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Charlotte")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    T.remove("Beverly");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Cara")=="unrelated");
    CHECK(T.relation("Robert")=="unrelated");
    T.remove("James");
    CHECK(T.relation("James")=="unrelated");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    T.remove("Betsy");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    T.remove("Bobbie");
    CHECK(T.relation("Bobbie")=="unrelated");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("James")=="unrelated");
}
TEST_CASE("Test remove -root "){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    T.addFather("Bobbie","James");
//Betsy-mother-
    T.addMother("Betsy","Beverly");
    T.addFather("Betsy","Colton");
//James-father-
    T.addMother("James","Camilla");
    T.addFather("James","Greyson");
//Beverly-grandmother-
    T.addMother("Beverly","Cara");
    T.addFather("Beverly","Robert");
//Colton-grandfather-
    T.addMother("Colton","Charlotte");
    T.addFather("Colton","Greyson");
//Camilla-grandmother-
    T.addMother("Camilla","Austin");
    T.addFather("Camilla","Chloe");
//Greyson-grandfather-
    T.addMother("Greyson","Chelsea");
    T.addFather("Greyson","Cooper");
    T.remove("Bobbie");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Cooper")=="unrelated");
    CHECK(T.relation("Chelsea")=="unrelated");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Austin")=="unrelated");
    CHECK(T.relation("Chloe")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Charlotte")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Cara")=="unrelated");
    CHECK(T.relation("Robert")=="unrelated");
    CHECK(T.relation("James")=="unrelated");
    CHECK(T.relation("Camilla")=="unrelated");
    CHECK(T.relation("Greyson")=="unrelated");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("Beverly")=="unrelated");
    CHECK(T.relation("Colton")=="unrelated");
    CHECK(T.relation("Bobbie")=="unrelated");
    CHECK(T.relation("Betsy")=="unrelated");
    CHECK(T.relation("James")=="unrelated");
}
TEST_CASE("Test - choosing the right answer between two"){
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    T.addFather("Bobbie","James");
//Betsy-mother-
    T.addMother("Betsy","Betsy");
    T.addFather("Betsy","Colton");
//James-father-
    T.addMother("James","Camilla");
    T.addFather("James","Greyson");
//Betsy-grandmother-
    T.addMother("Betsy","Cara");
    T.addFather("Betsy","Robert");

    CHECK(T.relation("Betsy")=="mother");
    CHECK(T.relation("Betsy")=="grandmother");
} 
TEST_CASE("Test exception") {
    Tree T("Bobbie");
    T.addMother("Bobbie","Betsy");
    T.addFather("Bobbie","James");
//Betsy-mother-
    T.addMother("Betsy","Beverly");
    T.addFather("Betsy","Colton");
//James-father-
    T.addMother("James","Camilla");
    T.addFather("James","Greyson");
//Beverly-grandmother-
    T.addMother("Beverly","Cara");
    T.addFather("Beverly","Robert");
//Colton-grandfather-
    T.addMother("Colton","Charlotte");
    T.addFather("Colton","Greyson");
//Camilla-grandmother-
    T.addMother("Camilla","Austin");
    T.addFather("Camilla","Chloe");

    CHECK_THROWS_AS(T.relation("Bobbie")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Betsy")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("James")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Beverly")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Colton")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Camilla")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Greyson")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Cara")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Robert")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Charlotte")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Greyson")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Austin")=="unrelated", std::exception);
    CHECK_THROWS_AS(T.relation("Chloe")=="unrelated", std::exception);
}
