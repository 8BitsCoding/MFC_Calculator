
// MFCApplication4Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4Dlg 대화 상자



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication4Dlg::OnBnClickedOk)
	ON_COMMAND_RANGE(IDC_BUTTON_1, IDC_BUTTON_9, OnSetNum)
	ON_COMMAND_RANGE(IDC_OP_ADD, IDC_OP_DIVI, OnSetOP)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CMFCApplication4Dlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_OP_BACK, &CMFCApplication4Dlg::OnBnClickedOpBack)
	ON_BN_CLICKED(IDC_OP_EQU, &CMFCApplication4Dlg::OnBnClickedOpEqu)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 메시지 처리기

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_font.CreatePointFont(240, L"굴림");
	GetDlgItem(IDC_SHOW_EDIT)->SetFont(&m_font);

	SetDlgItemInt(IDC_SHOW_EDIT, 0);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
}

void CMFCApplication4Dlg::OnSetNum(UINT a_ctrl_id)
{
	int num = GetDlgItemInt(IDC_SHOW_EDIT);

	if (m_reset_mode == 0) {
		SetDlgItemInt(IDC_SHOW_EDIT, a_ctrl_id - IDC_BUTTON_0 + num * 10);
	}
	else {
		m_reset_mode = 0;
		SetDlgItemInt(IDC_SHOW_EDIT, a_ctrl_id - IDC_BUTTON_0);
	}
	
}


void CMFCApplication4Dlg::OnBnClickedClearButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	SetDlgItemInt(IDC_SHOW_EDIT, 0);
}

void CMFCApplication4Dlg::OnSetOP(UINT a_ctrl_id)
{
	if (m_reset_mode == 0) {
		m_op_flag = a_ctrl_id - IDC_OP_ADD + 1;
		m_reset_mode = 1;
		m_num = GetDlgItemInt(IDC_SHOW_EDIT);
	}
}

void CMFCApplication4Dlg::OnBnClickedOpBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = GetDlgItemInt(IDC_SHOW_EDIT) / 10;
	SetDlgItemInt(IDC_SHOW_EDIT, num);
}


void CMFCApplication4Dlg::OnBnClickedOpEqu()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int second_num = GetDlgItemInt(IDC_SHOW_EDIT);
	int result = 0;

	switch (m_op_flag) {
	case 1 :		// +
		result = m_num + second_num;
		break;
	case 2:		// -
		result = m_num - second_num;
		break;
	case 3:		// *
		result = m_num * second_num;
		break;
	case 4:		// /
		if(second_num != 0)
			result = m_num / second_num;
		break;
	}

	SetDlgItemInt(IDC_SHOW_EDIT, result);
	m_reset_mode = 1;
}
