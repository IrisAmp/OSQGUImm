/*----------------------------------------------------------------------------
		OSQGUImm
	The entry point for the application.
----------------------------------------------------------------------------*/
#include "stdafx.h"
#include "nsafx.h"


int main(int argc, char* argv[])
{
	// Initialize GTK
	Gtk::Main kit(argc, argv);

	// Create the main window
    MainWindow window;

	// Run GTK
    Gtk::Main::run(window);
    
	// Everything's gravy.
    return 0;
}