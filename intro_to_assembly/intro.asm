%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;8 bit = 1 byte
    ;16 bit = 2 byte = 1 word
    ;32 bit = 4 byte = 2 word = 1 dword
    ;64 bit = 8 byte = 1 qword (quad word)
    ; mov reg1, const
    ; mov reg1, reg2 (load into reg1)
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    mov al, 0x00
    GET_DEC 1, al ;decimal로 입력받는다
    GET_DEC 1, num
    
    
    PRINT_DEC 1, al
    NEWLINE
    PRINT_DEC 1, num
    ;메모리에는 구분할 수 있도록 주소(번지수)가 있음
    ;mov rax, a ;이렇게 하면 주소값이 rax에 들어간다. (값이 들어가는게 아님)
    ;더하기
    ;add a, b ;a = a + b // a는 레지스터 또는 메모리 b는 레지스터 또는 메모리 또는 상수, 단 a,b 모두 메모리는 x
    add al, 1;레지스터 + 상수
    NEWLINE
    PRINT_DEC 1, al
    NEWLINE
    
    mov rax, [num]
    add al, [num] ;값을 더해야한다. num만 쓰면 주소를 뜻함...
    PRINT_DEC 1, al
    NEWLINE
    
    mov bl, 3 ;레지스터 + 레지스터
    add al, bl
    PRINT_DEC 1, al
    NEWLINE

    add [num], byte 1;상수를 더할때는 크기를 지정해줘야함. 메모리 + 상수
    PRINT_DEC 1, [num]
    NEWLINE 
    
    add [num], al;메모리 + 레지스터
    PRINT_DEC 1, [num]
    NEWLINE 
    
    ;메모리 + 메모리 는 안됨
    
    ;곱하기 연산 <-- 연산 비용이 크다
    ;mul reg
    ;mul bl --> al * bl : 연산 결과를 ax에 저장
    ;mul bx => ax * bx
    ;연산 결과는 dx 상위 16비트 ax 하위 16비트에 저장
    ;mul ebx => eax * ebx
    
    ; 5 * 8
    mov ax,0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    ;나누기 연산
    ;div reg
    ;div bl => ax / bl : 연산 결과는 al에 몫을 ah에는 나머지 
    ;ex) 100 / 3은? ==> 몫 33, 나머지 1
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al
    NEWLINE
    mov al, ah
    PRINT_DEC 1, al ;ah는 PRINT_DEC 안됨. 
    
    mov al, [a] ;이렇게 해야 값이 들어간다.
    
    mov [a], byte 0x55 
    mov [a], word 0x6666
    mov [a], cl 
    
    xor rax, rax
    ret
    ;변수 선언 및 사용
    ;변수는 데이터를 저장하는 바구니
    ; 처음에 바구니를 사용하겠다고 선언해야하는데 이 때 이름과 크기를 지정한다.
    
    
section .data
    ;초기화된 데이터 사용
    ;[변수이름] [크기] [초기값]
    ;[크기] db{1} dw(2) dd(4) dq(8)
    a db 0x11, 0x11, 0x11
     
    
section .bss
    ;변수이름 크기 개수
    ;초기화 되지 않은 데이터 --> resb resw resd resq ==> 1 2 4 8
    num resb 1
    
