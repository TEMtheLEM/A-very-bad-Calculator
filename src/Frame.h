#pragma once
#include <wx/wx.h>


class Frame : public wxFrame {
private:
	wxListBox *log_box;

	wxTextCtrl *txt1_in, *txt2_in;

	double num1, num2;

	bool parseInputs();

	void addBtnClicked(wxCommandEvent &event);
	void subBtnClicked(wxCommandEvent &event);
	void mulBtnClicked(wxCommandEvent &event);
	void divBtnClicked(wxCommandEvent &event);
	void powBtnClicked(wxCommandEvent &event);
	void modBtnClicked(wxCommandEvent &event);
public:
	Frame();

	wxDECLARE_EVENT_TABLE();
};

enum IDS {
	ADD_BTN_ID = 10000,
	SUB_BTN_ID,
	MUL_BTN_ID,
	DIV_BTN_ID,
	POW_BTN_ID,
	ROOT_BTN_ID,
	MOD_BTN_ID,
	EQ_BTN_ID,
	LOG_BOX_ID
};
