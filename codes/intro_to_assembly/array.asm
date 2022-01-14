%include "io64.inc"
;배열 : 동일한 타입의 데이터 묶음
;각 요소는 element
;각각의 위치는 index


section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov rbp, rsp
    
    mov rax, a ;<-이러면 주소가 들어간다
    PRINT_HEX 1, [a] 
    NEWLINE
    PRINT_HEX 1, [a+1] 
    NEWLINE
    PRINT_HEX 1, [a+2] 
    NEWLINE
    
    
    ;/*a 배열의 모든 데이터 루프로 출력하기*/
    mov ecx, 0; ecx는 counter
PRINT_VAL_A:
    ;add rax, ecx
    ;PRINT_HEX 1, [rax]
    ;NEWLINE
    PRINT_HEX 1, [a+ecx]
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne PRINT_VAL_A

    xor ecx, ecx
PRINT_B:
    PRINT_HEX 1, [b+ecx*2]
    NEWLINE
    inc ecx
    cmp ecx,5
    jne PRINT_B
    
    
    xor rax, rax
    ret
    

section .data
    msg db 'Hello World', 0x00
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ;5 * 1 = 5바이트 
    b times 5 dw 1 ;5 * 2 = 10바이트
    
section .bss
    num resb 10;10개 바이트 10byte