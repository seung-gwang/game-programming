%include "io64.inc"
;연습 문제 : 어떤 숫자가 (1~100)가 짝수면 1 홀수면 0을 출력하는 프로그램
section .text
global CMAIN
CMAIN:
    ;write your code here
    GET_DEC 1, ax ; 입력
    mov bl, 2
    div bl
    mov al, ah ;al은 나머지 저장, 1이면 홀수 
    
    cmp al, 1 ;나머지가 1이므로 홀수
    je IS_ODD
    
    mov rcx, 1
    jmp IS_EVEN

IS_ODD:
    mov rcx, 0 ;홀수면 0출력할 것, rcx를 출력할 것이고 rcx에 0 넣음
IS_EVEN:
    PRINT_HEX 1, rcx
    
    
    xor rax, rax
    ret