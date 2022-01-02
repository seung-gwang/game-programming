%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    ;스택 메모리와 스택 프레임 
    
    ;레제스터는 다양한 용도로 사용
    ; a b c d ==> 범용 레지스터
    ; 포인터 레지스터 ==> 특수 목적 레지스터, 위치를 가리키는 레지스터
    ; ---ip (instruction pointer) 다음 수행 명령어의 위치 (컴퓨터 구조시간에 배운 PC)
    ; ---sp (stack pointer) : 현재 스택 top 위치, 일종의 cursor
    ; ---bp (Base Pointer) 스택 상대주소 계산용
    
    ;stack push
    push rax
    push rbx
    push 1
    push 2
    call MAX ;call을 하면 Return 주소를 스택에 넣는
    PRINT_DEC 8, rax
    NEWLINE
    add rsp, 16 ;; 스택을 완전히 지워줘야 crash 안남.
    pop rbx ;레지스터 값 복원
    pop rax
    
    xor rax, rax
    ret
    
    
MAX:
    push rbp    ;]==> rbp레지스터가 기준이 되어 스택 내부의 값을 꺼내올 수 있음
    mov rbp, rsp;]==>하는 이유: 
    mov rax, [rbp+16]
    mov rbx, [rbp+24]
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1:
    pop rbp
    ret
    
    ;pop rbp     ;]
    ;ret
    
    ;stack pop ==> stack으로부터 register의 값을 복원
    pop rax
    pop rbx
    pop rcx
    ;이 시점에서는 스택에 아무것도 없으므로 rbp와 rsp는 동일한 주소
    
