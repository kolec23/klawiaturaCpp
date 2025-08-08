#include <windows.h>
#include <string>
LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;
HWND g_literki[36]; // uchwyt na litery alfabetu
HWND g_wynik;

std::string napis="";
void wypisz_litere(std::string a);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    // WYPEŁNIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
                       
    // REJESTROWANIE KLASY OKNA
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
            MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }

    // TWORZENIE OKNA
    HWND hwnd;

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, "Oto okienko", WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, 355, 210, NULL, NULL, hInstance, NULL);
	g_wynik=CreateWindowEx( 0, "STATIC" ,NULL,WS_CHILD | WS_VISIBLE |SS_CENTER, 10, 10, 480, 20, hwnd, NULL, hInstance, NULL );
	g_literki[0]=CreateWindowEx(0, "BUTTON", "A", WS_CHILD | WS_VISIBLE, 20, 50, 25,25, hwnd, NULL, hInstance, NULL);
	g_literki[1]=CreateWindowEx(0, "BUTTON", "B", WS_CHILD| WS_VISIBLE, 50,50,25,25, hwnd, NULL, hInstance, NULL);
	g_literki[2]=CreateWindowEx(0, "BUTTON", "C", WS_CHILD | WS_VISIBLE, 80,50, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[3]=CreateWindowEx(0, "BUTTON", "D", WS_CHILD | WS_VISIBLE, 110, 50, 25,25, hwnd, NULL, hInstance, NULL);
	g_literki[4]=CreateWindowEx(0, "BUTTON", "E", WS_CHILD | WS_VISIBLE, 140, 50, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[5]=CreateWindowEx(0, "BUTTON", "F", WS_CHILD | WS_VISIBLE, 170, 50, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[6]=CreateWindowEx(0, "BUTTON", "G", WS_CHILD | WS_VISIBLE, 200, 50, 25,25, hwnd, NULL, hInstance, NULL);
	g_literki[7]=CreateWindowEx(0, "BUTTON", "H", WS_CHILD | WS_VISIBLE, 230,50, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[8]=CreateWindowEx(0, "BUTTON", "I", WS_CHILD | WS_VISIBLE, 260, 50, 25,25, hwnd, NULL, hInstance, NULL);
	g_literki[9]=CreateWindowEx(0, "BUTTON", "J" , WS_CHILD | WS_VISIBLE, 290, 50, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[10]=CreateWindowEx(0, "BUTTON", "K", WS_CHILD | WS_VISIBLE, 20, 80, 25,25, hwnd, NULL, hInstance, NULL);
	g_literki[11]=CreateWindowEx(0, "BUTTON", "L", WS_CHILD | WS_VISIBLE, 50, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[12]=CreateWindowEx(0, "BUTTON", "M", WS_CHILD | WS_VISIBLE, 80, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[13]=CreateWindowEx(0, "BUTTON", "N", WS_CHILD | WS_VISIBLE, 110, 80, 25, 25, hwnd, NULL, hInstance , NULL);
	g_literki[14]=CreateWindowEx(0, "BUTTON", "O", WS_CHILD | WS_VISIBLE, 140, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[15]=CreateWindowEx(0, "BUTTON", "P", WS_CHILD | WS_VISIBLE, 170, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[16]=CreateWindowEx(0, "BUTTON", "Q", WS_CHILD | WS_VISIBLE, 200, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[17]=CreateWindowEx(0, "BUTTON", "R", WS_CHILD | WS_VISIBLE, 230, 80, 25, 25, hwnd,NULL, hInstance, NULL);
	g_literki[18]=CreateWindowEx(0, "BUTTON", "S", WS_CHILD | WS_VISIBLE, 260, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[19]=CreateWindowEx(0, "BUTTON", "T", WS_CHILD | WS_VISIBLE, 290, 80, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[20]=CreateWindowEx(0, "BUTTON", "U", WS_CHILD | WS_VISIBLE, 20, 110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[21]=CreateWindowEx(0, "BUTTON", "V", WS_CHILD | WS_VISIBLE, 50, 110,25,25, hwnd, NULL,hInstance, NULL);
	g_literki[22]=CreateWindowEx(0, "BUTTON", "W", WS_CHILD | WS_VISIBLE, 80, 110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[23]=CreateWindowEx(0, "BUTTON", "X", WS_CHILD | WS_VISIBLE, 110, 110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[24]=CreateWindowEx(0, "BUTTON", "Y", WS_CHILD | WS_VISIBLE, 140, 110, 25,25, hwnd,NULL, hInstance, NULL);
	g_literki[25]=CreateWindowEx(0, "BUTTON", "Z", WS_CHILD | WS_VISIBLE, 170, 110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[26]=CreateWindowEx(0, "BUTTON", "0", WS_CHILD | WS_VISIBLE, 200,110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[27]=CreateWindowEx(0, "BUTTON", "1", WS_CHILD | WS_VISIBLE, 230, 110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[28]=CreateWindowEx(0, "BUTTON", "2", WS_CHILD | WS_VISIBLE, 260, 110, 25, 25, hwnd,NULL, hInstance, NULL);
	g_literki[29]=CreateWindowEx(0, "BUTTON", "3", WS_CHILD | WS_VISIBLE, 290, 110, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[30]=CreateWindowEx(0, "BUTTON", "4",  WS_CHILD | WS_VISIBLE, 80, 140, 25,25, hwnd, NULL, hInstance, NULL);
	g_literki[31]=CreateWindowEx(0, "BUTTON", "5", WS_CHILD | WS_VISIBLE, 110, 140, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[32]=CreateWindowEx(0, "BUTTON", "6", WS_CHILD | WS_VISIBLE, 140,140, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[33]=CreateWindowEx(0, "BUTTON", "7", WS_CHILD | WS_VISIBLE, 170, 140, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[34]=CreateWindowEx(0, "BUTTON", "8", WS_CHILD | WS_VISIBLE, 200, 140, 25, 25, hwnd, NULL, hInstance, NULL);
	g_literki[35]=CreateWindowEx(0, "BUTTON", "9", WS_CHILD | WS_VISIBLE, 230, 140, 25, 25, hwnd, NULL, hInstance, NULL);
	
	if( hwnd == NULL )
    {
        MessageBox(NULL, "Okno odmówiło przyjścia na świat!", "Ale kicha...", MB_ICONEXCLAMATION);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow); // Pokaż okienko...
    UpdateWindow(hwnd);

    // Pętla komunikatów
    while (GetMessage(&Komunikat, NULL, 0, 0))
    {
        TranslateMessage(&Komunikat);
        DispatchMessage(&Komunikat);
    }                     
    return Komunikat.wParam;
}
           
// OBSŁUGA ZDARZEŃ
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

	case WM_COMMAND:
		{
			
			for(int i=0; i<36; i++)
			{
				char c=' ';
				//rzutowanie liter
				if(i<=25)
				{
					 c='A'+i;
					
				}
				else
				{
					//rzutowanie cyfr
					switch(i)
					{
						case 26: c='0'; break;
						case 27: c='1'; break;
						case 28: c='2'; break;
						case 29: c='3'; break;
						case 30: c='4'; break;
						case 31: c='5'; break;
						case 32: c='6'; break;
						case 33: c='7'; break;
						case 34: c='8'; break;
						case 35: c='9'; break;
						default: c=' '; break;
					}
					
				}
				
				if((HWND)lParam==g_literki[i])
					{
						napis+=c;
						SetWindowText(g_wynik, napis.c_str());
					}
			}
		}
		break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}