/*
** Collett – Core Icon Repository
** ==============================
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

#include "icons.h"
#include "svgiconengine.h"

#include <QIcon>
#include <QColor>
#include <QDebug>
#include <QString>
#include <QPalette>
#include <QApplication>

namespace Collett {

CollettIcons *CollettIcons::staticInstance = nullptr;
CollettIcons *CollettIcons::instance() {
    if (staticInstance == nullptr) {
        qDebug() << "Constructor: CollettIcons";
        staticInstance = new CollettIcons();
    }
    return staticInstance;
}

void CollettIcons::destroy() {
    if (staticInstance != nullptr) {
        qDebug() << "Destructor: Static CollettIcons";
        delete CollettIcons::staticInstance;
    }
}

/**!
 * @brief Construct a CollettIcons object.
 *
 * The icon SVG data is from Font Awesome
 * Browse: https://fontawesome.com/v6/search?o=r&m=free&s=regular
 */
CollettIcons::CollettIcons() {

    // Default Style
    QColor normal = QColor(qApp->palette().buttonText().color());
    QColor active = QColor(qApp->palette().highlight().color());
    normal.setAlphaF(0.7);
    active.setAlphaF(0.9);
    this->setIconStyle(normal, active);

    // File I/O
    // ========

    // folder-open-regular.svg
    m_svgPath["open"] = QByteArray(
        "M384 480l48 0c11.4 0 21.9-6 27.6-15.9l112-192c5.8-9.9 5.8-22.1 .1-32.1S555.5 224 544 224l"
        "-400 0c-11.4 0-21.9 6-27.6 15.9L48 357.1 48 96c0-8.8 7.2-16 16-16l117.5 0c4.2 0 8.3 1.7 1"
        "1.3 4.7l26.5 26.5c21 21 49.5 32.8 79.2 32.8L416 144c8.8 0 16 7.2 16 16l0 32 48 0 0-32c0-3"
        "5.3-28.7-64-64-64L298.5 96c-17 0-33.3-6.7-45.3-18.7L226.7 50.7c-12-12-28.3-18.7-45.3-18.7"
        "L64 32C28.7 32 0 60.7 0 96L0 416c0 35.3 28.7 64 64 64l23.7 0L384 480z"
    );

    // hard-drive-regular.svg
    m_svgPath["save"] = QByteArray(
        "M64 80c-8.8 0-16 7.2-16 16l0 162c5.1-1.3 10.5-2 16-2l384 0c5.5 0 10.9 .7 16 2l0-162c0-8.8"
        "-7.2-16-16-16L64 80zM48 320l0 96c0 8.8 7.2 16 16 16l384 0c8.8 0 16-7.2 16-16l0-96c0-8.8-7"
        ".2-16-16-16L64 304c-8.8 0-16 7.2-16 16zM0 320L0 96C0 60.7 28.7 32 64 32l384 0c35.3 0 64 2"
        "8.7 64 64l0 224 0 96c0 35.3-28.7 64-64 64L64 480c-35.3 0-64-28.7-64-64l0-96zm280 48a24 24"
        " 0 1 1 48 0 24 24 0 1 1 -48 0zm120-24a24 24 0 1 1 0 48 24 24 0 1 1 0-48z"
    );

}

CollettIcons::~CollettIcons() {
    qDebug() << "Destructor: CollettIcons";
}

void CollettIcons::setIconStyle(const QColor &normal, const QColor &active) {
    m_svgNormal = QByteArray("<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 512 512' fill='")
        .append(normal.name(QColor::HexRgb).toLatin1())
        .append("' opacity='")
        .append(QByteArray().setNum(normal.alphaF()))
        .append("'><path d='{data}'/></svg>");

    m_svgActive = QByteArray("<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 512 512' fill='")
        .append(active.name(QColor::HexRgb).toLatin1())
        .append("' opacity='")
        .append(QByteArray().setNum(active.alphaF()))
        .append("'><path d='{data}'/></svg>");
}

QIcon CollettIcons::icon(const QString &name) {
    return QIcon(
        new SVGIconEngine(
            QByteArray().append(m_svgNormal).replace("{data}", m_svgPath[name]),
            QByteArray().append(m_svgActive).replace("{data}", m_svgPath[name])
        )
    );
}

bool CollettIcons::contains(const QString &name) {
    return m_svgPath.contains(name);
}

} // namespace Collett
