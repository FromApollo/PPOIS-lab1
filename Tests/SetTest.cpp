#include "pch.h"
#include "D:/BSUIR/3 semester/PPOIS/lab1/Project1/Project1/Set.h"



class SetTest : public ::testing::Test {
protected:
    Set set1;
    Set set2;

    void SetUp() override {
        set1 = Set("a,b,c");
        set2 = Set("b,c,d");
    }
};

TEST_F(SetTest, ConstructorWithString) {
    Set testSet("x,y,z");
    ASSERT_EQ(testSet.cardinality(), 3);
    ASSERT_TRUE(testSet["x"]);
    ASSERT_TRUE(testSet["y"]);
    ASSERT_TRUE(testSet["z"]);
}

TEST_F(SetTest, DefaultConstructor) {
    Set emptySet;
    ASSERT_TRUE(emptySet.isEmpty());
}

TEST_F(SetTest, ConstructorWithCharPointer) {
    Set testSet("m,n,o");
    ASSERT_EQ(testSet.cardinality(), 3);
    ASSERT_TRUE(testSet["m"]);
    ASSERT_TRUE(testSet["n"]);
    ASSERT_TRUE(testSet["o"]);
}

TEST_F(SetTest, AddElement) {
    set1.addElement("d");
    ASSERT_TRUE(set1["d"]);
}

TEST_F(SetTest, AddExistingElement) {
    set1.addElement("a");
    ASSERT_EQ(set1.cardinality(), 3);
}

TEST_F(SetTest, DeleteElement) {
    set1.deleteElement("b");
    ASSERT_FALSE(set1["b"]);
    ASSERT_EQ(set1.cardinality(), 2);
}

TEST_F(SetTest, DeleteNonExistingElement) {
    set1.deleteElement("d");
    ASSERT_EQ(set1.cardinality(), 3);
}

TEST_F(SetTest, DeleteElementNotInSet) {
    set1.deleteElement("d");
    ASSERT_EQ(set1.cardinality(), 3);
}

TEST_F(SetTest, Cardinality) {
    ASSERT_EQ(set1.cardinality(), 3);
}

TEST_F(SetTest, IsEmpty) {
    ASSERT_FALSE(set1.isEmpty());
    Set emptySet;
    ASSERT_TRUE(emptySet.isEmpty());
}

TEST_F(SetTest, UnionOperator) {
    Set otherSet("c,d,e");
    Set resultSet = set1 + otherSet;
    ASSERT_EQ(resultSet.cardinality(), 5);
    ASSERT_TRUE(resultSet["a"]);
    ASSERT_TRUE(resultSet["b"]);
    ASSERT_TRUE(resultSet["c"]);
    ASSERT_TRUE(resultSet["d"]);
    ASSERT_TRUE(resultSet["e"]);
}

TEST_F(SetTest, UnionWithEmptySet) {
    Set otherSet;
    Set resultSet = set1 + otherSet;
    ASSERT_EQ(resultSet.cardinality(), 3);
}

TEST_F(SetTest, IntersectionOperator) {
    Set otherSet("b,c,d");
    Set resultSet = set1 * otherSet;
    ASSERT_EQ(resultSet.cardinality(), 2);
    ASSERT_TRUE(resultSet["b"]);
    ASSERT_TRUE(resultSet["c"]);
}

TEST_F(SetTest, IntersectionWithEmptySet) {
    Set otherSet;
    Set resultSet = set1 * otherSet;
    ASSERT_EQ(resultSet.cardinality(), 0);
}

TEST_F(SetTest, DifferenceOperator) {
    Set otherSet("b,c");
    Set resultSet = set1 - otherSet;
    ASSERT_EQ(resultSet.cardinality(), 1);
    ASSERT_TRUE(resultSet["a"]);
    ASSERT_FALSE(resultSet["b"]);
    ASSERT_FALSE(resultSet["c"]);
}

TEST_F(SetTest, DifferenceWithEmptySet) {
    Set otherSet;
    Set resultSet = set1 - otherSet;
    ASSERT_EQ(resultSet.cardinality(), 3);
}

TEST_F(SetTest, BooleanFunction) {
    auto booleanSubsets = set1.getBoolean();
    ASSERT_EQ(booleanSubsets.size(), 8);
}

TEST_F(SetTest, SplitStringIntoElements) {
    auto elements = set1.splitStringIntoElements("x,y,z");
    ASSERT_EQ(elements.size(), 3);
    ASSERT_EQ(elements[0], "x");
    ASSERT_EQ(elements[1], "y");
    ASSERT_EQ(elements[2], "z");
}

TEST_F(SetTest, SubscriptOperator) {
    ASSERT_TRUE(set1["a"]);
    ASSERT_FALSE(set1["x"]);
}

TEST_F(SetTest, PrintBoolean) {
    testing::internal::CaptureStdout();
    set1.printBoolean();
    string output = testing::internal::GetCapturedStdout();

    ASSERT_FALSE(output.empty());
    ASSERT_NE(output.find("Bullean:"), string::npos);
}

TEST_F(SetTest, PrintEmptySet) {
    Set emptySet;

    ostringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());

    emptySet.printSet();

    cout.rdbuf(oldCoutBuffer);

    ASSERT_EQ(buffer.str(), "Set is empty.\n");
}

TEST_F(SetTest, PrintNonEmptySet) {
    ostringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());

    set1.printSet();

    cout.rdbuf(oldCoutBuffer);

    ASSERT_EQ(buffer.str(), "Set elements: { a b c }\n");
}

TEST_F(SetTest, IntersectionWithCommonElements) {
    Set resultSet = set1 * set2;
    ASSERT_EQ(resultSet.cardinality(), 2);
    ASSERT_TRUE(resultSet["b"]);
    ASSERT_TRUE(resultSet["c"]);
}

TEST_F(SetTest, IntersectionWithIdenticalSets) {
    Set identicalSet("a,b,c");

    Set resultSet = set1 * identicalSet;

    ASSERT_EQ(resultSet.cardinality(), 3);

    ASSERT_TRUE(resultSet["a"]);
    ASSERT_TRUE(resultSet["b"]);
    ASSERT_TRUE(resultSet["c"]);
}

TEST_F(SetTest, UnionOperatorPlusEquals) {
    Set otherSet("d,e,f");
    set1 += otherSet;

    ASSERT_EQ(set1.cardinality(), 6);
    ASSERT_TRUE(set1["a"]);
    ASSERT_TRUE(set1["b"]);
    ASSERT_TRUE(set1["c"]);
    ASSERT_TRUE(set1["d"]);
    ASSERT_TRUE(set1["e"]);
    ASSERT_TRUE(set1["f"]);
}

TEST_F(SetTest, UnionOperatorPlusEqualsWithExistingElements) {
    Set otherSet("b,e,f");
    set1 += otherSet;

    ASSERT_EQ(set1.cardinality(), 5);
    ASSERT_TRUE(set1["a"]);
    ASSERT_TRUE(set1["b"]);
    ASSERT_TRUE(set1["c"]);
    ASSERT_TRUE(set1["e"]);
    ASSERT_TRUE(set1["f"]);
}

TEST_F(SetTest, UnionOperatorPlusEqualsWithEmptySet) {
    Set otherSet;
    set1 += otherSet;

    ASSERT_EQ(set1.cardinality(), 3);
}

TEST_F(SetTest, UnionOperatorPlusEqualsSelf) {
    set1 += set1;

    ASSERT_EQ(set1.cardinality(), 3); 
}

TEST_F(SetTest, UnionAssignmentOperator) {
    Set otherSet("c,d,e");
    set1 += otherSet;
    ASSERT_EQ(set1.cardinality(), 5);
    ASSERT_TRUE(set1["a"]);
    ASSERT_TRUE(set1["b"]);
    ASSERT_TRUE(set1["c"]);
    ASSERT_TRUE(set1["d"]);
    ASSERT_TRUE(set1["e"]);
}

TEST_F(SetTest, UnionAssignmentWithExistingElements) {
    Set otherSet("b,c");
    set1 += otherSet;
    ASSERT_EQ(set1.cardinality(), 3);
    ASSERT_TRUE(set1["a"]);
    ASSERT_TRUE(set1["b"]);
    ASSERT_TRUE(set1["c"]);
}

TEST_F(SetTest, DifferenceOperatorMinusEquals) {
    set1 -= set2;

    ASSERT_FALSE(set1["b"]);
    ASSERT_FALSE(set1["c"]);
    ASSERT_EQ(set1.cardinality(), 1);
    ASSERT_TRUE(set1["a"]);
}

TEST_F(SetTest, DifferenceOperatorMinusEqualsWithEmptySet) {
    set1 -= Set();

    ASSERT_EQ(set1.cardinality(), 3);
    ASSERT_TRUE(set1["a"]);
    ASSERT_TRUE(set1["b"]);
    ASSERT_TRUE(set1["c"]);
}

TEST_F(SetTest, DifferenceOperatorMinusEqualsWithNoCommonElements) {
    Set otherSet("x,y,z");
    set1 -= otherSet;

    ASSERT_EQ(set1.cardinality(), 3);
    ASSERT_TRUE(set1["a"]);
    ASSERT_TRUE(set1["b"]);
    ASSERT_TRUE(set1["c"]);
}

TEST_F(SetTest, DifferenceOperatorMinusEqualsEmptySetToSet) {
    Set emptySet;
    emptySet -= set1;

    ASSERT_TRUE(emptySet.isEmpty());
}



