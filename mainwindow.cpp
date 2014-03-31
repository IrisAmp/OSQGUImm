#include "stdafx.h"
#include "mainwindow.h"

MainWindow::MainWindow()
	:	m_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER, 0.0, 0.0),
		m_table(3, 3, true),
		m_img_up(Gtk::Stock::GO_UP, Gtk::ICON_SIZE_BUTTON),
		m_img_left(Gtk::Stock::GO_BACK, Gtk::ICON_SIZE_BUTTON),
		m_img_right(Gtk::Stock::GO_FORWARD, Gtk::ICON_SIZE_BUTTON),
		m_img_down(Gtk::Stock::GO_DOWN, Gtk::ICON_SIZE_BUTTON),
		m_img_rol(Gtk::Stock::MEDIA_REWIND, Gtk::ICON_SIZE_BUTTON),
		m_img_ror(Gtk::Stock::MEDIA_FORWARD, Gtk::ICON_SIZE_BUTTON),
		m_img_asc(Gtk::Stock::GOTO_TOP, Gtk::ICON_SIZE_BUTTON),
		m_img_desc(Gtk::Stock::GOTO_BOTTOM, Gtk::ICON_SIZE_BUTTON),
		m_img_stable(Gtk::Stock::HELP, Gtk::ICON_SIZE_BUTTON),
		m_img_esd(Gtk::Stock::DIALOG_WARNING, Gtk::ICON_SIZE_DIALOG)
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
		("HelpMenu", "Help"),
		sigc::mem_fun(*this, &MainWindow::on_help));
	m_refActionGroup->add( Gtk::Action::create
		("HelpAbout", Gtk::Stock::HELP),
		sigc::mem_fun(*this, &MainWindow::on_help_about));
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
		/*	Controls Table
		====================================================================*/
		m_boxV0.pack_start(m_boxH2, Gtk::PACK_SHRINK);
			m_boxH2.pack_start(m_control_esd, Gtk::PACK_SHRINK);
			m_control_esd.set_image(m_img_esd);
			m_control_esd.show();
			m_boxH2.pack_start(m_alignment, Gtk::PACK_SHRINK);
				m_alignment.add(m_table);
				create_controls_table();
				m_table.show();
				m_table.show_all_children();
			m_boxH2.show();
		m_alignment.show();
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

void MainWindow::on_help()
{

}

void MainWindow::on_help_about()
{

}

void MainWindow::on_control_safe()
{

}

void MainWindow::on_control_sticky()
{

}

void MainWindow::on_control_q()
{

}

void MainWindow::on_control_w()
{

}

void MainWindow::on_control_e()
{

}

void MainWindow::on_control_a()
{

}

void MainWindow::on_control_s()
{

}

void MainWindow::on_control_d()
{
	
}

void MainWindow::create_controls_table()
{
	m_table.attach(m_control_q, 0, 1, 0, 1);
	m_control_q.set_image(m_img_rol);
	m_control_q.set_tooltip_text("Rotate Left");
	m_table.attach(m_control_w, 1, 2, 0, 1);
	m_control_w.set_image(m_img_up);
	m_control_w.set_tooltip_text("Move Foreword");
	m_table.attach(m_control_e, 2, 3, 0, 1);
	m_control_e.set_image(m_img_ror);
	m_control_e.set_tooltip_text("Rotate Right");
	m_table.attach(m_control_a, 0, 1, 1, 2);
	m_control_a.set_image(m_img_left);
	m_control_a.set_tooltip_text("Move Left");
	m_table.attach(m_control_s, 1, 2, 1, 2);
	m_control_s.set_image(m_img_down);
	m_control_s.set_tooltip_text("Move Back");
	m_table.attach(m_control_d, 2, 3, 1, 2);
	m_control_d.set_image(m_img_right);
	m_control_d.set_tooltip_text("Move Right");
	m_table.attach(m_control_z, 0, 1, 2, 3);
	m_control_z.set_image(m_img_asc);
	m_control_z.set_tooltip_text("Ascend");
	m_table.attach(m_control_x, 1, 2, 2, 3);
	m_control_x.set_image(m_img_stable);
	m_control_x.set_tooltip_text("Stabilize");
	m_table.attach(m_control_c, 2, 3, 2, 3);
	m_control_c.set_image(m_img_desc);
	m_control_c.set_tooltip_text("Descend");
}
