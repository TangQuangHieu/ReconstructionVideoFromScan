
// ReconstructVideoFromScanDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ReconstructVideoFromScan.h"
#include "ReconstructVideoFromScanDlg.h"
#include "afxdialogex.h"
#include "utilities.h"
#include <filesystem>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CReconstructVideoFromScanDlg dialog



CReconstructVideoFromScanDlg::CReconstructVideoFromScanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECONSTRUCTVIDEOFROMSCAN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReconstructVideoFromScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LOG, m_lbLog);
	DDX_Control(pDX, IDC_LIST_IMAGE, m_hImageList);
}

BEGIN_MESSAGE_MAP(CReconstructVideoFromScanDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CReconstructVideoFromScanDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_RECTIFY_BLACK_BORDER, &CReconstructVideoFromScanDlg::OnBnClickedButtonRectifyBlackBorder)
	ON_BN_CLICKED(IDC_BUTTON_STITCH_IMAGES, &CReconstructVideoFromScanDlg::OnBnClickedButtonStitchImages)
	ON_LBN_SELCHANGE(IDC_LIST_IMAGE, &CReconstructVideoFromScanDlg::OnLbnSelchangeListImage)
	ON_BN_CLICKED(IDC_BUTTON_START_STITCH_POS, &CReconstructVideoFromScanDlg::OnBnClickedButtonStartStitchPos)
	ON_BN_CLICKED(IDC_BUTTON_STOP_STITCH_POS, &CReconstructVideoFromScanDlg::OnBnClickedButtonStopStitchPos)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_STITCH_IMAGE, &CReconstructVideoFromScanDlg::OnBnClickedButtonOpenStitchImage)
	ON_BN_CLICKED(IDC_BUTTON_RETIFY_GREEN_COLUMN, &CReconstructVideoFromScanDlg::OnBnClickedButtonRetifyGreenColumn)
	ON_BN_CLICKED(IDC_BUTTON_DETECT_NEW_FRAME, &CReconstructVideoFromScanDlg::OnBnClickedButtonDetectNewFrame)
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CReconstructVideoFromScanDlg::OnBnClickedButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_WRITE_IMAGE, &CReconstructVideoFromScanDlg::OnBnClickedButtonWriteImage)
	ON_BN_CLICKED(IDC_BUTTON_RUN_OPTIMIZE, &CReconstructVideoFromScanDlg::OnBnClickedButtonRunOptimize)
	ON_BN_CLICKED(IDC_BUTTON_DECODE_TIFF, &CReconstructVideoFromScanDlg::OnBnClickedButtonDecodeTiff)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CReconstructVideoFromScanDlg message handlers

BOOL CReconstructVideoFromScanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CReconstructVideoFromScanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReconstructVideoFromScanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CReconstructVideoFromScanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CReconstructVideoFromScanDlg::AddLog(LPCTSTR szMsg, ...)
{
	TCHAR buffer[4096];
	int timeLen = 22;
	memcpy(buffer, (LPCTSTR)CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S : "), timeLen);

	va_list args;
	va_start(args, szMsg);
	_vstprintf(buffer + timeLen, szMsg, args); //wvsprintf
	va_end(args);
	int nStrLen = strlen(buffer);
	buffer[nStrLen] = '\n';
	buffer[nStrLen + 1] = '\0';
	nStrLen++;

	//printf("%s", buffer);
	//TTRACEF(buffer);
	//if (m_bLog)
	{
		if (m_lbLog.GetCount() > 10000)
		{
			m_lbLog.ResetContent();
		}
		m_lbLog.AddString(buffer);
		m_lbLog.SetCurSel(m_lbLog.GetCount() - 1);
	}
	//FILE* fp = fopen(strLogFilePath, "at");
	//fwrite(buffer, 1, nStrLen, fp);
	//fclose(fp);
}

void CReconstructVideoFromScanDlg::OpenFolder()
{
	CString _ImageDir;
	//if (!m_open_folder)
	{
		GetDlgItemText(IDC_EDIT_IMAGE_PATH, _ImageDir);
		auto open_folder = CFolderPickerDialog("..\\data\\", OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_ENABLESIZING, this,
			sizeof(OPENFILENAME));
		//Check whether the default image dir exist, if so, initial the opening search dialog by that 
		if (MgIsDirectoryExists(_ImageDir))
		{
			open_folder.m_ofn.lpstrInitialDir = _ImageDir;
		}
		else
		{
			open_folder.m_ofn.lpstrInitialDir = MgGetModuleFileDirectory();
		}
		CString cstrOldFolder = open_folder.GetPathName();
		open_folder.DoModal();
		SetDlgItemText(IDC_EDIT_IMAGE_PATH, open_folder.GetPathName());
		m_cstrImagePath = open_folder.GetPathName();
		LoadImageListPath();
		m_StitchImage.SetImagePath(std::string(m_cstrImagePath+"_Out"));
	}
}

void CReconstructVideoFromScanDlg::LoadImageListPath()
{
	CString _ImageDir;
	GetDlgItemText(IDC_EDIT_IMAGE_PATH, _ImageDir);
	if (MgIsDirectoryExists((LPCTSTR)_ImageDir))
	{
		namespace fs = std::filesystem;
		//Reset all old content
		m_hImageList.ResetContent();

		//If file is exist, open and get all jpg images inside folder, not recursive =.=
		for (const auto& entry : fs::directory_iterator(std::string(_ImageDir)))
		{
			//std::cout << entry.path() << std::endl;
			auto& pathfile = entry.path();
			if (pathfile.extension().compare(".jpg")==0  || 
				pathfile.extension().compare(".tiff")==0 ||
				pathfile.extension().compare(".bmp")==0) 
			{
				auto cstrImageName = pathfile.filename().string();
				m_hImageList.AddString(cstrImageName.c_str());
			}
		}
		OnReDrawHorizontalScroolBar();
	}
}

void CReconstructVideoFromScanDlg::OnReDrawHorizontalScroolBar()
{
	CString str;
	CSize sz;
	int dx = 0;
	CDC* pDC = m_hImageList.GetDC();
	for (int i = 0; i < m_hImageList.GetCount(); i++)
	{
		m_hImageList.GetText(i, str);
		sz = pDC->GetTextExtent(str);

		if (sz.cx > dx)
			dx = sz.cx;

	}
	m_hImageList.ReleaseDC(pDC);

	if (m_hImageList.GetHorizontalExtent() < dx)
	{
		m_hImageList.SetHorizontalExtent(dx);
		ASSERT(m_hImageList.GetHorizontalExtent() == dx);

	}
}




void CReconstructVideoFromScanDlg::OnBnClickedButtonOpen()
{
	// TODO: Add your control notification handler code here
	AddLog("[I].Open Image Folder ...");
	OpenFolder();
	AddLog("[I].Done.");
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonRectifyBlackBorder()
{
	// TODO: Add your control notification handler code here
	cv::Mat inputImage;
	for (int iImageIdx = 0; iImageIdx < m_hImageList.GetCount(); ++iImageIdx)
	{
		CString cstrCurrentImage;
		m_hImageList.GetText(iImageIdx, cstrCurrentImage);
		CString cstrFullPath; cstrFullPath.Format("%s\\%s", m_cstrImagePath, cstrCurrentImage);
		inputImage = cv::imread(std::string(cstrFullPath));
		AddLog("[I].Processing Image %s", cstrCurrentImage);
		//m_StitchImage.RectifyBlackBorder(inputImage, std::string(cstrCurrentImage));
	}
	AddLog("[I].Done!");
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonStitchImages()
{
	// TODO: Add your control notification handler code here
	int Cnt = 0;
	for (int iImageIdx = m_StartStitchPos; iImageIdx <=m_StopStitchPos; ++iImageIdx,++Cnt)
	{
		CString cstrCurrentImage;
		m_hImageList.GetText(iImageIdx, cstrCurrentImage);
		CString cstrFullPath; cstrFullPath.Format("%s\\%s", m_StitchImage.GetImagePath().c_str(), cstrCurrentImage);
		AddLog("[I].Stitching Image %s", cstrCurrentImage);
		cv::Mat inputImage = cv::imread(std::string(cstrFullPath));
	/*	if (Cnt == 0)
		{
			m_StitchImage.SetFirstImage(inputImage);
		}
		else
		{
			m_StitchImage.Stitch2Images(m_StitchImage.GetImageResult(), inputImage,false);
		}*/
	}
	//m_StitchImage.WriteResult("Image_Stitch.tiff");
	AddLog("[I].Done!");
}

void CReconstructVideoFromScanDlg::OnLbnSelchangeListImage()
{
	// TODO: Add your control notification handler code here
	CString cstrCurrentImage;
	m_hImageList.GetText(m_hImageList.GetCurSel(), cstrCurrentImage);
	CString cstrFullPath; GetDlgItemText(IDC_EDIT_IMAGE_PATH, cstrFullPath); cstrFullPath.Format("%s\\%s", cstrFullPath, cstrCurrentImage);
	cv::Mat inputImage = cv::imread(std::string(cstrFullPath));
	if (!inputImage.empty())
	{
		cv::namedWindow("Preview", 0);
		cv::imshow("Preview", inputImage);
		cv::waitKey(1);
	}
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonStartStitchPos()
{
	// TODO: Add your control notification handler code here
	m_StartStitchPos = m_hImageList.GetCurSel();
	SetDlgItemInt(IDC_EDIT_START_STITCH_POS, m_StartStitchPos);
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonStopStitchPos()
{
	// TODO: Add your control notification handler code here
	m_StopStitchPos = m_hImageList.GetCurSel();
	SetDlgItemInt(IDC_EDIT_STOP_STITCH_POS, m_StopStitchPos);

}


void CReconstructVideoFromScanDlg::OnBnClickedButtonOpenStitchImage()
{
	// TODO: Add your control notification handler code here
	cv::namedWindow("Stitch Image", 0);
	cv::imshow("Stitch Image", m_StitchImage.GetImageResult());
	cv::waitKey(1);
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonRetifyGreenColumn()
{
	// TODO: Add your control notification handler code here
	CString cstrCurrentImage;
	m_hImageList.GetText(0, cstrCurrentImage);
	CString cstrFullPath; cstrFullPath.Format("%s\\%s", m_cstrImagePath, cstrCurrentImage);
	cv::Mat inputImage = cv::imread(std::string(cstrFullPath));
	AddLog("[I].Processing Image %s", cstrCurrentImage);
	//m_StitchImage.RectifyDeepBlueColumns(inputImage, std::string(cstrFullPath));
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonDetectNewFrame()
{
	// TODO: Add your control notification handler code here
	CString cstrCurrentImage;
	m_hImageList.GetText(0, cstrCurrentImage);
	CString cstrFullPath; cstrFullPath.Format("%s\\%s", m_cstrImagePath, cstrCurrentImage);
	cv::Mat inputImage = cv::imread(std::string(cstrFullPath));
	AddLog("[I].Processing Image %s", cstrCurrentImage);
	//m_StitchImage.DetectNewFrame(inputImage, true);
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonRun()
{
	// TODO: Add your control notification handler code here
	CString cstrImagePath; GetDlgItemText(IDC_EDIT_IMAGE_PATH, cstrImagePath);
	CString cstrImageOutPath; cstrImageOutPath.Format("%s_Out", cstrImagePath);
	m_StitchImage.Run(std::string(cstrImagePath), std::string(cstrImageOutPath));
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonWriteImage()
{
	// TODO: Add your control notification handler code here
	AddLog("[I].Writting stitched Image.");
	m_StitchImage.WriteResult(m_StitchImage.GetImageResult(),"Image_Stitch.tiff");
	AddLog("[I].Done!");
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonRunOptimize()
{
	// TODO: Add your control notification handler code here
	CString cstrImagePath; GetDlgItemText(IDC_EDIT_IMAGE_PATH, cstrImagePath);
	AddLog("[I].Processing folder ...%s", cstrImagePath);
	CString cstrImageOutPath; cstrImageOutPath.Format("%s_Out", cstrImagePath);
	CString cstrIntermediatePath; cstrIntermediatePath.Format("%s_Inter", cstrImagePath);
	m_StitchImage.DecodeTiff(std::string(cstrImagePath), std::string(cstrIntermediatePath));
	m_StitchImage.RunOptimize(std::string(cstrIntermediatePath), std::string(cstrImageOutPath));
	SetDlgItemText(IDC_EDIT_IMAGE_PATH, cstrImageOutPath);
	LoadImageListPath();
	AddLog("[I].Done!");
	
}


void CReconstructVideoFromScanDlg::OnBnClickedButtonDecodeTiff()
{
	// TODO: Add your control notification handler code here
	//AddLog("[I].Decoding Tiff...");
	//m_StitchImage.DecodeTiff("..\\data\\in\\", "..\\data\\out\\");
	//AddLog("[I].Done!");
	
}

void CReconstructVideoFromScanDlg::OnDestroy()
{
	cv::destroyAllWindows();
	cv::waitKey(1);
}
