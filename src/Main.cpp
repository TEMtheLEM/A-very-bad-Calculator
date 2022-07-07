/**
 * Main.cpp - Application init code.
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


#include "Main.h"
#include "Frame.h"
#include <string>


std::string Main::GetAppDirLoc() {
	// If, for whatever reason, there is no base command (i.e /path/to/Calculator).
	if (!argc) {
		wxPrintf("No command available.\n");
		exit(2);
	}

	// Get the current working directory.
	std::string cmd(argv[0]),
	            base = cmd.substr(0, cmd.find_last_of("/"));

	return base + "/../";
}

bool Main::OnInit() {
	// Get the current working directory.
	std::string app_dir = GetAppDirLoc();

	Frame *frame = new Frame();
	frame->SetMinSize(wxSize(400, 400));
	frame->SetIcon(wxIcon(wxString::Format("%s/res/img/icon.png", app_dir), wxBITMAP_TYPE_PNG));
	frame->Show();

	return true;
}
