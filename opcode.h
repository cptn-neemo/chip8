#ifndef __opcode_h
#define __opcode_h


// 0NNN
void call_mcroutine();
// OOE0
void clear_display();
// 00EE
void ret();
// 1NNN
void jump();
// 2NNN
void call();
// 3XNN
void skip_eq();
// 4XNN
void skip_neq();
// 5XY0
void skip_req();
// 6XNN
void lit_set();
// 7XNN
void ladd();
// 8XY0
void rset();
// 8XY1
void rorset();
// 8XY2
void randset();
// 8XY3
void rxorset();
// 8XY4
void radd();
// 8XY5
void rsub();
// 8XY6
void rshift();
// 8XY7
void rdiff();
// 8XYE
void lshift();
// 9XY0
void skip_rneq();
// ANNN
void seti();
// BNNN
void jump_v0();
// CXNN
void rand_o();
// DXYN
void draw();
// EX9E
void keq();
// EXA1
void kneq();
// FX07
void get_delay();
// FX0A
void get_key();
// FX15
void set_delay();
// FX18
void set_sound();
// FX1E
void iadd();
// FX29
void set_i_sprite();
// FX33
void bcd();
// FX55
void reg_dump();
// FX65
void reg_load();

const std::array<void(*)(), 35> opcodeTable = {
    call_mcroutine,
    clear_display,
    ret,
    jump,
    call,
    skip_eq,
    skip_neq,
    skip_req,
    lit_set,
    ladd,
    rset,
    rorset,
    randset,
    rxorset,
    radd,
    rsub,
    rshift,
    rdiff,
    lshift,
    skip_rneq,
    seti,
    jump_v0,
    rand_o,
    draw,
    keq,
    kneq,
    get_delay,
    get_key,
    set_delay,
    set_sound,
    iadd,
    set_i_sprite,
    bcd,
    reg_dump,
    reg_load
};

#endif
