#include "common_header.h"

// The RPN stack is a stack that holds values and processes operations
class RPN_Stack{
private:
    void add_number_to_stack(std::string& input);
    void perform_math_op(std::string& input);
    void perform_stack_op(std::string& input);

public:
    std::deque<float> stack = {0.0, 0.0, 0.0, 0.0};

    RPN_Stack();
    ~RPN_Stack();
    void process_input(User_Input& input);
};