// cardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "card.h"
#include "cardDlg.h"
#include "Mwic_32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardDlg dialog

CCardDlg::CCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCardDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCardDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCardDlg, CDialog)
	//{{AFX_MSG_MAP(CCardDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardDlg message handlers

BOOL CCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCardDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCardDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCardDlg::OnButton1()   //连接卡片 初始化 
{

	// TODO: Add your control notification handler code here
	icdev = 	ic_init(0 , 9600 ) ; 
	if ( icdev < 0 ) {MessageBox("打开失败","连接卡片");return ;}
	st = turn_on(icdev) ; //对卡上电
	if ( st < 0 ) {MessageBox("打开失败","连接卡片"); return ; }

	MessageBox("打开成功","连接卡片");
}

void CCardDlg::OnButton2()    //断开连接
{
	//断开卡片
	
			GetDlgItemText(IDC_EDIT3,tempwrite,sizeof(tempwrite));   //从控件中得到用户要写入内容
		char temp[10] ; 
		temp[9] = '\0' ; 
		for ( int i = 8;i >= 0;i --) 
		{
			temp[i] = money % 10 ; 
			money /= 10 ; 
		}
			int len=strlen(temp);
			st = swr_4442(icdev, 10 , 10, (unsigned char*)tempwrite);  //写入数据
			if(st==0)
			{
			//	MessageBox("写入成功","",MB_OK);
			}
	else 
		//MessageBox("写入失败","",MB_OK);
	ic_exit(icdev); 
	turn_off(icdev);    
	MessageBox("再见~~！","断开卡片",MB_OK);	
}

void CCardDlg::OnButton3() 
{
	//密码核对
	char  key[10];
	GetDlgItemText(IDC_EDIT1,key,sizeof(key));
	//从控件中取得用户输入密码	
	int  st=csc_4442(icdev,3,(unsigned char *)key);          //密码核对
	if(st==0)
		MessageBox("你竟然知道密码！","",MB_OK);
	else 
		MessageBox("傻了吧！进不去了！","",MB_OK);
}

void CCardDlg::OnButton4() 
{
	//读数据
	unsigned char tempread[100];
	tempread[5]='\0';
	st=srd_4442(icdev, 0, 5, tempread);   //从设备指定地址中读取数据到知道缓冲区中
	if(st==0)
		{
		SetDlgItemText(IDC_EDIT2,(char *)tempread);
		}
	else 
		MessageBox("读取错误","读取",MB_OK);
}

void CCardDlg::OnButton5() 
{
//写数据
			GetDlgItemText(IDC_EDIT3,tempwrite,sizeof(tempwrite));   //从控件中得到用户要写入内容
			int len=strlen(tempwrite);
            if(len>5)
                MessageBox("名字长有用？5个字就够了！","");
            else
            {

			st = swr_4442(icdev, 0 , 5, (unsigned char*)tempwrite);  //写入数据
			if(st==0)
			{
				MessageBox("写入成功","",MB_OK);
			}
			else 
				MessageBox("写入失败","",MB_OK);
			}
}

void CCardDlg::OnButton6() 
{

	//发卡
	money = 0 ; 
	char tempchar[10] = "000000000";
	tempchar[9] = '\0' ; 
	unsigned char *tempwr=(unsigned char *)(LPCTSTR)tempwrite;
			st = swr_4442(icdev, 10, 10, tempwr);
			if(st==0)
				MessageBox("发卡成功","",MB_OK);
    
			else 
				MessageBox("发卡错误","",MB_OK);

  }


void CCardDlg::OnButton7() 
{
		char tempwrite[10] ; 
		GetDlgItemText(IDC_EDIT4,tempwrite,sizeof(tempwrite));   //从控件中得到用户要写入内容	
		
		if( (tempwrite[0]-'0') < 0 ||  (tempwrite[0] - '0') > 9)
               MessageBox("你想给我钱？","") ; 
		
		
		else{
		int k = 0 ,j = 10 ; 
		for ( int i = 0;i < strlen(tempwrite) ;i ++)
			k = k*10 + (tempwrite[i] - '0') ; 

		if ( k > money ) {
			MessageBox("你有那么多钱？逗！","") ; 
			return ; 
		}
		else{
		money -= k ;
		char cs[100] ; 
		sprintf(cs,"%d",money) ; 
		MessageBox(cs,"余额！！！！！！") ; }}
}

void CCardDlg::OnButton8() 
{
		char tempwrite[10] ; 
		GetDlgItemText(IDC_EDIT5,tempwrite,sizeof(tempwrite));   //从控件中得到用户要写入内容	
		//MessageBox(tempwrite,"") ; 
		//int k = 0 ,j = 10 ; 

        if( (tempwrite[0]-'0') < 0 ||  (tempwrite[0] - '0') > 9)
               MessageBox("你在充什么？！","") ; 
        else
		{
			MessageBox(tempwrite,"") ; 
	     	int k = 0 ,j = 10 ; 
			for ( int i = 0;i < strlen(tempwrite) ;i ++)
		     	k = k*10 + (tempwrite[i] - '0') ; 
		money += k ; 
		char cs[100] ; 
		sprintf(cs,"%d",money) ; 
		MessageBox(cs,"余额！！！") ; 
		}
}

void CCardDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
