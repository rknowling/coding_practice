#include "common_header.h"

// The parser processes user inputs for calculator functions
class RPN_Parser{
private:
    const std::set<std::string> math_ops = {
        "+",
        "-",
        "*",
        "/",
        "^",
        "^2",
        "sqrt",
        "1/x",
        "sin",
        "cos",
        "tan",
        "asin",
        "acos",
        "atan",
        "log",
        "ln",
        "e"
    };

    const std::set<std::string> stack_ops = {
        "u",    // up
        "d",    // down
        "xy"    // swap x and y
    };

    const std::regex value_match_rule;

public:
    RPN_Parser();
    ~RPN_Parser();
    void accept_input(User_Input& input);
};