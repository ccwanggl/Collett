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
#include "data.h"
#include "maintoolbar.h"
#include "settings.h"
#include "textedit.h"

#include <QApplication>
#include <QCloseEvent>
#include <QJsonArray>

namespace Collett {

GuiMain::GuiMain(QWidget *parent) : QMainWindow(parent) {

    m_data = CollettData::instance();
    setWindowTitle(qApp->applicationName());

    // Settings
    CollettSettings *mainConf = CollettSettings::instance();
    resize(mainConf->mainWindowSize());

    // GUI Components
    m_mainToolBar = new GuiMainToolBar(this);
    m_textEditor  = new GuiTextEdit(this);

    this->addToolBar(Qt::TopToolBarArea, m_mainToolBar);
    this->setCentralWidget(m_textEditor);

    // Connect Signals
    // ===============

    // ToolBar Paragraph Formatting
    connect(m_mainToolBar->m_formatHeading1, &QAction::triggered,
            [this]{m_textEditor->applyBlockFormat(GuiTextEdit::Header, 1);});
    connect(m_mainToolBar->m_formatHeading2, &QAction::triggered,
            [this]{m_textEditor->applyBlockFormat(GuiTextEdit::Header, 2);});
    connect(m_mainToolBar->m_formatHeading3, &QAction::triggered,
            [this]{m_textEditor->applyBlockFormat(GuiTextEdit::Header, 3);});
    connect(m_mainToolBar->m_formatHeading4, &QAction::triggered,
            [this]{m_textEditor->applyBlockFormat(GuiTextEdit::Header, 4);});
    connect(m_mainToolBar->m_formatParagraph, &QAction::triggered,
            [this]{m_textEditor->applyBlockFormat(GuiTextEdit::Paragraph, 0);});

    // ToolBar Char Formatting
    connect(m_mainToolBar->m_formatBold, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleBoldFormat()));
    connect(m_mainToolBar->m_formatItalic, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleItalicFormat()));
    connect(m_mainToolBar->m_formatUnderline, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleUnderlineFormat()));
    connect(m_mainToolBar->m_formatStrike, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleStrikeFormat()));
    connect(m_mainToolBar->m_formatSuper, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleSuperScriptFormat()));
    connect(m_mainToolBar->m_formatSub, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleSubScriptFormat()));

    // ToolBar Text Align
    connect(m_mainToolBar->m_alignLeft, &QAction::triggered,
            [this]{m_textEditor->applyBlockAlignment(Qt::AlignLeft);});
    connect(m_mainToolBar->m_alignCenter, &QAction::triggered,
            [this]{m_textEditor->applyBlockAlignment(Qt::AlignHCenter);});
    connect(m_mainToolBar->m_alignRight, &QAction::triggered,
            [this]{m_textEditor->applyBlockAlignment(Qt::AlignRight);});
    connect(m_mainToolBar->m_alignJustify, &QAction::triggered,
            [this]{m_textEditor->applyBlockAlignment(Qt::AlignJustify);});

    // ToolBar Block Format
    connect(m_mainToolBar->m_lineIndent, SIGNAL(triggered()),
            m_textEditor, SLOT(toggleFirstLineIndent()));
    connect(m_mainToolBar->m_textIndent, SIGNAL(triggered()),
            m_textEditor, SLOT(increaseBlockIndent()));
    connect(m_mainToolBar->m_textOutdent, SIGNAL(triggered()),
            m_textEditor, SLOT(decreaseBlockIndent()));

    // Editor Return Format Signals
    connect(m_textEditor, SIGNAL(currentCharFormatChanged(const QTextCharFormat&)),
            m_mainToolBar, SLOT(editorCharFormatChanged(const QTextCharFormat&)));
    connect(m_textEditor, SIGNAL(currentBlockChanged(const QTextBlock&)),
            m_mainToolBar, SLOT(editorBlockChanged(const QTextBlock&)));

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

    m_data->openProject(path);
    if (!m_data->hasProject()) {
        return;
    }

    QJsonArray jContent = m_data->project()->document().value(QLatin1String("x:content")).toArray();
    this->m_textEditor->setJsonContent(jContent);
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
