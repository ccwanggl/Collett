/*
** Collett – Core Icon Repository
** ==============================
**
** This file is a part of Collett
** Copyright 2020–2021, Veronica Berglyd Olsen
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

#include "icons.h"
#include "svgiconengine.h"

#include <QIcon>
#include <QColor>
#include <QDebug>
#include <QString>
#include <QPalette>
#include <QApplication>
#include <QLatin1String>

namespace Collett {

CollettIcons *CollettIcons::staticInstance = nullptr;
CollettIcons *CollettIcons::instance() {
    if (staticInstance == nullptr) {
        staticInstance = new CollettIcons();
        qDebug() << "Constructor: CollettIcons";
    }
    return staticInstance;
}

void CollettIcons::destroy() {
    if (staticInstance != nullptr) {
        delete CollettIcons::staticInstance;
    }
}

/**!
 * @brief Construct a CollettIcons object.
 *
 * The icon SVG data is from https://fonts.google.com/icons
 * Icon style: Filled
 */
CollettIcons::CollettIcons() {

    // format_align_center_black_24dp.svg
    m_svgData["alignCentre"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M7 15v2h10v-2H7zm-4 6h18v-2H3v2zm0-8h18v-2H3v2zm4-6v2h10V7H7zM3 3v2h18V3H3z'/>"
        "</svg>"
    );

    // format_align_justify_black_24dp.svg
    m_svgData["alignJustify"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M3 21h18v-2H3v2zm0-4h18v-2H3v2zm0-4h18v-2H3v2zm0-4h18V7H3v2zm0-6v2h18V3H3z'/>"
        "</svg>"
    );

    // format_align_left_black_24dp.svg
    m_svgData["alignLeft"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M15 15H3v2h12v-2zm0-8H3v2h12V7zM3 13h18v-2H3v2zm0 8h18v-2H3v2zM3 3v2h18V3H3z'/>"
        "</svg>"
    );

    // format_align_right_black_24dp.svg
    m_svgData["alignRight"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M3 21h18v-2H3v2zm6-4h12v-2H9v2zm-6-4h18v-2H3v2zm6-4h12V7H9v2zM3 3v2h18V3H3z'/>"
        "</svg>"
    );

    // inventory_2_black_24dp.svg
    m_svgData["archive"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' enable-background='new 0 0 24 24' height='24px' viewBox='0 0 24 24' width='24px' "
            "fill='%1' opacity='%2'>"
            "<rect fill='none' height='24' width='24'/>"
            "<path d='M20,2H4C3,2,2,2.9,2,4v3.01C2,7.73,2.43,8.35,3,8.7V20c0,1.1,1.1,2,2,2h14c0.9,0,2-0.9,2-2V8.7c0.57-0.35,1-0.97,"
            "1-1.69V4 C22,2.9,21,2,20,2z M15,14H9v-2h6V14z M20,7H4V4h16V7z'/>"
        "</svg>"
    );

    // format_bold_black_24dp.svg
    m_svgData["bold"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M15.6 10.79c.97-.67 1.65-1.77 1.65-2.79 0-2.26-1.75-4-4-4H7v14h7.04c2.09 0 3.71-1.7 3.71-3.79 0-1.52-.86-2.82"
            "-2.15-3.42zM10 6.5h3c.83 0 1.5.67 1.5 1.5s-.67 1.5-1.5 1.5h-3v-3zm3.5 9H10v-3h3.5c.83 0 1.5.67 1.5 1.5s-.67 1.5-1.5 1."
            "5z'/>"
        "</svg>"
    );

    // auto_stories_black_24dp.svg
    m_svgData["book"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0V0z' fill='none'/>"
            "<path d='M19 1l-5 5v11l5-4.5V1zM1 6v14.65c0 .25.25.5.5.5.1 0 .15-.05.25-.05C3.1 20.45 5.05 20 6.5 20c1.95 0 4.05.4 5.5"
            " 1.5V6c-1.45-1.1-3.55-1.5-5.5-1.5S2.45 4.9 1 6zm22 13.5V6c-.6-.45-1.25-.75-2-1v13.5c-1.1-.35-2.3-.5-3.5-.5-1.7 0-4.15."
            "65-5.5 1.5v2c1.35-.85 3.8-1.5 5.5-1.5 1.65 0 3.35.3 4.75 1.05.1.05.15.05.25.05.25 0 .5-.25.5-.5v-1.1z'/>"
        "</svg>"
    );

    // format_indent_increase_black_24dp.svg
    m_svgData["blockIndent"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M3 21h18v-2H3v2zM3 8v8l4-4-4-4zm8 9h10v-2H11v2zM3 3v2h18V3H3zm8 6h10V7H11v2zm0 4h10v-2H11v2z'/>"
        "</svg>"
    );

    // format_indent_decrease_black_24dp.svg
    m_svgData["blockOutdent"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M11 17h10v-2H11v2zm-8-5l4 4V8l-4 4zm0 9h18v-2H3v2zM3 3v2h18V3H3zm8 6h10V7H11v2zm0 4h10v-2H11v2z'/>"
        "</svg>"
    );

    // format_italic_black_24dp.svg
    m_svgData["italic"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px'  fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M10 4v3h2.21l-3.42 8H6v3h8v-3h-2.21l3.42-8H18V4z'/>"
        "</svg>"
    );

    // more_vert_black_24dp.svg
    m_svgData["more"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M12 8c1.1 0 2-.9 2-2s-.9-2-2-2-2 .9-2 2 .9 2 2 2zm0 2c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zm0 6c-1.1 0-"
            "2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2z'/>"
        "</svg>"
    );

    // settings_black_24dp.svg
    m_svgData["settings"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' enable-background='new 0 0 24 24' height='24px' viewBox='0 0 24 24' width='24px' "
            "fill='%1' opacity='%2'>"
            "<rect fill='none' height='24' width='24'/>"
            "<path d='M19.5,12c0-0.23-0.01-0.45-0.03-0.68l1.86-1.41c0.4-0.3,0.51-0.86,0.26-1.3l-1.87-3.23c-0.25-0.44-0.79-0.62-1.25"
            "-0.42 l-2.15,0.91c-0.37-0.26-0.76-0.49-1.17-0.68l-0.29-2.31C14.8,2.38,14.37,2,13.87,2h-3.73C9.63,2,9.2,2.38,9.14,2.88L"
            "8.85,5.19 c-0.41,0.19-0.8,0.42-1.17,0.68L5.53,4.96c-0.46-0.2-1-0.02-1.25,0.42L2.41,8.62c-0.25,0.44-0.14,0.99,0.26,1.3l"
            "1.86,1.41 C4.51,11.55,4.5,11.77,4.5,12s0.01,0.45,0.03,0.68l-1.86,1.41c-0.4,0.3-0.51,0.86-0.26,1.3l1.87,3.23c0.25,0.44,"
            "0.79,0.62,1.25,0.42 l2.15-0.91c0.37,0.26,0.76,0.49,1.17,0.68l0.29,2.31C9.2,21.62,9.63,22,10.13,22h3.73c0.5,0,0.93-0.38"
            ",0.99-0.88l0.29-2.31 c0.41-0.19,0.8-0.42,1.17-0.68l2.15,0.91c0.46,0.2,1,0.02,1.25-0.42l1.87-3.23c0.25-0.44,0.14-0.99-0"
            ".26-1.3l-1.86-1.41 C19.49,12.45,19.5,12.23,19.5,12z M12.04,15.5c-1.93,0-3.5-1.57-3.5-3.5s1.57-3.5,3.5-3.5s3.5,1.57,3.5"
            ",3.5S13.97,15.5,12.04,15.5z'/>"
        "</svg>"
    );

    // format_strikethrough_black_24dp.svg
    m_svgData["strikethrough"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M10 19h4v-3h-4v3zM5 4v3h5v3h4V7h5V4H5zM3 14h18v-2H3v2z'/>"
        "</svg>"
    );

    // format_underlined_black_24dp.svg
    m_svgData["underline"] = QLatin1String(
        "<svg xmlns='http://www.w3.org/2000/svg' height='24px' viewBox='0 0 24 24' width='24px' fill='%1' opacity='%2'>"
            "<path d='M0 0h24v24H0z' fill='none'/>"
            "<path d='M12 17c3.31 0 6-2.69 6-6V3h-2.5v8c0 1.93-1.57 3.5-3.5 3.5S8.5 12.93 8.5 11V3H6v8c0 3.31 2.69 6 6 6zm-7 2v2h14"
            "v-2H5z'/>"
        "</svg>"
    );
}

CollettIcons::~CollettIcons() {
    qDebug() << "Destructor: CollettIcons";
}

QIcon CollettIcons::icon(const QString &name) {
    QColor col = qApp->palette().buttonText().color();
    QString svg = m_svgData[name].arg(col.name(QColor::HexRgb)).arg("0.7");
    return QIcon(new SVGIconEngine(svg));
}

} // namespace Collett
