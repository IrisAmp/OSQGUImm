#include "stdafx.h"
#include "mainwindow.h"

MainWindow::MainWindow()
	:	m_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER),
		m_table(2, 3, true),
		m_control_w(Gtk::Stock::GO_UP),
		m_control_a(Gtk::Stock::GO_BACK),
		m_control_s(Gtk::Stock::GO_DOWN),
		m_control_d(Gtk::Stock::GO_FORWARD)
{
	// Set up the cosmetics.
	set_size_request(MAIN_WINDOW_HEIGHT * PHI, MAIN_WINDOW_HEIGHT);
	set_border_width(5);


	// Set up menus
	m_refActionGroup = Gtk::ActionGroup::create();
	/*	Edit
	========================================================================*/
	m_refActionGroup->add(Gtk::Action::create
		("EditMenu", "Edit"));
	m_refActionGroup->add(Gtk::Action::create
		("EditConn", "Connection Settings"),
		Gtk::AccelKey("<control>C"),
		sigc::mem_fun(*this, &MainWindow::create_conn_settings_window));
	m_refActionGroup->add(Gtk::Action::create
		("EditSetP", "Edit Default Setpoints"),
		Gtk::AccelKey("<control>S"),
		sigc::mem_fun(*this, &MainWindow::create_setpoints_window));
	//------------------------------------------------------------------------
	/*	Help
	========================================================================*/
	m_refActionGroup->add( Gtk::Action::create
		("HelpMenu", "Help") );
	m_refActionGroup->add( Gtk::Action::create
		("HelpAbout", Gtk::Stock::HELP),
          sigc::mem_fun(*this, &MainWindow::on_help_about) );
	//------------------------------------------------------------------------
	m_refUIManager = Gtk::UIManager::create();
	m_refUIManager->insert_action_group(m_refActionGroup);

	add_accel_group(m_refUIManager->get_accel_group());
	Glib::ustring ui_info = 
		"<ui>"
		"	<menubar name='Menu'>"
		"		<menu action='EditMenu'>"
		"			<menuitem action='EditConn'/>"
		"			<menuitem action='EditSetP'/>"
		"		</menu>"
        "		<menu action='HelpMenu'>"
        "			<menuitem action='HelpAbout'/>"
        "		</menu>"
        "	</menubar>"
        "</ui>";

	try
	{
		m_refUIManager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex)
	{
		std::cerr << "building menus failed: " <<  ex.what();
	}


	// Set up window
	/*	Vertical Stacker
	========================================================================*/
	Gtk::Widget* pMenubar = m_refUIManager->get_widget("/Menu");
	if(pMenubar) m_boxV0.pack_start(*pMenubar, Gtk::PACK_SHRINK);
	pMenubar -> show();
	//------------------------------------------------------------------------
	/*	Vertical Stacker
	========================================================================*/
	add(m_boxV0);
	m_boxV0.set_homogeneous(false);
		/*	TextView Frame
		====================================================================*/
		m_boxV0.pack_start(m_frame_textview);
		m_frame_textview.set_label("Info");
		m_frame_textview.set_shadow_type(Gtk::ShadowType::SHADOW_ETCHED_OUT);
			/*	TextView
			================================================================*/
			m_frame_textview.add(m_textview);
			m_textview.add_to_buffer("-------------------------------------------------------------------------------\n", false);
			m_textview.add_to_buffer("\tWelcome to the OSQGUI\n", false);
			m_textview.add_to_buffer("-------------------------------------------------------------------------------\n", false);
			m_textview.add_to_buffer("(i) The system is initializing.\n");
			m_textview.show();
			//----------------------------------------------------------------
		m_frame_textview.show();
		//--------------------------------------------------------------------
		/*	Horizontal Separator
		====================================================================*/
		m_boxV0.pack_start(m_separator, Gtk::PACK_SHRINK);
		m_separator.show();
		//--------------------------------------------------------------------
		/*	Row 1: Buttons
		====================================================================*/
		m_boxV0.pack_start(m_boxH0, Gtk::PACK_SHRINK);
		m_boxH0.set_homogeneous(true);
			/*	TextView Frame
			================================================================*/
			m_boxV0.pack_start(m_frame_controlbuttons, Gtk::PACK_SHRINK);
			m_frame_controlbuttons.set_label("Control Settings");
			m_frame_controlbuttons.set_shadow_type(Gtk::ShadowType::SHADOW_ETCHED_OUT);
			m_frame_controlbuttons.add(m_boxH1);
				/*	Button 0: Configure
				============================================================*/
				m_boxH1.pack_start(m_button0);
				m_button0.set_label("Safe");
				m_button0.show();
				//------------------------------------------------------------
				/*	Button 1: Settings
				============================================================*/
				m_boxH1.pack_start(m_button1);
				m_button1.set_label("Sticky");
				m_button1.show();
				//------------------------------------------------------------
			m_boxH1.show();
			m_frame_controlbuttons.show();
			//----------------------------------------------------------------
		m_boxH0.show();
		//--------------------------------------------------------------------
		/*	Controls Table
		====================================================================*/
		m_boxV0.pack_start(m_alignment, Gtk::PACK_SHRINK);
			m_alignment.add(m_table);
				m_table.attach(m_control_q, 0, 1, 0, 1);
				m_table.attach(m_control_w, 1, 2, 0, 1);
				m_table.attach(m_control_e, 2, 3, 0, 1);
				m_table.attach(m_control_a, 0, 1, 1, 2);
				m_table.attach(m_control_s, 1, 2, 1, 2);
				m_table.attach(m_control_d, 2, 3, 1, 2);
			m_table.show();
			m_table.show_all_children();
		m_alignment.show();
		//--------------------------------------------------------------------
	m_boxV0.show();
	//------------------------------------------------------------------------

	m_textview.add_to_buffer("(i) Initialization complete.\n");
}

MainWindow::~MainWindow()
{

}

void MainWindow::create_conn_settings_window()
{

}

void MainWindow::create_setpoints_window()
{

}

void MainWindow::on_control_safe()
{

}

void MainWindow::on_control_sticky()
{

}

void MainWindow::on_help_about()
{

}
