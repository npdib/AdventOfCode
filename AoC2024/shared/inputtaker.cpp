#include "inputtaker.h"

#include <sstream>

InputTaker& InputTaker::get()
{
    static InputTaker inputTaker;
    return inputTaker;
}

InputTaker::~InputTaker()
{
    m_file.close();
}

std::string InputTaker::readAll()
{
    std::fstream file("input.txt");
    std::stringstream output;

    while (file.good())
    {
        char c = file.get();
        output << c;
    }

    file.close();
    return output.str();
}

std::string InputTaker::readLine()
{
    std::string line;
    std::getline(m_file, line);
    return line;
}

bool InputTaker::moreToRead() const
{
    return m_file.good();
}

void InputTaker::reset()
{
    m_file.close();
    m_file.open("input.txt");
}

InputTaker::InputTaker()
{
    m_file.open("input.txt");
}

std::ostream& operator<<(std::ostream& os, const InputTaker& it)
{
    std::string str;
    if (it.m_file.is_open())
        const_cast<std::fstream&>(it.m_file) >> str;

    os << str;
    return os;
}
