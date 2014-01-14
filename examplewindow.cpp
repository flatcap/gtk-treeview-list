#include <iostream>
#include "examplewindow.h"

ExampleWindow::ExampleWindow (void)
{
	set_default_size (500, 200);

	add (m_TreeView);

	m_Columns.add (m_col_id);
	m_Columns.add (m_col_name);
	m_Columns.add (m_col_number);
	m_Columns.add (m_col_percentage);

	m_refTreeModel = Gtk::ListStore::create (m_Columns);
	m_TreeView.set_model (m_refTreeModel);

	Gtk::TreeModel::Row row;

	row = *(m_refTreeModel->append()); row[m_col_id] = 1; row[m_col_name] = "Billy Bob";     row[m_col_number] = 10; row[m_col_percentage] = 15;
	row = *(m_refTreeModel->append()); row[m_col_id] = 2; row[m_col_name] = "Joey Jojo";     row[m_col_number] = 20; row[m_col_percentage] = 40;
	row = *(m_refTreeModel->append()); row[m_col_id] = 3; row[m_col_name] = "Rob McRoberts"; row[m_col_number] = 30; row[m_col_percentage] = 70;

	m_TreeView.append_column ("ID",   m_col_id);
	m_TreeView.append_column ("Name", m_col_name);

	m_TreeView.append_column_numeric ("Formatted number", m_col_number, "%010d");

	Gtk::CellRendererProgress* cell = Gtk::manage (new Gtk::CellRendererProgress);
	int cols_count = m_TreeView.append_column ("Some percentage", *cell);
	Gtk::TreeViewColumn* pColumn = m_TreeView.get_column (cols_count - 1);
	if (pColumn) {
		pColumn->add_attribute (cell->property_value(), m_col_percentage);
	}

	show_all_children();
}

