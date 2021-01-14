#include <win_kernel/utils.h>
#include <vmm/vmm.h>
#include <win_kernel/memory_manager.h>

VOID WinGetParameters(OUT QWORD_PTR params, IN BYTE count)
{
    PREGISTERS regs = &VmmGetVmmStruct()->guestRegisters;
    QWORD paramsStart = regs->rsp + 5 * sizeof(QWORD);
    switch(count)
    {
        case 17:
        case 16:
        case 15:
        case 14:
        case 13:
        case 12:
        case 11:
        case 10:
        case 9:
        case 8:
        case 7:
        case 6:
        case 5:
            WinMmCopyGuestMemory(params + 4, paramsStart, (count - 4) * sizeof(QWORD));
        case 4:
            params[3] = regs->r9;
        case 3:
            params[2] = regs->r8;
        case 2:
            params[1] = regs->rdx;
        case 1:
            params[0] = regs->rcx;
    }
}