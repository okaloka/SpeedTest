#include <windows.h>

typedef void (*InitializeSpeedhack)(float speed);

int main() {
    // Carregar a DLL
    HINSTANCE hDLL = LoadLibrary("speedhack-i386.dll");

    if (hDLL != NULL) {
        // Obter o endereço da função
        InitializeSpeedhack initSpeedhack = (InitializeSpeedhack)GetProcAddress(hDLL, "InitializeSpeedhack");

        if (initSpeedhack != NULL) {
            // Chamar a função com a velocidade desejada
            initSpeedhack(2.0f);
        }

        // Liberar a DLL após o uso (opcional)
        FreeLibrary(hDLL);
    }

    return 0;
}
