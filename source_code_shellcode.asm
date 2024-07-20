
.data
.code

	main proc
	sub rsp,64
	mov rbx,60H
	mov rsi,gs:[rbx]
	add rsi,24
	mov rsi,[rsi];ldr
	add rsi,32
	mov rsi,[rsi];ldr.inmemory
	mov rsi,[rsi]
	mov r11,rsi
	add r11,32 
	mov r11,[r11];ntdl.dll
	mov rsi,[rsi]
	add rsi,32
	mov r13,[rsi] ;kernel32.dll
	
	
	
	;exit_thread_string:
	;	call get_exit_thread
	;	db "GetCurrentThread",0
	;get_exit_thread:
	;pop rdx
	;call GetProcessAddress
	;mov r14,rax
	;call get_terminate_thread
	;	db "TerminateThread",0
	;get_terminate_thread:
	;pop rdx
	;call GetProcessAddress
	;mov r12,rax
	;next:
	;xchg r13,r11
	get_std_handle_string:
		call std_handle
		db "GetStdHandle",0
	std_handle:
	pop rdx
	call GetProcessAddress
	mov r8,rax

	write_console_a_string:
		call write_console
		db "WriteConsoleA",0
	write_console:
	pop rdx
	call GetProcessAddress
	mov r15,rax

	mov rbp,rsp
	add rbp,30
	mov r13,rbp
	mov rsi,rbp
	mov rcx,26
	mov bl,'A'
	init_string:
		mov [rsi],bl
		inc rsi
		inc bl
		loop init_string
	mov rcx,-11
	call r8
	mov rcx,rax
	mov rdx,r13
	mov r8,26
	mov r9,0H
	push 0H
	call r15
	pop rbx
	add rsp,64
	;mov rcx,r14
	;mov rdx,0
	;call r12
	xor rax,rax
	ret
	main endp

	GetProcessAddress proc
	xor rax,rax
	mov eax,[r13+3Ch]
	mov eax,[r13+rax+88H]
	add rax,r13
	xor r9,r9
	mov r9d,[rax+18H]
	xor rbx,rbx
	mov ebx,[rax+20H]
	add rbx,r13
	again:
	dec r9d
	jz finish
	xor rsi,rsi
	mov esi,[rbx+r9*4]
	add rsi,r13
	mov rdi,rdx
	run:
		mov cl,[rdi]
		cmp cl,[rsi]
		jne again
		inc rdi
		inc rsi
		cmp byte ptr[rdi],0
		jne run
	xor rbx,rbx
	mov ebx,[rax+24H]
	add rbx,r13
	xor rcx,rcx
	mov cx,[rbx+2*r9]
	mov ebx,[rax+1CH]
	add rbx,r13
	xor rax,rax
	mov eax,[rbx+4*rcx]
	add rax,r13
	ret
	finish:
		mov rax,0
		ret
GetProcessAddress endp
end