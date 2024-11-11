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

#include <QApplication>
#include <QFont>
#include <QMenu>
#include <QSize>
#include <QToolBar>
#include <QWidget>

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

    m_formatHeadingMenu = new QMenu(this);

    m_formatTextGroup = new QActionGroup(this);
    m_formatTextGroup->setExclusionPolicy(QActionGroup::ExclusionPolicy::Exclusive);

    m_formatHeading1 = m_formatHeadingMenu->addAction(tr("Partition"));
    m_formatHeading1->setCheckable(true);
    m_formatHeading1->setActionGroup(m_formatTextGroup);

    m_formatHeading2 = m_formatHeadingMenu->addAction(tr("Chapter"));
    m_formatHeading2->setCheckable(true);
    m_formatHeading2->setActionGroup(m_formatTextGroup);

    m_formatHeading3 = m_formatHeadingMenu->addAction(tr("Scene"));
    m_formatHeading3->setCheckable(true);
    m_formatHeading3->setActionGroup(m_formatTextGroup);

    m_formatHeading4 = m_formatHeadingMenu->addAction(tr("Section"));
    m_formatHeading4->setCheckable(true);
    m_formatHeading4->setActionGroup(m_formatTextGroup);

    m_formatHeading = new QToolButton(this);
    m_formatHeading->setIcon(icons->icon("heading"));
    m_formatHeading->setToolTip(tr("Heading Formats"));
    m_formatHeading->setMenu(m_formatHeadingMenu);
    m_formatHeading->setPopupMode(QToolButton::InstantPopup);
    this->addWidget(m_formatHeading);

    m_formatParagraph = new QAction(icons->icon("paragraph"), tr("Text Paragraph"));
    m_formatParagraph->setCheckable(true);
    m_formatParagraph->setActionGroup(m_formatTextGroup);
    this->addAction(m_formatParagraph);

    // Char Formatting
    // ===============

    this->addSeparator();

    m_formatBold = new QAction(icons->icon("bold"), tr("Bold"));
    m_formatBold->setCheckable(true);
    this->addAction(m_formatBold);

    m_formatItalic = new QAction(icons->icon("italic"), tr("Italics"));
    m_formatItalic->setCheckable(true);
    this->addAction(m_formatItalic);

    m_formatUnderline = new QAction(icons->icon("underline"), tr("Underline"));
    m_formatUnderline->setCheckable(true);
    this->addAction(m_formatUnderline);

    m_formatStrike = new QAction(icons->icon("strikethrough"), tr("Strikethrough"));
    m_formatStrike->setCheckable(true);
    this->addAction(m_formatStrike);

    m_formatSuper = new QAction(icons->icon("superscript"), tr("Superscript"));
    m_formatSuper->setCheckable(true);
    this->addAction(m_formatSuper);

    m_formatSub = new QAction(icons->icon("subscript"), tr("Subscript"));
    m_formatSub->setCheckable(true);
    this->addAction(m_formatSub);

    // Text Align
    // ==========

    this->addSeparator();

    m_alignTextGroup = new QActionGroup(this);
    m_alignTextGroup->setExclusionPolicy(QActionGroup::ExclusionPolicy::Exclusive);

    m_alignLeft = new QAction(icons->icon("align-left"), tr("Align Left"));
    m_alignLeft->setCheckable(true);
    m_alignLeft->setActionGroup(m_alignTextGroup);
    this->addAction(m_alignLeft);

    m_alignCenter = new QAction(icons->icon("align-center"), tr("Align Centre"));
    m_alignCenter->setCheckable(true);
    m_alignCenter->setActionGroup(m_alignTextGroup);
    this->addAction(m_alignCenter);

    m_alignRight = new QAction(icons->icon("align-right"), tr("Align Right"));
    m_alignRight->setCheckable(true);
    m_alignRight->setActionGroup(m_alignTextGroup);
    this->addAction(m_alignRight);

    m_alignJustify = new QAction(icons->icon("align-justify"), tr("Justify Margins"));
    m_alignJustify->setCheckable(true);
    m_alignJustify->setActionGroup(m_alignTextGroup);
    this->addAction(m_alignJustify);

    // Block Format
    // ============

    this->addSeparator();

    m_lineIndent = new QAction(icons->icon("line-indent"), tr("First Line Indent"));
    m_lineIndent->setCheckable(true);
    this->addAction(m_lineIndent);

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

/**
 * Private Slots
 * =============
 */

void GuiMainToolBar::editorCharFormatChanged(const QTextCharFormat &fmt) {
    m_formatBold->setChecked(fmt.fontWeight() > QFont::Medium);
    m_formatItalic->setChecked(fmt.fontItalic());
    m_formatUnderline->setChecked(fmt.fontUnderline());
    m_formatStrike->setChecked(fmt.fontStrikeOut());
    m_formatSuper->setChecked(fmt.verticalAlignment() == QTextCharFormat::AlignSuperScript);
    m_formatSub->setChecked(fmt.verticalAlignment() == QTextCharFormat::AlignSubScript);
}

void GuiMainToolBar::editorBlockChanged(const QTextBlock &block) {

    QTextBlockFormat blockFormat = block.blockFormat();

    switch (blockFormat.headingLevel()) {
    case 1:
        m_formatHeading1->setChecked(true);
        break;
    case 2:
        m_formatHeading2->setChecked(true);
        break;
    case 3:
        m_formatHeading3->setChecked(true);
        break;
    case 4:
        m_formatHeading4->setChecked(true);
        break;
    default:
        m_formatParagraph->setChecked(true);
        break;
    }

    switch (blockFormat.alignment()) {
    case  Qt::AlignLeft:
        m_alignLeft->setChecked(true);
        break;
    case  Qt::AlignHCenter:
        m_alignCenter->setChecked(true);
        break;
    case  Qt::AlignRight:
        m_alignRight->setChecked(true);
        break;
    case  Qt::AlignJustify:
        m_alignJustify->setChecked(true);
        break;
    }

    m_lineIndent->setChecked(blockFormat.textIndent() > 0.0);
}

} // namespace Collett
