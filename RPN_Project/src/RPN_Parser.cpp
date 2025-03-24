#include "RPN_Parser.h"

RPN_Parser::RPN_Parser() : value_match_rule("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$"){}
RPN_Parser::~RPN_Parser(){}

void RPN_Parser::accept_input(User_Input& input){
    // Collect user input and store in variable
    std::cout << "Enter a number, math operation, or stack operation: ";
    std::cin >> input.input_string;
    std::cout << input.input_string << " <- input_string" << std::endl;

    // Check if user input is a number
    if (std::regex_match(input.input_string, value_match_rule)){
        input.input_flag = NUMBER;
        std::cout << input.input_flag << " <- input_flag" << std::endl;
    }

    // Check if user input is a math operation
    if (math_ops.contains(input.input_string)){
        input.input_flag = MATH_OP;
        std::cout << input.input_flag << " <- input_flag" << std::endl;
    }

    // Check if user input is a stack operation
    if (stack_ops.contains(input.input_string)){
        input.input_flag = STACK_OP;
        std::cout << input.input_flag << " <- input_flag" << std::endl;
    }

    // Check if user input is to quit the program
    if (input.input_string == "quit"){
        shutdown_program();
    }
}

// come back to unions to make checking user input more compact