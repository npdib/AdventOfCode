#include "inputtaker.h"

#include <sstream>

InputTaker& InputTaker::get()
{
    static InputTaker inputTaker;
    return inputTaker;
}

InputTaker::~InputTaker()
{
    file.close();
}

std::string InputTaker::getAll() const
{
    std::stringstream output;

    while (file.good())
    {
        char c = const_cast<std::fstream&>(file).get();
        output << c;
    }

    return output.str();
}

InputTaker::InputTaker()
{
    file.open("input.txt");
}

std::ostream& operator<<(std::ostream& os, const InputTaker& it)
{
    os << it.getAll();
    return os;
}
