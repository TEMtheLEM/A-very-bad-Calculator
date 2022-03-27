#include "Frame.h"
#include <vector>


wxBEGIN_EVENT_TABLE(Frame, wxFrame)
EVT_BUTTON(ADD_BTN_ID, Frame::addBtnClicked)
EVT_BUTTON(SUB_BTN_ID, Frame::subBtnClicked)
EVT_BUTTON(MUL_BTN_ID, Frame::mulBtnClicked)
EVT_BUTTON(DIV_BTN_ID, Frame::divBtnClicked)
EVT_BUTTON(POW_BTN_ID, Frame::powBtnClicked)
EVT_BUTTON(MOD_BTN_ID, Frame::modBtnClicked)
wxEND_EVENT_TABLE()


Frame::Frame() : wxFrame(NULL, wxID_ANY, "A very bad GUI Calculator", wxPoint(60, 180), wxSize(800, 500)) {
	// Master grid (takes up entire application)
	wxGridSizer *full_grid = new wxGridSizer(2, 1, wxSize(0, 0));

	// Log output
	log_box = new wxListBox(this, wxID_ANY);
	full_grid->Add(log_box, 1, wxEXPAND | wxALL, SIZE_MULTIPLIER * 3);

	// Inputs; 2 text boxes for our numbers and a few buttons for operations.
	wxGridSizer *inputs = new wxGridSizer(2, 1, wxSize(0, 0));

	// 2 text inputs for our numbers.
	wxGridSizer *num_inputs = new wxGridSizer(1, 2, wxSize(0, 0));
	for (int i = 0; i < 2; i++) {
		wxTextCtrl *num_in = new wxTextCtrl(this, wxID_ANY, "");
		num_in->SetFont(APP_FONT);
		num_inputs->Add(num_in, 1, wxEXPAND | wxALIGN_CENTER | wxALL, SIZE_MULTIPLIER);
		txt_in[i] = num_in;
	}

	// Operational buttons.
	wxGridSizer *btn_grid = new wxGridSizer(2, 3, wxSize(0, 0));
	for (int i = 0; i < BTN_AMOUNT; i++) {
		wxButton *btn = new wxButton(this, 10000+i, BTN_LABELS[i]);
		btn->SetFont(APP_FONT);
		btn_grid->Add(btn, 1, wxEXPAND | wxALL, SIZE_MULTIPLIER);
	}

	// Add buttons and text fields to inputs.
	inputs->Add(num_inputs, 1, wxEXPAND | wxALL, SIZE_MULTIPLIER);
	inputs->Add(btn_grid, 1, wxEXPAND | wxALL, SIZE_MULTIPLIER);

	// Finally add inputs to application, then set the grid in the application.
	full_grid->Add(inputs, 1, wxEXPAND | wxALL, SIZE_MULTIPLIER);
	this->SetSizer(full_grid);
}


Frame::~Frame() {
	for (auto &&item : txt_in)
		delete item;
	delete log_box;
}

bool Frame::parseInputs() {
	std::vector<short> failed {};

	for (int i = 0; i < 2; i++) {
		if (!txt_in[i]->GetValue().ToDouble(&nums[i]))
			failed.push_back(i+1);
	}

	if (failed.size()) {
		std::string err_msg = "The following bad number(s) were given:\n";
		for (const short &ell : failed)
			err_msg += "\t- Number " + std::to_string(ell) + '\n';
		wxMessageBox(err_msg, "Bad number(s) given.", wxICON_ERROR);
		return false;
	}

	return true;
}

void Frame::addBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%.2lf", nums[0] + nums[1]));
}

void Frame::subBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%.2lf", nums[0] - nums[1]));
}

void Frame::mulBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%.2lf", nums[0] * nums[1]));
}

void Frame::divBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%.2lf", nums[0] / nums[1]));
}

void Frame::powBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%.2lf", pow(nums[0], nums[1])));
}

void Frame::modBtnClicked(wxCommandEvent &event) {
	if (parseInputs())
		log_box->AppendString(wxString::Format("%ld", ((long) nums[0] % (long) nums[1])));
}
