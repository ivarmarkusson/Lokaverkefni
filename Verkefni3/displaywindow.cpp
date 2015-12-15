#include "displaywindow.h"
#include "ui_displaywindow.h"

#include <QMessageBox>
#include <QDebug>

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);

    scientistClicked = false;
    computerClicked = false;

    connectAllScientists();
    connectAllComputers();
    connectAllConnections();

    connect(ui->pushButton_close,SIGNAL(clicked()), this, SLOT(close()));
    //connect(ui->pushButton_add_sci, SIGNAL(clicked()), this, SLOT(addScientist()));

}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

//CONNECTS_TO_ENGINE_CLASS_TO_FETCH_DATA
void DisplayWindow::connectAllScientists()
{
    vector<Scientist> scientists;
    scientists.clear();
    currentlyDisplayedScientists.clear();
    scientists = engineObj.sortSientists(1);
    displayScientists(scientists);
    displaySciConnections(scientists);
}
void DisplayWindow::connectAllComputers()
{
    vector<Computer> computers;
    computers.clear();
    currentlyDisplayedComputers.clear();
    computers = engineObj.sortComputers(1);
    displayComputers(computers);
    displayComConnections(computers);
}
void DisplayWindow::connectAllConnections()
{
    vector<Connection> connections;
    currentlyDisplayedConnections.clear();
    connections.clear();
    connections = engineObj.sortConnections();
    displayConnections(connections);
}

//DISPLAYS_SCIENTISTS
void DisplayWindow::displayScientists(vector<Scientist> scientists)
{
    ui->table_display_sci->clearContents();
    ui->table_display_sci->setRowCount(scientists.size());
    ui->table_display_sci->setColumnCount(4);
    ui->table_display_sci->setSortingEnabled(false);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        QString name = QString::fromStdString(scientists.at(i).getName_Scientist());
        QString yearborn = QString::fromStdString(scientists.at(i).getBirth_Scientist());
        QString yeardead = QString::fromStdString(scientists.at(i).getDeath_Scientist());
        QString gender = QString::fromStdString(scientists.at(i).getGender_Scientist());

        ui->table_display_sci->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_sci->setItem(i, 1, new QTableWidgetItem(yearborn));
        ui->table_display_sci->setItem(i, 2, new QTableWidgetItem(yeardead));
        ui->table_display_sci->setItem(i, 3, new QTableWidgetItem(gender));
    }
    currentlyDisplayedScientists = scientists;
    ui->table_display_sci->setSortingEnabled(true);
}

//DISPLAYS_COMPUTERS
void DisplayWindow::displayComputers(vector<Computer> computers)
{
    ui->table_display_com->clearContents();
    ui->table_display_com->setRowCount(computers.size());
    ui->table_display_com->setColumnCount(4);
    ui->table_display_com->setSortingEnabled(false);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        QString name = QString::fromStdString(computers.at(i).getName_Computer());
        QString type = QString::fromStdString(computers.at(i).getType_Computer());
        QString year = QString::fromStdString(computers.at(i).getYearBuilt_Computer());
        QString built = QString::fromStdString(computers.at(i).getBuilt_Computer());

        ui->table_display_com->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_com->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_display_com->setItem(i, 2, new QTableWidgetItem(year));
        ui->table_display_com->setItem(i, 3, new QTableWidgetItem(built));
    }

    ui->table_display_com->setSortingEnabled(true);

    currentlyDisplayedComputers = computers;
}

//DISPLAYS_CONNECTIONS
void DisplayWindow::displayConnections(vector<Connection> connections)
{
    ui->table_display_connect->clearContents();
    ui->table_display_connect->setRowCount(connections.size());
    ui->table_display_connect->setColumnCount(2);
    ui->table_display_connect->setSortingEnabled(false);

    for(unsigned int i = 0; i < connections.size(); i++)
    {

        QString name_computer = QString::fromStdString(connections.at(i).getName_Com());
        QString name_scientist = QString::fromStdString(connections.at(i).getName_Sci());

        ui->table_display_connect->setItem(i, 0, new QTableWidgetItem(name_scientist));
        ui->table_display_connect->setItem(i, 1, new QTableWidgetItem(name_computer));
    }

    ui->table_display_connect->setSortingEnabled(true);

    currentlyDisplayedConnections = connections;
}

//DISPLAYS_SCIENTISTS_CONNECTIONS
void DisplayWindow::displaySciConnections(vector<Scientist> scientists)
{
    ui->table_edit_connect_sci->clearContents();
    ui->table_edit_connect_sci->setRowCount(scientists.size());
    ui->table_edit_connect_sci->setColumnCount(4);
    ui->table_edit_connect_sci->setSortingEnabled(false);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        QString name = QString::fromStdString(scientists.at(i).getName_Scientist());
        QString yearborn = QString::fromStdString(scientists.at(i).getBirth_Scientist());
        QString yeardead = QString::fromStdString(scientists.at(i).getDeath_Scientist());
        QString gender = QString::fromStdString(scientists.at(i).getGender_Scientist());

        ui->table_edit_connect_sci->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_edit_connect_sci->setItem(i, 1, new QTableWidgetItem(yearborn));
        ui->table_edit_connect_sci->setItem(i, 2, new QTableWidgetItem(yeardead));
        ui->table_edit_connect_sci->setItem(i, 3, new QTableWidgetItem(gender));
    }

    ui->table_edit_connect_sci->setSortingEnabled(true);
}

//DISPLAYS_COMPUTERS_CONNECTIONS
void DisplayWindow::displayComConnections(vector<Computer> computers)
{
    ui->table_edit_connect_com->clearContents();
    ui->table_edit_connect_com->setRowCount(computers.size());
    ui->table_edit_connect_com->setColumnCount(4);
    ui->table_edit_connect_com->setSortingEnabled(false);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        QString name = QString::fromStdString(computers.at(i).getName_Computer());
        QString type = QString::fromStdString(computers.at(i).getType_Computer());
        QString year = QString::fromStdString(computers.at(i).getYearBuilt_Computer());
        QString built = QString::fromStdString(computers.at(i).getBuilt_Computer());

        ui->table_edit_connect_com->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_edit_connect_com->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_edit_connect_com->setItem(i, 2, new QTableWidgetItem(year));
        ui->table_edit_connect_com->setItem(i, 3, new QTableWidgetItem(built));
    }

    ui->table_edit_connect_com->setSortingEnabled(true);

    currentlyDisplayedComputers = computers;
}

//TABLE_CLICKED_DISPLAYS_SCIENTIST
void DisplayWindow::on_table_display_sci_clicked()
{
    if(!(ui->table_display_sci->currentItem()->isSelected()))
    {
        ui->pushButton_remove_sci->setEnabled(false);
        ui->pushButton_edit_sci->setEnabled(false);
    }
    else
    {
        ui->pushButton_remove_sci->setEnabled(true);
        ui->pushButton_edit_sci->setEnabled(true);
    }

    int scientistIndex = ui->table_display_sci->currentIndex().row();
    Scientist selectedScientist = currentlyDisplayedScientists.at(scientistIndex);

    string name = selectedScientist.getName_Scientist();
    string gender = selectedScientist.getGender_Scientist();
    string death = selectedScientist.getDeath_Scientist();
    string birth = selectedScientist.getBirth_Scientist();

    QString qName = QString::fromStdString(name);
    QString qGender = QString::fromStdString(gender);
    QString qDeath = QString::fromStdString(death);
    QString qBirth = QString::fromStdString(birth);

    ui->line_sci_name_add_remove_edit->setText(qName);
    ui->line_sci_gender_add_remove_edit->setText(qGender);
    ui->line_sci_birth_add_remove_edit->setText(qBirth);
    if(death != "Alive")
    {
        ui->line_sci_death_add_remove_edit->setText(qDeath);
    }
}

//TABLE_CLICKED_COMPUTERS
void DisplayWindow::on_table_display_com_clicked()
{
    if(!(ui->table_display_com->currentItem()->isSelected()))
    {
        ui->pushButton_com_remove->setEnabled(false);
        ui->pushButton_com_edit->setEnabled(false);
    }
    else
    {
        ui->pushButton_com_remove->setEnabled(true);
        ui->pushButton_com_edit->setEnabled(true);
    }

    int computerIndex = ui->table_display_com->currentIndex().row();

    Computer selectedComputer = currentlyDisplayedComputers.at(computerIndex);

    string name = selectedComputer.getName_Computer();
    string type = selectedComputer.getType_Computer();
    string year = selectedComputer.getYearBuilt_Computer();
    string built = selectedComputer.getBuilt_Computer();

    QString qName = QString::fromStdString(name);
    QString qType = QString::fromStdString(type);
    QString qYear = QString::fromStdString(year);
    QString qBuilt = QString::fromStdString(built);

    ui->line_com_name_add_remove_edit->setText(qName);
    ui->line_com_type_add_remove_edit->setText(qType);
    ui->line_com_year_add_remove_edit->setText(qYear);
    ui->line_com_built_add_remove_edit->setText(qBuilt);
}


//ADDS_SCIENTIST_TO_DATABASE
void DisplayWindow::on_pushButton_add_sci_clicked()
{
    addScientist();
    connectAllScientists();
}

void DisplayWindow::addScientist()
{
    int id = ui->table_display_sci->currentIndex().row();
    string name = ui->line_sci_name_add_remove_edit->text().toStdString();
    name[0] = toupper(name[0]);
    string gender = ui->line_sci_gender_add_remove_edit->text().toStdString();
    gender[0] = toupper(gender[0]);
    string birth = ui->line_sci_birth_add_remove_edit->text().toStdString();
    birth[0] = toupper(birth[0]);
    string death = ui->line_sci_death_add_remove_edit->text().toStdString();
    death[0] = toupper(death[0]);

    if(death == "")
    {
        death = "Alive";
    }
    Scientist* newScientist = new Scientist(id,name,gender,birth,death);
    /*
    newScientist.setName_Scientist(name);
    newScientist.setGender_Scientist(gender);
    newScientist.setBirth_Scientist(birth);
    newScientist.setDeath_Scientist(death);
    */
    if(name.empty()|| birth.empty() || gender.empty()
                || atoi(birth.c_str()) > 2015 || atoi(death.c_str()) > 2015
                || ((atoi(birth.c_str()) > atoi(death.c_str())) && death != "Alive")
                || (gender != "Male" && gender != "male" && gender != "Female" && gender != "female"))
        {
            ui->statusbar->showMessage("Invalid Input, Try Again!", 3000);
        }
        else
        {
            engineObj.addScientists(*newScientist);
            ui->statusbar->showMessage("Scientist Has Been Added!", 3000);
        }

    delete newScientist;
}

//ADDS_COMPUTER_TO_DATABASE
void DisplayWindow::on_pushButton_com_add_clicked()
{
    addComputer();
    connectAllComputers();
}

void DisplayWindow::addComputer()
{
    int id = ui->table_display_com->currentIndex().row();
    string name = ui->line_com_name_add_remove_edit->text().toStdString();
    name[0] = toupper(name[0]);
    string type = ui->line_com_type_add_remove_edit->text().toStdString();
    type[0] = toupper(type[0]);
    string year = ui->line_com_year_add_remove_edit->text().toStdString();
    year[0] = toupper(year[0]);
    string built = ui->line_com_built_add_remove_edit->text().toStdString();
    built[0] = toupper(built[0]);

    Computer* newComputer = new Computer(id,name,type,year,built);

    /*
    newComputer.setName_Computer(name);
    newComputer.setType_Computer(type);
    newComputer.setYearBuilt_Computer(year);
    newComputer.setBuilt_Computer(built);
    */

    if(name.empty() || type.empty() || year.empty() || built.empty()
            || (built != "Yes" && built != "yes" && built != "No" && built != "no")
            || atoi(year.c_str()) > 2015 || atoi(year.c_str()) < 0)
        {
            ui->statusbar->showMessage("Invalid Input, Try Again!", 3000);
        }
        else
        {
            engineObj.addComputers(*newComputer);

            ui->statusbar->showMessage("Computer Has Been Added", 3000);
        }

    delete newComputer;

}

//SEARCH_SCIENTISTS
void DisplayWindow::on_line_search_sci_textChanged()
{
    string input = ui->line_search_sci->text().toStdString();

    vector<Scientist> searchResults;
    searchResults.clear();

    searchResults = engineObj.searchScientists(input);
    displayScientists(searchResults);
}

//SEARCH_COMPUTERS
void DisplayWindow::on_line_search_com_textChanged()
{
    string input = ui->line_search_com->text().toStdString();

    vector<Computer> searchResults;
    searchResults.clear();

    searchResults = engineObj.searchComputers(input);
    displayComputers(searchResults);
}

//SEARCH_LINES_IN_CONNECTIONS
void DisplayWindow::on_line_connect_search_sci_textChanged()
{
    string input = ui->line_connect_search_sci->text().toStdString();

    vector<Scientist> searchResults;
    searchResults.clear();

    searchResults = engineObj.searchScientists(input);
    displaySciConnections(searchResults);
}
void DisplayWindow::on_line_connect_search_com_textChanged()
{
    string input = ui->line_connect_search_com->text().toStdString();

    vector<Computer> searchResults;
    searchResults.clear();

    searchResults = engineObj.searchComputers(input);
    displayComConnections(searchResults);
}

//ENABLE_BUTTONS
void DisplayWindow::on_table_edit_connect_sci_clicked()
{
    if(ui->table_edit_connect_sci->currentItem()->isSelected())
    {
        scientistClicked = true;
    }
    else
    {
        scientistClicked = false;
    }

    if(computerClicked && scientistClicked)
    {
        ui->pushButton_connect->setEnabled(true);
    }
    else
    {
        ui->pushButton_connect->setEnabled(false);
    }
}
void DisplayWindow::on_table_edit_connect_com_clicked()
{
    if(ui->table_edit_connect_com->currentItem()->isSelected())
    {
        computerClicked = true;
    }
    else
    {
        computerClicked = false;
    }

    if(computerClicked && scientistClicked)
    {
        ui->pushButton_connect->setEnabled(true);
    }
    else
    {
        ui->pushButton_connect->setEnabled(false);
    }
}
void DisplayWindow::on_pushButton_connect_clicked()
{
    //Needs fixing, possibly use a pointer like in addSci and addCom
    Scientist connectScientist;

    int s_index = ui->table_edit_connect_sci->currentIndex().row();
    connectScientist = currentlyDisplayedScientists.at(s_index);
    int s_ID = currentlyDisplayedScientists.at(s_index).getID_Scientist();

    Computer connectComputer;

    int c_index = ui->table_edit_connect_com->currentIndex().row();
    connectComputer = currentlyDisplayedComputers.at(c_index);
    int c_ID = currentlyDisplayedComputers.at(c_index).getID_Computer();

    ui->statusbar->showMessage(QString::number(c_ID), 3000);


    engineObj.addConnection(c_ID,s_ID);
    connectAllConnections();
}

void DisplayWindow::on_pushButton_remove_sci_clicked()
{
    Scientist removeScientist;

    int index = ui->table_display_sci->currentIndex().row();
    removeScientist = currentlyDisplayedScientists.at(index);

    QString ID = QString::number(currentlyDisplayedScientists.at(index).getID_Scientist());
    ui->statusbar->showMessage("Scientist Has Been Removed!", 3000);

    engineObj.removeScientist(ID);
    connectAllScientists();
}


void DisplayWindow::on_pushButton_edit_sci_clicked()
{
    Scientist editScientist;

    int index = ui->table_display_sci->currentIndex().row();
    editScientist = currentlyDisplayedScientists.at(index);

    string name = ui->line_sci_name_add_remove_edit->text().toStdString();
    string gender = ui->line_sci_gender_add_remove_edit->text().toStdString();
    string birth = ui->line_sci_birth_add_remove_edit->text().toStdString();
    string death = ui->line_sci_death_add_remove_edit->text().toStdString();

    editScientist.setName_Scientist(name);
    editScientist.setGender_Scientist(gender);
    editScientist.setBirth_Scientist(birth);
    editScientist.setDeath_Scientist(death);

    Data dataobj;
    dataobj.EditSci(editScientist);

    ui->statusbar->showMessage("Scientist Has Been Edited!", 3000);

    connectAllScientists();
}

void DisplayWindow::on_pushButton_com_remove_clicked()
{
    Computer removeComputer;

    int index = ui->table_display_com->currentIndex().row();
    removeComputer = currentlyDisplayedComputers.at(index);

    QString ID = QString::number(currentlyDisplayedComputers.at(index).getID_Computer());
    ui->statusbar->showMessage("Computer Has Been Removed!", 3000);

    engineObj.removeComputer(ID);
    connectAllComputers();
}
