%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
;분기문(if) : 특정 조건에 따라서 코드 흐름을 제어
;스킬 버튼을 눌렀는가? ==> 스킬 사용
;제한 시간 내에 던전 입장 수락 버튼을 눌렀는가? ==> YES --> 입장, NO --> 던전 취소
    
    ;cmp dat, src (dat가 기준)
    ;비교를 한 결과물은 flag register에 저장 
    
    ;JMP, [label] 시리즈 JUMP의 의미 무조건 가!
    ;JE : JumpEqual 같으면 JUMP
    ;JNE jump not equals
    ;JG :JumpGreater
    ;JGE Jump greater equals
    ;JL
    ;JLE 등등
    
    ;/*두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램 작성 */
    mov rax, 10
    mov rbx, 10
    
    cmp rax, rbx
    je LABEL_EQUAL
    
    mov rcx, 0
    jmp LABEL_EQUAL_END
    NEWLINE
    
LABEL_EQUAL: ;ZF --> zero flag가 켜져 있으면 이쪽으로 온다.
    mov rcx, 1
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
;연습 문제 : 어떤 숫자가 (1~100)가 짝수면 1 홀수면 0을 출력하는 프로그램
;나누기 연산 ah 레지스터 활
    
    
    
    xor rax, rax
    ret