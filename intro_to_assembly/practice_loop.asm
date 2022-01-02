%include "io64.inc"
;1~100숫자 합 구하기==> 1+2+3+4+....+100
section .text
global CMAIN
CMAIN:
    ;write your code here
    mov eax, 1
    xor ebx, ebx ;ebx == 0
    
SUM:
    add ebx, eax
    inc eax
    cmp eax, 101
    jne SUM

PRINT_DEC 1, ebx
NEWLINE
    ; loop [라벨]
    ;ecx에 반복 횟수
    ;loop 할때마다 ecx 감소 0이면 빠져나감, 아니면 라벨로 이동.
    mov ecx, 100
    xor eax, eax
LABEL_LOOP_SUM:
    add eax, ecx
    loop LABEL_LOOP_SUM ;이렇게 할 수도 있음
    
PRINT_DEC 1, eax


    xor rax, rax
    ret