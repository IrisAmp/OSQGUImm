/*----------------------------------------------------------------------------
		Main Window
	Defines the main window for the application.
----------------------------------------------------------------------------*/
#ifndef __OSQGUIMM_MAINWINDOW_H_DEFINED__
#define __OSQGUIMM_MAINWINDOW_H_DEFINED__


#include "constants.h"
#include "dimensions.h"
#include "helper.h"
#include "maintextview.h"


class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();

	// Signal Handlers
	void create_conn_settings_window();
	void create_setpoints_window();

	void on_help();
	void on_help_about();

	void on_control_safe();
	void on_control_sticky();

	void on_control_q();
	void on_control_w();
	void on_control_e();
	void on_control_a();
	void on_control_s();
	void on_control_d();

private:
	// Auxiliary
	void create_controls_table();

	// Child Widgets
	Gtk::VBox m_boxV0;
	Gtk::HBox m_boxH0, m_boxH1, m_boxH2;
	Gtk::ToggleButton m_button0, m_button1, m_button2, m_button3;
	Gtk::HSeparator m_separator;
	Gtk::Frame m_frame_textview, m_frame_controlbuttons;
	Gtk::Alignment m_alignment;
	MainTextView m_textview;

	// Controls Table
	Gtk::Table m_table;
	Gtk::Button m_control_w, m_control_a,
	            m_control_s, m_control_d,
	            m_control_q, m_control_e,
	            m_control_z, m_control_x,
	            m_control_c, m_control_esd;
	Gtk::Image m_img_up, m_img_down, m_img_left, m_img_right,
	           m_img_rol, m_img_ror, m_img_asc, m_img_desc,
			   m_img_stable, m_img_esd;

	// Menus
	Glib::RefPtr<Gtk::UIManager> m_refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup, m_refControlGroup;
	Glib::RefPtr<Gtk::CheckMenuItem> m_refSafe, m_refSticky;
};


#endif//__OSQGUIMM_MAINWINDOW_H_DEFINED__