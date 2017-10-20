#include <windows.h>

void Cheat()
{
    // Obtenemos el entry point
    DWORD entryPoint = (DWORD)GetModuleHandle(NULL);
    // Obtenemos la direccion del puntero estatico
    DWORD baseAddress = *(DWORD*)(entryPoint + 0x109B74);
    // Obtenemos la direccion donde se almacenan las balas
    DWORD bullets = baseAddress + 0x150;
    while (true)
    {
        // Asignamos el numero de balas
        *(DWORD*)bullets = 20;
        // Suspendemos la ejecución 200 milisegundos
        Sleep(200);
    }
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // Ejecutamos la función Cheat en un hilo
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Cheat, 0, 0, 0);
            break;

        case DLL_PROCESS_DETACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
