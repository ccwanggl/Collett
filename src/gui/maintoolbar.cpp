/*
** Collett – GUI Main Tool Bar Class
** =================================
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

#include "maintoolbar.h"
#include "icons.h"

#include <QFont>
#include <QSize>
#include <QToolBar>
#include <QWidget>
#include <QApplication>

namespace Collett {

GuiMainToolBar::GuiMainToolBar(QWidget *parent) : QToolBar(parent) {

    CollettIcons *icons = CollettIcons::instance();

    this->setIconSize(QSize(16, 16));

    // File Menu
    // =========

    m_openFile = new QAction(icons->icon("open"), tr("Open File"));
    this->addAction(m_openFile);

    m_saveFile = new QAction(icons->icon("save"), tr("Save File"));
    this->addAction(m_saveFile);

    // Paragraph Formatting
    // ====================

    this->addSeparator();

    m_formatHeading = new QAction(icons->icon("heading"), tr("Insert Heading"));
    this->addAction(m_formatHeading);

    // Char Formatting
    // ===============

    this->addSeparator();

    m_formatBold = new QAction(icons->icon("bold"), tr("Bold"));
    this->addAction(m_formatBold);

    m_formatItalic = new QAction(icons->icon("italic"), tr("Italics"));
    this->addAction(m_formatItalic);

    m_formatUnderline = new QAction(icons->icon("underline"), tr("Underline"));
    this->addAction(m_formatUnderline);

    m_formatStrike = new QAction(icons->icon("strikethrough"), tr("Strikethrough"));
    this->addAction(m_formatStrike);

    m_formatSuper = new QAction(icons->icon("superscript"), tr("Superscript"));
    this->addAction(m_formatSuper);

    m_formatSub = new QAction(icons->icon("subscript"), tr("Subscript"));
    this->addAction(m_formatSub);

    // Text Align
    // ==========

    this->addSeparator();

    m_alignLeft = new QAction(icons->icon("align-left"), tr("Align Left"));
    this->addAction(m_alignLeft);

    m_alignCenter = new QAction(icons->icon("align-center"), tr("Align Centre"));
    this->addAction(m_alignCenter);

    m_alignRight = new QAction(icons->icon("align-right"), tr("Align Right"));
    this->addAction(m_alignRight);

    m_alignJustify = new QAction(icons->icon("align-justify"), tr("Justify Margins"));
    this->addAction(m_alignJustify);

    // Block Format
    // ============

    this->addSeparator();

    m_textIndent = new QAction(icons->icon("indent"), tr("Indent Text"));
    this->addAction(m_textIndent);

    m_textOutdent = new QAction(icons->icon("outdent"), tr("Outdent Text"));
    this->addAction(m_textOutdent);

    // Text Tools
    // ==========

    this->addSeparator();

    m_textHighlight = new QAction(icons->icon("highlighter"), tr("Highlight Text"));
    this->addAction(m_textHighlight);

}

} // namespace Collett
