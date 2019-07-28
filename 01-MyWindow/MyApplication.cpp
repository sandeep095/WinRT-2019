#include<Windows.h> // Master header file.

// Declare CALLBACK Function
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int iCmdShow) // Entry Point Function
{
	// Variable Declaration

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[]=TEXT("MyApplication");


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
		TEXT("My Application"), 
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
	switch(iMsg)
	{
		// Compulsory Case
		case WM_DESTROY :
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam)); // All other messages are returned to OS
}



