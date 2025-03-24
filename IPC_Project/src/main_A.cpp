#include "RPN_Parser.h"
#include "RPN_Stack.h"

int main(){
    printf("Welcome to the shared memory app!\n");






    
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