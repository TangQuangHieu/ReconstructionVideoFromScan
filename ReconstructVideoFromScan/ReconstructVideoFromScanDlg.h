
// ReconstructVideoFromScanDlg.h : header file
//

#pragma once
#include "StitchImage.h"

// CReconstructVideoFromScanDlg dialog
class CReconstructVideoFromScanDlg : public CDialogEx
{
// Construction
public:
	CReconstructVideoFromScanDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECONSTRUCTVIDEOFROMSCAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Show Log File
	CListBox m_lbLog;
	void AddLog(LPCTSTR szMsg, ...);


	void OpenFolder();
	void LoadImageListPath();
	CString m_cstrImagePath;
	//function used for initilize properly list box, if the path of text in list box is too lenghthy, we make the horizontal scrool bar to that text

	StitchImage m_StitchImage;


	int m_StartStitchPos;
	int m_StopStitchPos;

private:
	void OnReDrawHorizontalScroolBar();
public:
	afx_msg void OnBnClickedButtonOpen();
	CListBox m_hImageList;
	afx_msg void OnBnClickedButtonRectifyBlackBorder();
	afx_msg void OnBnClickedButtonStitchImages();
	afx_msg void OnLbnSelchangeListImage();
	afx_msg void OnBnClickedButtonStartStitchPos();
	afx_msg void OnBnClickedButtonStopStitchPos();
	afx_msg void OnBnClickedButtonOpenStitchImage();
	afx_msg void OnBnClickedButtonRetifyGreenColumn();
	afx_msg void OnBnClickedButtonDetectNewFrame();
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnBnClickedButtonWriteImage();
	afx_msg void OnBnClickedButtonRunOptimize();
	afx_msg void OnBnClickedButtonDecodeTiff();
};
