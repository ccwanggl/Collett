/*
** Collett – Main GUI Class
** ========================
**
** This file is a part of Collett
** Copyright 2020–2024, Veronica Berglyd Olsen
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "guimain.h"
#include "maintoolbar.h"
#include "settings.h"
#include "textedit.h"

#include <QCloseEvent>
#include <QApplication>

namespace Collett {

GuiMain::GuiMain(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle(qApp->applicationName());

    // Settings
    CollettSettings *mainConf = CollettSettings::instance();
    resize(mainConf->mainWindowSize());

    // GUI Components
    m_mainToolBar = new GuiMainToolBar(this);
    m_textEditor  = new GuiTextEdit(this);

    this->addToolBar(Qt::TopToolBarArea, m_mainToolBar);
    this->setCentralWidget(m_textEditor);

    return;
}

GuiMain::~GuiMain() {
    qDebug() << "Destructor: GuiMain";
}

/**!
 * @brief Open a Collett document.
 * 
 * @param path Path to the document.
 */
void GuiMain::openFile(const QString &path) {

}

/**
 * GUI Methods
 * ===========
 */

bool GuiMain::closeMain() {

    // Save Settings
    CollettSettings *mainConf = CollettSettings::instance();
    if (!this->isFullScreen()) {
        mainConf->setMainWindowSize(this->size());
    }
    mainConf->flushSettings();

    return true;
}

/**
 * Events
 * ======
 */

void GuiMain::closeEvent(QCloseEvent *event) {
    if (closeMain()) {
        event->accept();
    } else {
        event->ignore();
    }
}

} // namespace Collett
