#include <iostream>
#include "examplewindow.h"

ExampleWindow::ExampleWindow (void)
{
	m_Columns.add (m_col_id);
	m_Columns.add (m_col_name);
	m_Columns.add (m_col_number);
	m_Columns.add (m_col_percentage);
	m_Columns.add (m_col_suffix);

	m_refTreeModel = Gtk::ListStore::create (m_Columns);
	m_TreeView.set_model (m_refTreeModel);

	m_TreeView.signal_row_activated().connect (sigc::mem_fun (*this, &ExampleWindow::on_row_activated));
	m_TreeView.set_activate_on_single_click (true);

	Gtk::TreeModel::Row row;
	row = *(m_refTreeModel->append()); row[m_col_id] = 1; row[m_col_name] = "Billy"; row[m_col_number] = 10; row[m_col_percentage] =       15; row[m_col_suffix] = "M";
	row = *(m_refTreeModel->append()); row[m_col_id] = 2; row[m_col_name] = "Joey";  row[m_col_number] = 20; row[m_col_percentage] =     4000; row[m_col_suffix] = "WW";
	row = *(m_refTreeModel->append()); row[m_col_id] = 3; row[m_col_name] = "Rob";   row[m_col_number] = 30; row[m_col_percentage] = 70000000; row[m_col_suffix] = "MMM";

	m_TreeView.append_column         ("ID",     m_col_id);			// 0
	m_TreeView.append_column         ("Name",   m_col_name);		// 1
	m_TreeView.append_column_numeric ("Number", m_col_number, "%05d");	// 3
	m_TreeView.append_column         ("Hybrid", m_col_percentage);		// 2

	Gtk::TreeViewColumn* pColumn;

	pColumn = m_TreeView.get_column(3);
	pColumn->pack_end (m_col_suffix, false);
	pColumn->get_first_cell()->set_alignment(1.0, 0.5);
	pColumn->set_alignment (1.0);

	set_default_size (400, 150);
	add (m_Box);
	m_Box.pack_start (m_TreeView, false, false);
	show_all_children();
	move (960, 0);
}

void ExampleWindow::on_row_activated (const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* col)
{
	Gtk::TreeModel::iterator iter = m_refTreeModel->get_iter (path);
	if (iter) {
		Gtk::TreeModel::Row row = *iter;
		std::cout << "Row activated: Name=" << row[m_col_name] << std::endl;

		row[m_col_number]     = row[m_col_number]     + 100;
		row[m_col_percentage] = row[m_col_percentage] * 2;
		row[m_col_suffix]     = row[m_col_suffix]     + "W";
	}
}

