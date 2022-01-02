%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    ;함수 ==> 프로시져 procedure, 또는 subroutine라고 어셈블리에서 부름.
    call PRINT_MSG
    mov eax, 10
    mov ebx, 15
    call MAX
    PRINT_DEC 4, ecx     
    xor rax, rax
    ret

PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret ;함수 종료==> call 다음으로 돌아감
;두 값중 더 큰 값을 반환하는 max 함수 구현? ==> 두 값을 어떻게 넘겨받지? 반환값을 어떻게 받지?
;eax와 ebx 입력값을 ecx에 반환
MAX:
    cmp eax, ebx
    jg L1;eax>ebx
    mov ecx, ebx
    jmp L2   
L1:
    mov ecx, eax
L2:
    ret
;그런데 인자가 더 많다면? 10개, 20개... 또 eax, ebx등 레지스터에 이미 중요한 값이 있다면?==>레지스터만 이용하는 것은 위험할 수 있다.
;전부 data section에서 저장하기엔 메모리 낭비가 너무 크다. ==> 다른 메모리 구조가 필요하다.
;스택 stack 메모리 영역을 사용해야함. ==> 함수가 사용하는 일종의 메모장//매개변수 전달, return address 등 저장...함수가 끝나면 정리 가능.
section .data
msg db 'Hello World', 0x00

section .bss
    num resb 10