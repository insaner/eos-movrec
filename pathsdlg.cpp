/***************************************************************************
 *   Copyright (C) 2015 by insaner                                         *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "pathsdlg.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
	/*
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
	*/
#include <QString>
#include <QToolButton>
#include <QFileDialog>



	/*
		CurrSettings.Path = dlg.Path();
		CurrSettings.VidName = dlg.VidName();
		CurrSettings.ImgName = dlg.ImgName();
	*/


GPathsDlg::GPathsDlg(QWidget* parent)
 : QDialog(parent)
{
	setModal(true);
	setSizeGripEnabled(false);
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setSizeConstraint(QLayout::SetFixedSize);
	
	
	QHBoxLayout* layout_Path = new QHBoxLayout();
	layout_Path->addWidget(new QLabel(tr("Path:")), 0);
	PathLabel = new QLabel(Path);
	layout_Path->addWidget(PathLabel, 0);
	
	PathBtn = new QToolButton(this);
	PathBtn->setText(tr("..."));
	PathBtn->setEnabled(true);
	PathBtn->setToolTip(tr("select Path"));
	layout_Path->addWidget(PathBtn, 0);
	layout->addLayout(layout_Path, 0);
	
	
	QHBoxLayout* layout_ImgName = new QHBoxLayout();
	layout_ImgName->addWidget(new QLabel(tr("ImgName:")), 0);
	ImgNameLabel = new QLabel(ImgName);
	layout_ImgName->addWidget(ImgNameLabel, 0);
	
	ImgNameBtn = new QToolButton(this);
	ImgNameBtn->setText(tr("..."));
	ImgNameBtn->setEnabled(true);
	ImgNameBtn->setToolTip(tr("select Img name"));
	layout_ImgName->addWidget(ImgNameBtn, 0);
	layout->addLayout(layout_ImgName, 0);
	
	
	QHBoxLayout* layout_VidName = new QHBoxLayout();
	layout_VidName->addWidget(new QLabel(tr("VidName:")), 0);
	VidNameLabel = new QLabel(VidName);
	layout_VidName->addWidget(VidNameLabel, 0);
	
	VidNameBtn = new QToolButton(this);
	VidNameBtn->setText(tr("..."));
	VidNameBtn->setEnabled(true);
	VidNameBtn->setToolTip(tr("select Vid name"));
	layout_VidName->addWidget(VidNameBtn, 0);
	layout->addLayout(layout_VidName, 0);
	
	
	QFrame *line = new QFrame(this);
	line->setFrameShape(QFrame::HLine); // Horizontal line
	line->setFrameShadow(QFrame::Sunken);
	line->setLineWidth(1);

	QHBoxLayout* layout_line = new QHBoxLayout();
	layout_line->addWidget(line);
	layout->addLayout(layout_line, 0);
	

	QHBoxLayout* layout_FName_inc = new QHBoxLayout();
	layout_FName_inc->addWidget(new QLabel(tr("File names automatically increment numerically (appended with _000, _001... before the extension).")), 0);
	layout->addLayout(layout_FName_inc, 0);
	/*
	
	QHBoxLayout* layout_line1 = new QHBoxLayout();
	layout_line1->addWidget(new QLabel(tr("Buffer size (for writing)")), 0);
	BufferBox = new QSpinBox(this);
	BufferBox->setSuffix(tr("MB"));
	BufferBox->setRange(1, 512);
	BufferBox->setValue(2);
	layout_line1->addWidget(BufferBox, 0);
	layout->addLayout(layout_line1, 0);

	QHBoxLayout* layout_line2 = new QHBoxLayout();
	layout_line2->addWidget(new QLabel(tr("Camera AF mode (only on 50D and later!)")), 0);
	AFModeBox = new QComboBox(this);
	AFModeBox->addItem(tr("Quick"));
	AFModeBox->addItem(tr("Live"));
	AFModeBox->addItem(tr("Live Face"));
	AFModeBox->setCurrentIndex(1);
	layout_line2->addWidget(AFModeBox, 0);
	layout->addLayout(layout_line2, 0);

	StabFPSBox = new QCheckBox(tr("Use stabilized FPS"), this);
	layout->addWidget(StabFPSBox, 0);

	ShowWhiteBox = new QCheckBox(tr("Show zoom white box"), this);
	layout->addWidget(ShowWhiteBox, 0);

	*/
	
	
	QHBoxLayout* layout_btn = new QHBoxLayout();
	layout_btn->addStretch(10);
	QPushButton* okBtn = new QPushButton(this);
	okBtn->setText(tr("&OK"));
	okBtn->setDefault(true);
	okBtn->setAutoDefault(true);
	layout_btn->addWidget(okBtn, 0);
	layout_btn->addSpacing(10);
	QPushButton* cancelBtn = new QPushButton(this);
	cancelBtn->setText(tr("&Cancel"));
	layout_btn->addWidget(cancelBtn, 0);
	layout_btn->addStretch(10);
	layout->addLayout(layout_btn, 0);
	
	connect(PathBtn, SIGNAL(clicked()), this, SLOT(slotSelPath()));
	connect(ImgNameBtn, SIGNAL(clicked()), this, SLOT(slotSelImgName()));
	connect(VidNameBtn, SIGNAL(clicked()), this, SLOT(slotSelVidName()));

	connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}


//	dlg.setOptions(CurrSettings.Path, CurrSettings.VidName, CurrSettings.ImgName);
void GPathsDlg::setOptions(QString newPath, QString newVidName, QString newImgName)
//void GPathsDlg::setOptions(int buff_sz, int afmode, bool s, bool w)
{
 fprintf(stderr, "GPathsDlg::setOptions: \n");
 fprintf(stderr, "GPathsDlg::setOptions: [%s, %s, %s]\n", newPath.toLatin1().constData(),
		newVidName.toLatin1().constData(),
		newImgName.toLatin1().constData());
	Path = newPath;
	VidName = newVidName;
	ImgName = newImgName;
	PathLabel->setText(Path);
	VidNameLabel->setText(VidName);
	ImgNameLabel->setText(ImgName);
 fprintf(stderr, "GPathsDlg::setOptions: DONE\n");
/*
	BufferBox->setValue(buff_sz/1048576);
	AFModeBox->setCurrentIndex(afmode);
	StabFPSBox->setChecked(s);
	ShowWhiteBox->setChecked(w);
*/
	
}


void GPathsDlg::slotSelPath()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Save directory"), Path,
		QFileDialog::ShowDirsOnly);
 fprintf(stderr, "GPathsDlg::slotSelPath \n");
	if (!dir.isNull() && !dir.isEmpty())
	{
		Path = dir;
		PathLabel->setText(Path);
 fprintf(stderr, "GPathsDlg::slotSelPath: Path: \n");
 fprintf(stderr, "GPathsDlg::slotSelPath: Path: [%s]\n", Path.toLatin1().constData());
	}
}
	
void GPathsDlg::slotSelImgName()
{
	// QString dir = QFileDialog::getExistingDirectory(this, tr("Save directory"), Path,
	// 	QFileDialog::ShowDirsOnly);
	QString dir = QFileDialog::getSaveFileName(this, tr("Video file output name"), ImgName,
		// tr("JPG Image  .jpg (*.jpg)"), 0);
		tr("JPG Image  .jpg (*.jpg)"), 0, QFileDialog::DontConfirmOverwrite);
 fprintf(stderr, "GPathsDlg::slotSelImgName \n");
	if (!dir.isNull() && !dir.isEmpty())
	{
		ImgName = dir;
		ImgNameLabel->setText(ImgName);
 fprintf(stderr, "GPathsDlg::slotSelImgName: ImgName: \n");
 fprintf(stderr, "GPathsDlg::slotSelImgName: ImgName: [%s]\n", ImgName.toLatin1().constData());
 fprintf(stderr, "GPathsDlg::slotSelImgName: dir ImgName: [%s]\n", QFileInfo(ImgName).path().toLatin1().constData());
 //fprintf(stderr, "GPathsDlg::slotSelImgName: ext ImgName: [%s]\n", QFileInfo(ImgName).extension().toLatin1().constData());
 fprintf(stderr, "GPathsDlg::slotSelImgName: ext ImgName: [%s]\n", QFileInfo(ImgName).suffix().toLatin1().constData());
 fprintf(stderr, "GPathsDlg::slotSelImgName: base ImgName: [%s]\n", QFileInfo(ImgName).completeBaseName().toLatin1().constData());
	}
}

// QString QFileDialog::getSaveFileName(QWidget * parent = 0, const QString & caption = QString(), const QString & dir = QString(), const QString & filter = QString(), QString * selectedFilter = 0, Options options = 0)
void GPathsDlg::slotSelVidName()
{
	QString dir = QFileDialog::getSaveFileName(this, tr("Video file output name"), VidName,
		// tr("Videos  .avi .mpg .mp4 (*.avi *.mpg *.mp4)"), 0);
		tr("Videos  .avi .mpg .mp4 (*.avi *.mpg *.mp4)"), 0, QFileDialog::DontConfirmOverwrite);
	// QString dir = QFileDialog::getExistingDirectory(this, tr("Save directory"), Path,
	// 	QFileDialog::ShowDirsOnly);
 fprintf(stderr, "GPathsDlg::slotSelVidName \n");
	if (!dir.isNull() && !dir.isEmpty())
	{
		VidName = dir;
		VidNameLabel->setText(VidName);
 fprintf(stderr, "GPathsDlg::slotSelVidName: VidName: \n");
 fprintf(stderr, "GPathsDlg::slotSelVidName: VidName: [%s]\n", VidName.toLatin1().constData());
	}
}
/*
int GPathsDlg::bufferSize()
{
	return 1048576*BufferBox->value();
}

int GPathsDlg::afMode()
{
	return AFModeBox->currentIndex();
}

bool GPathsDlg::useStabFPS()
{
	return StabFPSBox->isChecked();
}

bool GPathsDlg::showWhiteBox()
{
	return ShowWhiteBox->isChecked();
}
*/
// ------------------------------


	
	

// /*
GPathsDlg::~GPathsDlg()
{
// fprintf(stderr, "GPathsDlg::DESTRUCTOER \n");
}

// */
	