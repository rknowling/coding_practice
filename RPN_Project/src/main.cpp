#include "RPN_Parser.h"
#include "RPN_Stack.h"

void print_stack_values(std::deque<float> stack){
    std::system("clear");
    std::cout << "t: " << stack[3] << std::endl;
    std::cout << "z: " << stack[2] << std::endl;
    std::cout << "y: " << stack[1] << std::endl;
    std::cout << "x: " << stack[0] << std::endl;
}

void shutdown_program(){
    std::cout << "Ending program..." << std::endl;
    exit(0);
}

int main(){
    printf("Welcome to the calculator app!\n");

    User_Input user_input;
    RPN_Parser parser_object;
    RPN_Stack stack_object;

    while (true){
        user_input.input_string = "";
        user_input.input_flag = Input_Flag::INVALID;
        parser_object.accept_input(user_input);
        stack_object.process_input(user_input);
        print_stack_values(stack_object.stack);
    }
    
    return 0;
}