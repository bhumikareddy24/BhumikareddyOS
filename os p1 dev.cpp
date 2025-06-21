#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    LPCSTR program = "C:\\Windows\\System32\\notepad.exe";

    
    if (!CreateProcess(
            NULL,         
            (LPSTR)program, 
            NULL,         
            NULL,         
            FALSE,        
            0,            
            NULL,         
            NULL,         
            &si,          
            &pi)          
        ) {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

    printf("New Process created!\n");
    printf("Process ID (PID): %lu\n", pi.dwProcessId);
    printf("Parent Process ID: (Not directly available in Windows API)\n");

    
    WaitForSingleObject(pi.hProcess, INFINITE);

    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

