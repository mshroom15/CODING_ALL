.model small
.stack 100h

.data
msg1 db 'Enter Input :', '$'
CRLF db 0Dh, 0Ah , '$'
even db 'EVEN' , '$'
odd db  'ODD', '$'

.code
 main proc
    mov ax, @data
    mov ds, ax
    xor cx, cx            
    xor si, si
    xor bx, bx

    mov ah, 09h
    lea dx, msg1
    int 21h

read:
    mov ah, 01h
    int 21h
    
    cmp al, 0Dh         
    je read_end

    sub al, '0'
    mov ah, 0

    mov si, ax
    mov ax, bx

    mov dx ,10
    mul dx
    mov bx, ax

    add bx , si

    jmp read

read_end:
    mov ax, bx
    mov cx , 02h
    div cx
    cmp dx , 00h
    je EVEN_num

    mov ah, 09h
    lea dx, CRLF
    int 21h
    mov ah, 09h
    lea dx, odd
    int 21h
    jmp print
    

EVEN_num:    
    
    mov ah, 09h
    lea dx, CRLF
    int 21h
    mov ah, 09h
    lea dx, even
    int 21h
    jmp print

print:
    mov ax, bx
    mov cx, 0
    mov bx , 10
devide:
    xor dx, dx
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne devide
    
    mov ah, 09h
    lea dx, CRLF
    int 21h
    
print_loop:
    pop dx
    add dl , '0'
    mov ah, 02h
    int 21h
    
    loop print_loop
exit:
    mov ah, 4Ch
    int 21h
 main endp
 end main