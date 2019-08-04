#include<Windows.h> // Master header file.

// Declare CALLBACK Function
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int iCmdShow) // Entry Point Function
{
	// Variable Declaration

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[]=TEXT("PledgeApp");


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
		TEXT("Pledge Application"), 
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
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	//TCHAR str []=TEXT("भारत माझा देश आहे. सारे भारतीय माझे बांधव आहेत. माझ्या देशावर माझे प्रेम आहे. माझ्या देशातल्या समृद्ध आणि विविधतेने नटलेल्या परंपरांचा मला अभिमान आहे. त्या परंपरांचा पाईक होण्याची पात्रता माझ्या अंगी यावी म्हणून मी सदैव प्रयत्न करीन. मी माझ्या पालकांचा, गुरुजनांचा आणि वडीलधार्‍या माणसांचा मान ठेवीन आणि प्रत्येकाशी सौजन्याने वागेन. माझा देश आणि माझे देशबांधव यांच्याशी निष्ठा राखण्याची मी प्रतिज्ञा करीत आहे. त्यांचे कल्याण आणि त्यांची समृद्धी ह्यांतच माझे सौख्य सामावले आहे.");
	TCHAR pledge []=TEXT("**PLEDGE**");
	TCHAR pledge1 []=TEXT("India is my country.");
	TCHAR pledge2 []=TEXT("All Indians are my Brothers and Sisters.");
	TCHAR pledge3 []=TEXT("I love my country");
	TCHAR pledge4 []=TEXT("and I am proud of its rich and varied heritage.");
	TCHAR pledge5 []=TEXT("I shall always strive to be worthy of it.");
	TCHAR pledge6 []=TEXT("I shall give my parents, teachers and all elders");
	TCHAR pledge7 []=TEXT("respect and treat everyone with courtesy.");
	TCHAR pledge8 []=TEXT("To my country and my people,");
	TCHAR pledge9 []=TEXT("I pledge my devotion.");
	TCHAR pledge10 []=TEXT("In their well being and");
	TCHAR pledge11 []=TEXT("prosperity alone, lies my happiness.");
	TCHAR pledge12 []=TEXT("Jai Hind !!!");

	TCHAR circle1 [] =TEXT("strive");
	TCHAR circle2 [] =TEXT("parents, teachers");
	TCHAR circle3 [] =TEXT("treat everyone");
	TCHAR circle4 [] =TEXT("country and");

	switch(iMsg)
	{
		case WM_CREATE :
		break;

		case WM_PAINT :

			//GetClientRect(hwnd,&rc);
			hdc = BeginPaint(hwnd,&ps);
			SetTextColor(hdc,RGB(255,125,0));
			SetBkColor(hdc,RGB(0,0,0));
			SetTextAlign(hdc,TA_CENTER);




			//DrawText(hdc,str,-1,&rc,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			TextOut(hdc,500,	50,	pledge1,wcslen(pledge1));
			TextOut(hdc,500,	70,	pledge2,wcslen(pledge2));
			TextOut(hdc,500,	90,	pledge3,wcslen(pledge3));
			TextOut(hdc,500,	110,	pledge4,wcslen(pledge4));
			
			SetTextColor(hdc,RGB(255,255,255));
			TextOut(hdc,500,	130,	pledge5,wcslen(pledge5));
			TextOut(hdc,500,	150,	pledge6,wcslen(pledge6));
			TextOut(hdc,500,	170,	pledge7,wcslen(pledge7));
			TextOut(hdc,500,	190,	pledge8,wcslen(pledge8));

			SetTextColor(hdc,RGB(0,255,0));
			TextOut(hdc,500,	210,	pledge9,wcslen(pledge9));
			TextOut(hdc,500,	230,	pledge10,wcslen(pledge10));
			TextOut(hdc,500,	250,	pledge11,wcslen(pledge11));
			TextOut(hdc,500,	270,	pledge12,wcslen(pledge12));

			SetTextColor(hdc,RGB(0,0,255));
			TextOut(hdc,490,	130,	circle1,wcslen(circle1));
			TextOut(hdc,505,	150,	circle2,wcslen(circle2));
			TextOut(hdc,492,	170,	circle3,wcslen(circle3));
			TextOut(hdc,485,	190,	circle4,wcslen(circle4));

			SetTextColor(hdc,RGB(255,255,255));
			TextOut(hdc,500,	10,	pledge,wcslen(pledge));
			EndPaint(hwnd,&ps);
			break;

		// Compulsory Case
		case WM_DESTROY :
			PostQuitMessage(0);
			break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam)); // All other messages are returned to OS
}



