#include "RPN_Stack.h"

RPN_Stack::RPN_Stack(){}
RPN_Stack::~RPN_Stack(){}

double x; // Temporary intermediate number
double y; // Temporary intermediate number

void RPN_Stack::add_number_to_stack(std::string& input){
    // Convert the input string to double and then add the number to the front of the stack
    x = std::stod(input);
    stack.push_front(x);
    stack.pop_back();
}

void RPN_Stack::perform_math_op(std::string& input){
    x = stack[0];
    y = stack[1];

    if (input == "+"){
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y + x);
    }
    if (input == "-"){
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y - x);
    }
    if (input == "*"){
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y * x);
    }
    if (input == "/"){
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y / x);
    }
    if (input == "^"){
        stack.pop_front();
        stack.push_back(0);
        stack[0] = pow(y, x);
    }
    if (input == "^2"){
        stack[0] = pow(x, 2);
    }
    if (input == "sqrt"){
        stack[0] = sqrt(x);
    }
    if (input == "1/x"){
        stack[0] = 1 / x;
    }
    if (input == "sin"){
        stack[0] = sin(x);
    }
    if (input == "cos"){
        stack[0] = cos(x);
    }
    if (input == "tan"){
        stack[0] = tan(x);
    }
    if (input == "asin"){
        stack[0] = asin(x);
    }
    if (input == "acos"){
        stack[0] = acos(x);
    }
    if (input == "atan"){
        stack[0] = atan(x);
    }
    if (input == "log"){
        stack[0] = log10(x);
    }
    if (input == "ln"){
        stack[0] = log(x);
    }
    if (input == "e"){
        stack[0] = exp(x);
    }
}

void RPN_Stack::perform_stack_op(std::string& input){
    if (input == "u"){
        std::rotate(stack.rbegin(), stack.rbegin() + 1, stack.rend());
    }
    if (input == "d"){
        std::rotate(stack.begin(), stack.begin() + 1, stack.end());
    }
    if (input == "xy"){
        x = stack[0];
        y = stack[1];
        stack[0] = y;
        stack[1] = x;
    }
}

void RPN_Stack::process_input(User_Input& input){
    // Dispatch to the appropriate function based on the input flag
    switch (input.input_flag){
        case NUMBER:
            add_number_to_stack(input.input_string);
            break;
        case MATH_OP:
            perform_math_op(input.input_string);
            break;
        case STACK_OP:
            perform_stack_op(input.input_string);
            break;
        default:
            printf("Invalid input. Please enter a valid number, math operation, or stack operation.\n");
            break;
    }
}