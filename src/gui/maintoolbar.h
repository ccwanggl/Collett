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

#ifndef GUI_MAIN_TOOLBAR_H
#define GUI_MAIN_TOOLBAR_H

#include <QAction>
#include <QActionGroup>
#include <QObject>
#include <QTextBlock>
#include <QTextCharFormat>
#include <QToolBar>
#include <QToolButton>
#include <QWidget>

namespace Collett {

class GuiMain;
class GuiMainToolBar : public QToolBar
{
    Q_OBJECT

public:
    GuiMainToolBar(QWidget *parent=nullptr);
    ~GuiMainToolBar() {};

public slots:
    void editorCharFormatChanged(const QTextCharFormat &fmt);
    void editorBlockChanged(const QTextBlock &block);

private:

    // Groups
    QActionGroup *m_formatTextGroup;
    QActionGroup *m_alignTextGroup;

    // File Menu
    QAction *m_openFile;
    QAction *m_saveFile;

    // Paragraph Formatting
    QToolButton *m_formatHeading;
    QMenu       *m_formatHeadingMenu;
    QAction     *m_formatHeading1;
    QAction     *m_formatHeading2;
    QAction     *m_formatHeading3;
    QAction     *m_formatHeading4;
    QAction     *m_formatParagraph;

    // Char Formatting
    QAction *m_formatBold;
    QAction *m_formatItalic;
    QAction *m_formatUnderline;
    QAction *m_formatStrike;
    QAction *m_formatSuper;
    QAction *m_formatSub;

    // Text Align
    QAction *m_alignLeft;
    QAction *m_alignCenter;
    QAction *m_alignRight;
    QAction *m_alignJustify;

    // Block Format
    QAction *m_lineIndent;
    QAction *m_textIndent;
    QAction *m_textOutdent;

    // Text Tools
    QAction *m_textHighlight;

    friend class GuiMain;

};
} // namespace Collett

#endif // GUI_MAIN_TOOLBAR_H
