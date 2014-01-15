#ifndef _EXAMPLEWINDOW_H_
#define _EXAMPLEWINDOW_H_

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow (void);
	~ExampleWindow() = default;

protected:
	Gtk::TreeModelColumn<int>           m_col_id;
	Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	Gtk::TreeModelColumn<int>           m_col_number;
	Gtk::TreeModelColumn<int>           m_col_percentage;
	Gtk::TreeModelColumn<Glib::ustring> m_col_suffix;

	Gtk::TreeModel::ColumnRecord m_Columns;

	Gtk::Box m_Box;
	Gtk::TreeView m_TreeView;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

	void on_row_activated (const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* col);
};

#endif // _EXAMPLEWINDOW_H_

