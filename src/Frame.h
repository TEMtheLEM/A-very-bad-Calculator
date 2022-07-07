/**
 * Frame.h - Template file for application frame.
 * Copyright (C) 2022  Connor Inch  <conninch@protonmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#define   SIZE_MULTIPLIER   4
#define   BTN_AMOUNT        6
#define   APP_FONT          wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true)


class Frame : public wxFrame {
private:
	enum BTN_IDS {
		ADD_BTN_ID = 10000,
		SUB_BTN_ID,
		MUL_BTN_ID,
		DIV_BTN_ID,
		POW_BTN_ID,
		MOD_BTN_ID
	};

	const std::string BTN_LABELS[BTN_AMOUNT] = { "+", "-", "x", "/", "^", "MOD" };
	wxListBox *log_box;
	wxTextCtrl *txt_in[2];
	double nums[2];

	bool parseInputs();
	void onOppBtnClick(wxCommandEvent &event);
public:
	Frame();
	~Frame();

	wxDECLARE_EVENT_TABLE();
};
