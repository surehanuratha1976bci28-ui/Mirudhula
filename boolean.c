#include <stdbool.h>

// Helper function to recursively parse the expression
bool parse(const char* s, int* i) {
    // Base Case: True
    if (s[*i] == 't') {
        (*i)++;
        return true;
    }
    // Base Case: False
    if (s[*i] == 'f') {
        (*i)++;
        return false;
    }
    // Logical NOT: !(subExpr)
    if (s[*i] == '!') {
        *i += 2; // Move past '!('
        bool res = !parse(s, i);
        (*i)++; // Move past closing ')'
        return res;
    }
    
    // Logical AND/OR: &(subExpr1, ...) or |(subExpr1, ...)
    char op = s[*i];
    *i += 2; // Move past '&(' or '|('
    
    // Initialize default value based on identity elements
    bool res = (op == '&'); 
    
    while (true) {
        bool sub_res = parse(s, i);
        
        if (op == '&') {
            res &= sub_res;
        } else {
            res |= sub_res;
        }
        
        // If we reach the end of the current operator block
        if (s[*i] == ')') {
            (*i)++;
            break;
        }
        // Skip commas separating sub-expressions
        if (s[*i] == ',') {
            (*i)++;
        }
    }
    return res;
}

bool parseBoolExpr(char* expression) {
    int index = 0;
    return parse(expression, &index);
}
