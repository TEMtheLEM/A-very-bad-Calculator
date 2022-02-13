#pragma once
#include <wx/wx.h>


class Main : public wxApp {
public:
	Main();
	~Main();
	virtual bool OnInit();
};

wxIMPLEMENT_APP(Main);
