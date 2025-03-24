#include "RPN_Stack.h"

RPN_Stack::Memory_Access(){}
RPN_Stack::~RPN_Stack(){}

double x; // Temporary intermediate number
double y; // Temporary intermediate number

void RPN_Stack::add_number_to_stack(std::string& input){
    // Convert the input string to double and then add the number to the front of the stack
    std::cout << "adding value to stack" << std::endl;
    x = std::stod(input);
    stack.push_front(x);
    stack.pop_back();
}

void RPN_Stack::perform_math_op(std::string& input){
    x = stack[0];
    y = stack[1];

    std::cout << "performing math..." << std::endl;
    if (input == "+"){
        std::cout << "adding..." << std::endl;
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y + x);
    }
    if (input == "-"){
        std::cout << "subtracting..." << std::endl;
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y - x);
    }
    if (input == "*"){
        std::cout << "multiplying..." << std::endl;
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y * x);
    }
    if (input == "/"){
        std::cout << "dividing..." << std::endl;
        stack.pop_front();
        stack.push_back(0);
        stack[0] = (y / x);
    }
    if (input == "^"){
        std::cout << "raising to a power..." << std::endl;
        stack.pop_front();
        stack.push_back(0);
        stack[0] = pow(y, x);
    }
    if (input == "^2"){
        std::cout << "squaring..." << std::endl;
        stack[0] = pow(x, 2);
    }
    if (input == "sqrt"){
        std::cout << "taking square root..." << std::endl;
        stack[0] = sqrt(x);
    }
    if (input == "1/x"){
        std::cout << "taking reciprocal..." << std::endl;
        stack[0] = 1 / x;
    }
    if (input == "sin"){
        std::cout << "taking sine..." << std::endl;
        stack[0] = sin(x);
    }
    if (input == "cos"){
        std::cout << "taking cosine..." << std::endl;
        stack[0] = cos(x);
    }
    if (input == "tan"){
        std::cout << "taking tangent..." << std::endl;
        stack[0] = tan(x);
    }
    if (input == "asin"){
        std::cout << "taking arcsine..." << std::endl;
        stack[0] = asin(x);
    }
    if (input == "acos"){
        std::cout << "taking arccosine..." << std::endl;
        stack[0] = acos(x);
    }
    if (input == "atan"){
        std::cout << "taking arctangent..." << std::endl;
        stack[0] = atan(x);
    }
    if (input == "log"){
        std::cout << "taking log base 10..." << std::endl;
        stack[0] = log10(x);
    }
    if (input == "ln"){
        std::cout << "taking natural log..." << std::endl;
        stack[0] = log(x);
    }
    if (input == "e"){
        std::cout << "raising e to a power..." << std::endl;
        stack[0] = exp(x);
    }
}

void RPN_Stack::perform_stack_op(std::string& input){
    if (input == "u"){
        std::cout << "rotating stack up..." << std::endl;
        std::rotate(stack.rbegin(), stack.rbegin() + 1, stack.rend());
    }
    if (input == "d"){
        std::cout << "rotating stack down..." << std::endl;
        std::rotate(stack.begin(), stack.begin() + 1, stack.end());
    }
    if (input == "xy"){
        std::cout << "swap x and y..." << std::endl;
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