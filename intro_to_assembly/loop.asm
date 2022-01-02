%include "io64.inc"
;반복문 --> 특정 조건을 만족할때까지 반복해서 실행
section .text
global CMAIN
CMAIN:
    ;write your code here
    mov ecx, 10
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx ;decrease ecx == sub ecx, 1
    
    cmp ecx,0
    jne LABEL_LOOP
    
    PRINT_STRING endMsg
    NEWLINE
    
    
    
    xor rax, rax
    ret

section .data
msg db 'HELLO WORLD', 0x00
endMsg db 'Loop END', 0x00