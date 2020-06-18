#include "opcode.h"

// 0NNN
void call_mcroutine(
    cpu_t& cpu,
    mem_t& mem,
    stack_t& stack,
    display_t& display,
    keys_t& keys
){}
// OOE0
void clear_display(
    cpu_t& cpu,
    mem_t& mem,
    stack_t& stack,
    display_t& display,
    keys_t& keys
){}
// 00EE
void ret(
    cpu_t& cpu, 
    mem_t& mem, 
    stack_t& stack, 
    display_t& display, 
    keys_t& keys
){}
// 1NNN
void jump(
    cpu_t& cpu, 
    mem_t& mem, 
    stack_t& stack, 
    display_t& display, 
    keys_t& keys
){}
// 2NNN
void call(
    cpu_t& cpu, 
    mem_t& mem, 
    stack_t& stack, 
    display_t& display, 
    keys_t& keys
){}

// 3XNN
void skip_eq(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 4XNN
void skip_neq(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 5XY0
void skip_req(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 6XNN
void lit_set(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 7XNN
void ladd(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY0
void rset(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY1
void rorset(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY2
void randset(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY3
void rxorset(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY4
void radd(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY5
void rsub(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY6
void rshift(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XY7
void rdiff(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 8XYE
void lshift(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// 9XY0
void skip_rneq(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// ANNN
void seti(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// BNNN
void jump_v0(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// CXNN
void rand_o(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// DXYN
void draw(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// EX9E
void keq(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// EXA1
void kneq(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX07
void get_delay(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX0A
void get_key(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX15
void set_delay(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX18
void set_sound(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX1E
void iadd(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX29
void set_i_sprite(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX33
void bcd(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX55
void reg_dump(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
// FX65
void reg_load(
    cpu_t& cpu, 
    mem_t& mem,
    stack_t& stack,
    display_t& display, 
    keys_t& keys
){}
