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

    static std::string readAll();
    std::string readLine();
    bool moreToRead() const;

    void reset();

    friend std::ostream& operator<<(std::ostream& os, const InputTaker& it);

private:
    InputTaker();
    ~InputTaker();

private:
    std::fstream m_file;
};