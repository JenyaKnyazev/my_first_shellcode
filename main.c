#include <windows.h>
int main() {
	void* mem;
	DWORD p;
	unsigned char shellcode[292] = {
	0x48, 0x83, 0xEC, 0x40, 0x48, 0xC7, 0xC3, 0x60, 0x00, 0x00, 0x00, 0x65,
	0x48, 0x8B, 0x33, 0x48, 0x83, 0xC6, 0x18, 0x48, 0x8B, 0x36, 0x48, 0x83,
	0xC6, 0x20, 0x48, 0x8B, 0x36, 0x48, 0x8B, 0x36, 0x4C, 0x8B, 0xDE, 0x49,
	0x83, 0xC3, 0x20, 0x4D, 0x8B, 0x1B, 0x48, 0x8B, 0x36, 0x48, 0x83, 0xC6,
	0x20, 0x4C, 0x8B, 0x2E, 0xE8, 0x0D, 0x00, 0x00, 0x00, 0x47, 0x65, 0x74,
	0x53, 0x74, 0x64, 0x48, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x00, 0x5A, 0xE8,
	0x6A, 0x00, 0x00, 0x00, 0x4C, 0x8B, 0xC0, 0xE8, 0x0E, 0x00, 0x00, 0x00,
	0x57, 0x72, 0x69, 0x74, 0x65, 0x43, 0x6F, 0x6E, 0x73, 0x6F, 0x6C, 0x65,
	0x41, 0x00, 0x5A, 0xE8, 0x4E, 0x00, 0x00, 0x00, 0x4C, 0x8B, 0xF8, 0x48,
	0x8B, 0xEC, 0x48, 0x83, 0xC5, 0x1E, 0x4C, 0x8B, 0xED, 0x48, 0x8B, 0xF5,
	0x48, 0xC7, 0xC1, 0x1A, 0x00, 0x00, 0x00, 0xB3, 0x41, 0x88, 0x1E, 0x48,
	0xFF, 0xC6, 0xFE, 0xC3, 0xE2, 0xF7, 0x48, 0xC7, 0xC1, 0xF5, 0xFF, 0xFF,
	0xFF, 0x41, 0xFF, 0xD0, 0x48, 0x8B, 0xC8, 0x49, 0x8B, 0xD5, 0x49, 0xC7,
	0xC0, 0x1A, 0x00, 0x00, 0x00, 0x49, 0xC7, 0xC1, 0x00, 0x00, 0x00, 0x00,
	0x6A, 0x00, 0x41, 0xFF, 0xD7, 0x5B, 0x48, 0x83, 0xC4, 0x40, 0x48, 0x33,
	0xC0, 0xC3, 0x48, 0x33, 0xC0, 0x41, 0x8B, 0x45, 0x3C, 0x41, 0x8B, 0x84,
	0x05, 0x88, 0x00, 0x00, 0x00, 0x49, 0x03, 0xC5, 0x4D, 0x33, 0xC9, 0x44,
	0x8B, 0x48, 0x18, 0x48, 0x33, 0xDB, 0x8B, 0x58, 0x20, 0x49, 0x03, 0xDD,
	0x41, 0xFF, 0xC9, 0x74, 0x3F, 0x48, 0x33, 0xF6, 0x42, 0x8B, 0x34, 0x8B,
	0x49, 0x03, 0xF5, 0x48, 0x8B, 0xFA, 0x8A, 0x0F, 0x3A, 0x0E, 0x75, 0xE8,
	0x48, 0xFF, 0xC7, 0x48, 0xFF, 0xC6, 0x80, 0x3F, 0x00, 0x75, 0xEF, 0x48,
	0x33, 0xDB, 0x8B, 0x58, 0x24, 0x49, 0x03, 0xDD, 0x48, 0x33, 0xC9, 0x66,
	0x42, 0x8B, 0x0C, 0x4B, 0x8B, 0x58, 0x1C, 0x49, 0x03, 0xDD, 0x48, 0x33,
	0xC0, 0x8B, 0x04, 0x8B, 0x49, 0x03, 0xC5, 0xC3, 0x48, 0xC7, 0xC0, 0x00,
	0x00, 0x00, 0x00, 0xC3
	};
	mem = VirtualAlloc(0, 292, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	RtlMoveMemory(mem, shellcode, 292);
	VirtualProtect(mem, 292, PAGE_EXECUTE_READ, &p);
	CreateThread(0, 292, mem, 0, 0, 0);
	//WaitForSingleObject(CreateThread(0, 0, mem, 0, 0, 0), -1);
	Sleep(5000);
	return 0;
}