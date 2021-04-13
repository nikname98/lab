#include<iostream>
#include<string>
#include<vector>
#include<cstdint>


struct Node{
    uint32_t _id;
    std::string _name;
    Node() : _id(0), _name("") {}

    friend std::istream& operator>> (std::istream &in, Node &node);
    friend std::ostream& operator<< (std::ostream &out, const Node &node);
};

class StackOfParameters
{
    public:
         StackOfParameters(): _top(-1){}
         StackOfParameters(const std::vector<uint32_t> &ids, const std::vector<std::string> &names);
         void push(const Node &elem);
         bool is_empty();
         Node& operator() ();
         friend std::istream& operator>> (std::istream &in, StackOfParameters &stack);
         friend std::ostream& operator<< (std::ostream &out, const StackOfParameters &stack);
    private:
         static const int64_t _size = 256;
         Node _nodes[_size];
         std::int64_t _top;
};







