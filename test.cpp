#include"Stack.h"
#include<gtest/gtest.h>
#include<string>

TEST(ConstructorTestCase, StackOverFlow)
{
    std::vector<uint32_t> ids;
    std::vector<std::string> names;
    for(uint32_t i = 0; i < 257; i++){
        ids.push_back(i);
        names.push_back(std::to_string(i));
    }
    try{
        StackOfParameters stack(ids, names);
        FAIL() << "Expected StackOverFlow";
    }catch(const std::string &msg){
        EXPECT_EQ(msg, std::string("Stack overflow!"));
    }
    
}

TEST(ConstructorTestCase, EqualArrays)
{
    std::vector<uint32_t> ids = {1, 2, 3};
    std::vector<std::string> names = {"a", "aa"};

    try{
        StackOfParameters stack(ids, names);
        FAIL() << "Expected EqualArrays";
    }catch(const std::string &msg){
        EXPECT_EQ(msg, std::string("The size of the array ids must be equal to the array names"));
    }
}

TEST(MethodsTestCase, Push)
{
    StackOfParameters stack;
    Node node;
    node._id = 1;
    node._name = "1";

	    for(int i = 0; i < 256; i++){
		    stack.push(node);
	    }
	    try{
		    stack.push(node);
		    FAIL() << "Except stack overflow";
	    }catch(const std::string &msg){
		    EXPECT_EQ(msg, std::string("Overflow!"));
	    }
}


TEST(MethodsTestCase, Pop)
{
    StackOfParameters stack;
    Node node1;
    Node node2;

    node1._id = 1;
    node1._name = "1";
    node2._id = 2;
    node2._name = "2"; 

    stack.push(node1);
    stack.push(node2);

    try{
        stack();
        stack();
	stack();
        FAIL() << "Expected StackUnderFlow";
    }catch(const std::string &msg){
        EXPECT_EQ(msg, std::string("The stack is already empty!Underflow!"));
    }
}
TEST(MethodsTestCase, Empty)
{
	StackOfParameters stack;
	Node node;
	node._id = 1;
	node._name = "1";
	stack.push(node);
	stack();
	bool res = stack.is_empty();
	EXPECT_EQ(true, res);

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
