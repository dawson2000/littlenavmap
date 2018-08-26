/*****************************************************************************
* Copyright 2015-2018 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "gui/timedialog.h"
#include "ui_timedialog.h"

TimeDialog::TimeDialog(QWidget *parent, const QDateTime& datetime) :
  QDialog(parent), ui(new Ui::TimeDialog)
{
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
  setWindowModality(Qt::ApplicationModal);
  ui->setupUi(this);

  ui->calendarWidget->setSelectedDate(datetime.date());
  ui->timeEdit->setTime(datetime.time());
}

TimeDialog::~TimeDialog()
{
  delete ui;
}

QDateTime TimeDialog::getDateTime() const
{
  return QDateTime(ui->calendarWidget->selectedDate(), ui->timeEdit->time());
}