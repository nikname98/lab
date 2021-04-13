
#include"Stack.h"


std::istream& operator>> (std::istream &in, Node &node){
    std::cout << "id: ";
    in >> node._id;
    std::cout << "name: ";
    in >> node._name;
    return in;
}


std::ostream& operator<< (std::ostream &out, const Node &node)
{
    out << "{" << "\n"
        << "        " << '"' <<"id" << '"' << ":" << node._id << "," << "\n" 
        << "        " << '"' <<"name" << '"' << ":" << node._name << '"' << "\n"
        << "    }";
    return out;
}

StackOfParameters::StackOfParameters(const std::vector<uint32_t> &ids, const std::vector<std::string> &names){
    _top = -1;
    if(ids.size() != names.size()){
        throw std::string("The size of the array ids must be equal to the array names");
    }
    else if(ids.size() >= _size){
        throw std::string("Stack overflow!");
    }else{
        for(int64_t i = 0; i < names.size(); i++){
            _nodes[i]._id = ids[i];
            _nodes[i]._name = names[i];
            _top++;
        }
    }
}


void StackOfParameters::push(const Node &elem){
     _top++;
    if(_top >= _size){
        throw std::string("Overflow!");
    }
    _nodes[_top] = elem;
}

bool StackOfParameters::is_empty(){
    return _top == -1;
}

Node& StackOfParameters::operator() (){
    if(this->is_empty()){
        throw std::string("The stack is already empty!Underflow!");
    }
    _top = _top - 1;
    return _nodes[_top - 1];
}

std::istream& operator>> (std::istream &in, StackOfParameters &stack){
    Node node;
    in >> node;
    stack.push(node);
    return in;
}

std::ostream& operator<< (std::ostream &out, const StackOfParameters &stack)
{
    out << "{" << "\n";
    for(int64_t i = stack._top; i >= 0; i--){
        if(i != stack._top){
            out << "    " << stack._nodes[i] << "," <<"\n";
        }else{
            out << "    " << stack._nodes[i] <<"\n";
        }
    }
    out << "}";
    return out;
}













