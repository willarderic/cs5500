enum Instruction {
    // General
    MOVQ,
    // Arithmetic
    ADDQ,
    SUBQ,
    IMULQ,
    IDIVQ,
    INCQ,
    DECQ,
    // Logic
    AND,
    OR,
    XOR,
    // Comparison
    CMPQ,
    JE, 
    JNE,
    JL,
    JLE,
    JG,
    JGE,
    JMP,
    JNZ,
    JZ,
    // Function
    CALL,
    RET,
    // For output
    LEA
};
