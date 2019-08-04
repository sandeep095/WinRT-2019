#include<Windows.h> // Master header file.

// Declare CALLBACK Function
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int iCmdShow) // Entry Point Function
{
	// Variable Declaration

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[]=TEXT("ColorScreenApp");


	// initialization of WNDCLASSEX

	wndclass.cbSize=sizeof(WNDCLASSEX);                            // Size
	wndclass.style=CS_HREDRAW | CS_VREDRAW;						  //  Window Style
	wndclass.cbClsExtra=0;										  // Extra Information about Class
	wndclass.cbWndExtra=0;                                        // Extra Information about Window
	wndclass.lpfnWndProc=WndProc;								  //Assigning  address of our Callback function
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);				  // We dont have our own icon.So that we are using  default.
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);				  // We dont have our own Cursor.So that we are using  default.	
	wndclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);   
	wndclass.lpszClassName=szAppName;
	wndclass.lpszMenuName=NULL;
	wndclass.hIconSm=LoadIcon(NULL,IDI_APPLICATION);



	//Register our class

	RegisterClassEx(&wndclass);


	//Create window
	hwnd=CreateWindow(szAppName,
		TEXT("COLOR SCREEN BY PRESSING KEYS "), 
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);


	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);


	//Message Loop

	while(GetMessage(&msg,NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);

}

// CALLBACK Function
LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP hBitmap;
	HDC hdc;
	HDC mhdc;//memory hdc
	PAINTSTRUCT ps;
	RECT rc;
	//TCHAR str []=TEXT("Color Screen !!!");
	TCHAR sMsgBox[255];
	
	static int iPaintFlag;
	HBRUSH hBrush;

	HINSTANCE hInstance;
	BITMAP bitmap;
	int i;

	switch(iMsg)
	{
		case WM_CREATE :
			
			//hInstance=((LPCREATESTRUCT)lParam)->hInstance;
			//hInstance=GetModuleHandle(NULL);
			
			

			//wsprintf(sMsgBox,TEXT("WM_CREATE is arrived..."));
			//MessageBox(hwnd,sMsgBox,TEXT("Message"),MB_OK | MB_ICONINFORMATION);

		break;

		case WM_CHAR :

			switch(wParam)
			{
			case 'R':
			case 'r':
				iPaintFlag=1;
			i = InvalidateRect(hwnd,NULL,true);

			break;

			case 'G':
			case 'g':
				iPaintFlag=2;
				InvalidateRect(hwnd,NULL,true);
				break;

			case 'B':
			case 'b':
				iPaintFlag=3;
				InvalidateRect(hwnd,NULL,true);
				break;

			case 'C':
			case 'c':
				iPaintFlag=4;
				InvalidateRect(hwnd,NULL,true);
				break;

			case 'M':
			case 'm':
				iPaintFlag=5;
				InvalidateRect(hwnd,NULL,true);
				break;
			case 'Y':
			case 'y':
				iPaintFlag=6;
				InvalidateRect(hwnd,NULL,true);
				break;
			case 'W':
			case 'w':
				iPaintFlag=7;
				InvalidateRect(hwnd,NULL,true);
				break;
			case 'K':
			case 'k':
				iPaintFlag=8;
				InvalidateRect(hwnd,NULL,true);
				break;

			default:
				iPaintFlag=8;
				InvalidateRect(hwnd,NULL,true);
				break;

			}
				break;
		/*case WM_KEYDOWN :
				wsprintf(sMsgBox,TEXT("WM_KEYDOWN is arrived..."));
				MessageBox(hwnd,sMsgBox,TEXT("Message"),MB_OK | MB_ICONINFORMATION);
			break;

		case WM_LBUTTONDOWN :
				wsprintf(sMsgBox,TEXT("WM_LBUTTONDOWN is arrived..."));
				MessageBox(hwnd,sMsgBox,TEXT("Message"),MB_OK | MB_ICONINFORMATION);
			break;*/
		case WM_PAINT :

			GetClientRect(hwnd,&rc);
			hdc = BeginPaint(hwnd,&ps);


			switch(iPaintFlag)
			{
			case 1:
				hBrush=CreateSolidBrush(RGB(255,0,0));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
			break;

			case 2 :
				hBrush=CreateSolidBrush(RGB(0,255,0));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			case 3 :
				hBrush=CreateSolidBrush(RGB(0,0,255));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			case 4 :
				hBrush=CreateSolidBrush(RGB(0,255,255));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			case 5 :
				hBrush=CreateSolidBrush(RGB(255,0,255));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			case 6 :
				hBrush=CreateSolidBrush(RGB(255,255,0));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			case 7 :
				hBrush=CreateSolidBrush(RGB(255,255,255));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			case 8 :
				hBrush=CreateSolidBrush(RGB(0,0,0));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			default:
				hBrush=CreateSolidBrush(RGB(0,0,0));
				SelectObject(hdc,hBrush);
				FillRect(hdc,&rc,hBrush);
				break;
			}	

			EndPaint(hwnd,&ps);
			break;

		// Compulsory Case
		case WM_DESTROY :
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam)); // All other messages are returned to OS
}
