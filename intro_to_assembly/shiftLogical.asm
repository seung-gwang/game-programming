%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;쉬프트 연산, 논리 연산
    
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    ;곱셈, 나눗셈 2^n로 할때 바르게
    ;게임 서버에서 objectID를 만들 때, 각 비트가 몬스터인지 유저인지 등을 나타낼 수 있는데 이를 이동시킬 때 간편하게 사용 가능함.
    
    mov al, 0b10010101
    mov bl, 0b01111100
    ; and --> 0001 0100 ==> 0x14
    and al, bl; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    not al
    PRINT_HEX 1, al
    NEWLINE
    ;응용 사례: bitflag
    ;논리 연산 not and or xor
    ;xor 둘다 1이거나 둘다 0이면 0 ==> 아니면 1... 즉 서로 다르면 참
    NEWLINE
    mov al, 0b10010101
    mov bl, 0b01111100
    
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al ;==>XOR을 두번하면 자기 자신으로 되돌아옴: 암호학에서 유용하게 사용.
    NEWLINE
     
    xor rax, rax ;결과는 무조건 0이 나올것임 속도도 빠름 good. mov rax,0 보다 빠르다. rax에 0을 넣는것은 정상 종료를 의미.
    ret