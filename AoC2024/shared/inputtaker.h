#pragma once

#include <fstream>

class InputTaker
{
public:
    static InputTaker& get();

    InputTaker(InputTaker&) = delete;
    InputTaker(InputTaker&&) = delete;
    InputTaker operator=(InputTaker&) = delete;
    InputTaker& operator=(InputTaker&&) = delete;

    ~InputTaker();

    std::string getAll() const;
    friend std::ostream& operator<<(std::ostream& os, const InputTaker& it);

private:
    InputTaker();

private:
    std::fstream file;
};