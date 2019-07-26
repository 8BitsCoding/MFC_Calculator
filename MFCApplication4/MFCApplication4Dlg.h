
// MFCApplication4Dlg.h: 헤더 파일
//

#pragma once


// CMFCApplication4Dlg 대화 상자
class CMFCApplication4Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void OnSetNum(UINT a_ctrl_id);
	CFont m_font;
	afx_msg void OnBnClickedClearButton();
	void OnSetOP(UINT a_ctrl_id);
	afx_msg void OnBnClickedOpBack();
	char m_op_flag = 0;	// 0 -> 연산자 선택 없음 , 1 -> +, 2 -> - , 3 -> *, 4 -> /
	char m_reset_mode = 0;
	int m_num = 0;
	afx_msg void OnBnClickedOpEqu();
};
