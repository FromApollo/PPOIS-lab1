#include "pch.h"
#include "D:/BSUIR/3 semester/PPOIS/lab1/Project1/Project1/CantorSet.h"
#include <sstream>

TEST(CantorSetTest, ViewCantorTreeTest) {
    string input = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o";

    CantorSet cantorSet(input);

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    cantorSet.viewCantorTree();

    cout.rdbuf(old);

    string expected_output =
        "\t\to \n\tk l m n o \n\t\tk l \na b c d e f g h i j k l m n o \n\t\te \n\ta b c d e \n\t\ta b \n";



    EXPECT_EQ(buffer.str(), expected_output);

}

TEST(CantorSetTest, ViewCantorTreeTestRemainder1) {
    string input = "a,b,c,d,n,z,m";


    CantorSet cantorSet(input);

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    cantorSet.viewCantorTree();

    cout.rdbuf(old);

    string expected_output =
        "\tz m \na b c d n z m \n\t\tc \n\ta b c \n\t\ta \n";



    EXPECT_EQ(buffer.str(), expected_output);

}
