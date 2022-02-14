#include "Frame.h"


wxBEGIN_EVENT_TABLE(Frame, wxFrame)
EVT_BUTTON(ADD_BTN_ID, Frame::addBtnClicked)
EVT_BUTTON(SUB_BTN_ID, Frame::subBtnClicked)
EVT_BUTTON(MUL_BTN_ID, Frame::mulBtnClicked)
EVT_BUTTON(DIV_BTN_ID, Frame::divBtnClicked)
EVT_BUTTON(POW_BTN_ID, Frame::powBtnClicked)
EVT_BUTTON(MOD_BTN_ID, Frame::modBtnClicked)
wxEND_EVENT_TABLE()


Frame::Frame() : wxFrame(NULL, wxID_ANY, "A very bad GUI Calculator", wxPoint(30, 80), wxSize(800, 500)) {
	// Create operation buttons
	wxButton *add_btn = new wxButton(this, ADD_BTN_ID, "+");
	wxButton *sub_btn = new wxButton(this, SUB_BTN_ID, "-");
	wxButton *mul_btn = new wxButton(this, MUL_BTN_ID, "x");
	wxButton *div_btn = new wxButton(this, DIV_BTN_ID, "/");
	wxButton *pow_btn = new wxButton(this, POW_BTN_ID, "^");
	wxButton *mod_btn = new wxButton(this, MOD_BTN_ID, "MOD");

	// Set button fonts
	wxFont btn_font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true);
	add_btn->SetFont(btn_font);
	sub_btn->SetFont(btn_font);
	mul_btn->SetFont(btn_font);
	div_btn->SetFont(btn_font);
	pow_btn->SetFont(btn_font);
	mod_btn->SetFont(btn_font);

	// Log output
	log_box = new wxListBox(this, LOG_BOX_ID, wxDefaultPosition);

	// Master grid (takes up entire application)
	wxGridSizer *full_grid = new wxGridSizer(2, 1, wxSize(0, 0));

	full_grid->Add(log_box, 1, wxEXPAND | wxALL, 10);

	wxGridSizer *inputs = new wxGridSizer(2, 1, wxSize(0, 0));

	wxGridSizer *num_inputs = new wxGridSizer(1, 2, wxSize(0, 0));
	txt1_in = new wxTextCtrl(this, wxID_ANY, "");
	txt2_in = new wxTextCtrl(this, wxID_ANY, "");
	txt1_in->SetFont(btn_font);
	txt2_in->SetFont(btn_font);
	num_inputs->Add(txt1_in, 1, wxEXPAND | wxALIGN_CENTER | wxALL, 4);
	num_inputs->Add(txt2_in, 1, wxEXPAND | wxALIGN_CENTER | wxALL, 4);

	wxGridSizer *btn_grid = new wxGridSizer(2, 3, wxSize(0, 0));

	btn_grid->Add(add_btn, 1, wxEXPAND | wxALL, 4);
	btn_grid->Add(sub_btn, 1, wxEXPAND | wxALL, 4);
	btn_grid->Add(mul_btn, 1, wxEXPAND | wxALL, 4);
	btn_grid->Add(div_btn, 1, wxEXPAND | wxALL, 4);
	btn_grid->Add(pow_btn, 1, wxEXPAND | wxALL, 4);
	btn_grid->Add(mod_btn, 1, wxEXPAND | wxALL, 4);

	inputs->Add(num_inputs, 1, wxEXPAND | wxALL, 4);
	inputs->Add(btn_grid, 1, wxEXPAND | wxALL, 4);

	full_grid->Add(inputs, 1, wxEXPAND | wxALL, 4);
	this->SetSizer(full_grid);
}


bool Frame::parseInputs() {
	if (!txt1_in->GetValue().ToDouble(&num1)) {
		wxMessageBox("Bad 1st number!", "Bad number", wxICON_WARNING | wxOK);
		return false;
	}
	if (!txt2_in->GetValue().ToDouble(&num2)) {
		wxMessageBox("Bad 2nd number!", "Bad number", wxICON_WARNING | wxOK);
		return false;
	}

	return true;
}

void Frame::addBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%lf", num1+num2));
}
void Frame::subBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%lf", num1-num2));
}
void Frame::mulBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%lf", num1*num2));
}
void Frame::divBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%lf", num1/num2));
}
void Frame::powBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%lf", pow(num1, num2)));
}
void Frame::modBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%ld", ((long)num1 % (long)num2)));
}
