#pragma once
#include <wx/wx.h>


#define SIZE_MULTIPLIER   4
#define BTN_AMOUNT        6
#define APP_FONT          wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true)


class Frame : public wxFrame {
private:
	wxListBox *log_box;

	const std::string BTN_LABELS[BTN_AMOUNT] = { "+", "-", "x", "/", "^", "MOD" };
	enum BTN_IDS {
		ADD_BTN_ID = 10000,
		SUB_BTN_ID,
		MUL_BTN_ID,
		DIV_BTN_ID,
		POW_BTN_ID,
		MOD_BTN_ID
	};

	wxTextCtrl *txt_in[2];

	double nums[2];

	bool parseInputs();

	void addBtnClicked(wxCommandEvent &event);
	void subBtnClicked(wxCommandEvent &event);
	void mulBtnClicked(wxCommandEvent &event);
	void divBtnClicked(wxCommandEvent &event);
	void powBtnClicked(wxCommandEvent &event);
	void modBtnClicked(wxCommandEvent &event);
public:
	Frame();
	~Frame();

	wxDECLARE_EVENT_TABLE();
};
