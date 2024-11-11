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
    m_svgSize["open"] = QSize(576, 512);
    m_svgPath["open"] = QByteArray(
        "M384 480l48 0c11.4 0 21.9-6 27.6-15.9l112-192c5.8-9.9 5.8-22.1 .1-32.1S555.5 224 544 224l"
        "-400 0c-11.4 0-21.9 6-27.6 15.9L48 357.1 48 96c0-8.8 7.2-16 16-16l117.5 0c4.2 0 8.3 1.7 1"
        "1.3 4.7l26.5 26.5c21 21 49.5 32.8 79.2 32.8L416 144c8.8 0 16 7.2 16 16l0 32 48 0 0-32c0-3"
        "5.3-28.7-64-64-64L298.5 96c-17 0-33.3-6.7-45.3-18.7L226.7 50.7c-12-12-28.3-18.7-45.3-18.7"
        "L64 32C28.7 32 0 60.7 0 96L0 416c0 35.3 28.7 64 64 64l23.7 0L384 480z"
    );

    // hard-drive-regular.svg
    m_svgSize["save"] = QSize(512, 512);
    m_svgPath["save"] = QByteArray(
        "M64 80c-8.8 0-16 7.2-16 16l0 162c5.1-1.3 10.5-2 16-2l384 0c5.5 0 10.9 .7 16 2l0-162c0-8.8"
        "-7.2-16-16-16L64 80zM48 320l0 96c0 8.8 7.2 16 16 16l384 0c8.8 0 16-7.2 16-16l0-96c0-8.8-7"
        ".2-16-16-16L64 304c-8.8 0-16 7.2-16 16zM0 320L0 96C0 60.7 28.7 32 64 32l384 0c35.3 0 64 2"
        "8.7 64 64l0 224 0 96c0 35.3-28.7 64-64 64L64 480c-35.3 0-64-28.7-64-64l0-96zm280 48a24 24"
        " 0 1 1 48 0 24 24 0 1 1 -48 0zm120-24a24 24 0 1 1 0 48 24 24 0 1 1 0-48z"
    );

    // Text Formatting
    // ===============

    // Paragraph Format

    // heading-solid.svg
    m_svgSize["heading"] = QSize(448, 512);
    m_svgPath["heading"] = QByteArray(
        "M0 64C0 46.3 14.3 32 32 32l48 0 48 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-16 0 0 112 224 "
        "0 0-112-16 0c-17.7 0-32-14.3-32-32s14.3-32 32-32l48 0 48 0c17.7 0 32 14.3 32 32s-14.3 32-"
        "32 32l-16 0 0 144 0 176 16 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-48 0-48 0c-17.7 0-32-14"
        ".3-32-32s14.3-32 32-32l16 0 0-144-224 0 0 144 16 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-4"
        "8 0-48 0c-17.7 0-32-14.3-32-32s14.3-32 32-32l16 0 0-176L48 96 32 96C14.3 96 0 81.7 0 64z"
    );

    // paragraph-solid.svg
    m_svgSize["paragraph"] = QSize(448, 512);
    m_svgPath["paragraph"] = QByteArray(
        "M192 32l64 0 160 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-32 0 0 352c0 17.7-14.3 32-32 32s-"
        "32-14.3-32-32l0-352-32 0 0 352c0 17.7-14.3 32-32 32s-32-14.3-32-32l0-96-32 0c-88.4 0-160-"
        "71.6-160-160s71.6-160 160-160z"
    );

    // Char Format

    // bold-solid.svg
    m_svgSize["bold"] = QSize(384, 512);
    m_svgPath["bold"] = QByteArray(
        "M0 64C0 46.3 14.3 32 32 32l48 0 16 0 128 0c70.7 0 128 57.3 128 128c0 31.3-11.3 60.1-30 82"
        ".3c37.1 22.4 62 63.1 62 109.7c0 70.7-57.3 128-128 128L96 480l-16 0-48 0c-17.7 0-32-14.3-3"
        "2-32s14.3-32 32-32l16 0 0-160L48 96 32 96C14.3 96 0 81.7 0 64zM224 224c35.3 0 64-28.7 64-"
        "64s-28.7-64-64-64L112 96l0 128 112 0zM112 288l0 128 144 0c35.3 0 64-28.7 64-64s-28.7-64-6"
        "4-64l-32 0-112 0z"
    );

    // italic-solid.svg
    m_svgSize["italic"] = QSize(384, 512);
    m_svgPath["italic"] = QByteArray(
        "M128 64c0-17.7 14.3-32 32-32l192 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-58.7 0L160 416l64"
        " 0c17.7 0 32 14.3 32 32s-14.3 32-32 32L32 480c-17.7 0-32-14.3-32-32s14.3-32 32-32l58.7 0L"
        "224 96l-64 0c-17.7 0-32-14.3-32-32z"
    );

    // underline-solid.svg
    m_svgSize["underline"] = QSize(448, 512);
    m_svgPath["underline"] = QByteArray(
        "M16 64c0-17.7 14.3-32 32-32l96 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-16 0 0 128c0 53 43 "
        "96 96 96s96-43 96-96l0-128-16 0c-17.7 0-32-14.3-32-32s14.3-32 32-32l96 0c17.7 0 32 14.3 3"
        "2 32s-14.3 32-32 32l-16 0 0 128c0 88.4-71.6 160-160 160s-160-71.6-160-160L64 96 48 96C30."
        "3 96 16 81.7 16 64zM0 448c0-17.7 14.3-32 32-32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 32L"
        "32 480c-17.7 0-32-14.3-32-32z"
    );

    // strikethrough-solid.svg
    m_svgSize["strikethrough"] = QSize(512, 512);
    m_svgPath["strikethrough"] = QByteArray(
        "M161.3 144c3.2-17.2 14-30.1 33.7-38.6c21.1-9 51.8-12.3 88.6-6.5c11.9 1.9 48.8 9.1 60.1 12"
        "c17.1 4.5 34.6-5.6 39.2-22.7s-5.6-34.6-22.7-39.2c-14.3-3.8-53.6-11.4-66.6-13.4c-44.7-7-88"
        ".3-4.2-123.7 10.9c-36.5 15.6-64.4 44.8-71.8 87.3c-.1 .6-.2 1.1-.2 1.7c-2.8 23.9 .5 45.6 1"
        "0.1 64.6c4.5 9 10.2 16.9 16.7 23.9L32 224c-17.7 0-32 14.3-32 32s14.3 32 32 32l448 0c17.7 "
        "0 32-14.3 32-32s-14.3-32-32-32l-209.9 0-.4-.1-1.1-.3c-36-10.8-65.2-19.6-85.2-33.1c-9.3-6."
        "3-15-12.6-18.2-19.1c-3.1-6.1-5.2-14.6-3.8-27.4zM348.9 337.2c2.7 6.5 4.4 15.8 1.9 30.1c-3 "
        "17.6-13.8 30.8-33.9 39.4c-21.1 9-51.7 12.3-88.5 6.5c-18-2.9-49.1-13.5-74.4-22.1c-5.6-1.9-"
        "11-3.7-15.9-5.4c-16.8-5.6-34.9 3.5-40.5 20.3s3.5 34.9 20.3 40.5c3.6 1.2 7.9 2.7 12.7 4.3c"
        "0 0 0 0 0 0s0 0 0 0c24.9 8.5 63.6 21.7 87.6 25.6c0 0 0 0 0 0l.2 0c44.7 7 88.3 4.2 123.7-1"
        "0.9c36.5-15.6 64.4-44.8 71.8-87.3c3.6-21 2.7-40.4-3.1-58.1l-75.7 0c7 5.6 11.4 11.2 13.9 1"
        "7.2z"
    );

    // superscript-solid.svg
    m_svgSize["superscript"] = QSize(512, 512);
    m_svgPath["superscript"] = QByteArray(
        "M480 32c0-11.1-5.7-21.4-15.2-27.2s-21.2-6.4-31.1-1.4l-32 16c-15.8 7.9-22.2 27.1-14.3 42.9"
        "C393 73.5 404.3 80 416 80l0 80c-17.7 0-32 14.3-32 32s14.3 32 32 32l32 0 32 0c17.7 0 32-14"
        ".3 32-32s-14.3-32-32-32l0-128zM32 64C14.3 64 0 78.3 0 96s14.3 32 32 32l15.3 0 89.6 128L47"
        ".3 384 32 384c-17.7 0-32 14.3-32 32s14.3 32 32 32l32 0c10.4 0 20.2-5.1 26.2-13.6L176 311."
        "8l85.8 122.6c6 8.6 15.8 13.6 26.2 13.6l32 0c17.7 0 32-14.3 32-32s-14.3-32-32-32l-15.3 0L2"
        "15.1 256l89.6-128 15.3 0c17.7 0 32-14.3 32-32s-14.3-32-32-32l-32 0c-10.4 0-20.2 5.1-26.2 "
        "13.6L176 200.2 90.2 77.6C84.2 69.1 74.4 64 64 64L32 64z"
    );

    // subscript-solid.svg
    m_svgSize["subscript"] = QSize(512, 512);
    m_svgPath["subscript"] = QByteArray(
        "M32 64C14.3 64 0 78.3 0 96s14.3 32 32 32l15.3 0 89.6 128L47.3 384 32 384c-17.7 0-32 14.3-"
        "32 32s14.3 32 32 32l32 0c10.4 0 20.2-5.1 26.2-13.6L176 311.8l85.8 122.6c6 8.6 15.8 13.6 2"
        "6.2 13.6l32 0c17.7 0 32-14.3 32-32s-14.3-32-32-32l-15.3 0L215.1 256l89.6-128 15.3 0c17.7 "
        "0 32-14.3 32-32s-14.3-32-32-32l-32 0c-10.4 0-20.2 5.1-26.2 13.6L176 200.2 90.2 77.6C84.2 "
        "69.1 74.4 64 64 64L32 64zM480 320c0-11.1-5.7-21.4-15.2-27.2s-21.2-6.4-31.1-1.4l-32 16c-15"
        ".8 7.9-22.2 27.1-14.3 42.9C393 361.5 404.3 368 416 368l0 80c-17.7 0-32 14.3-32 32s14.3 32"
        " 32 32l32 0 32 0c17.7 0 32-14.3 32-32s-14.3-32-32-32l0-128z"
    );

    // Alignment

    // align-left-solid.svg
    m_svgSize["align-left"] = QSize(448, 512);
    m_svgPath["align-left"] = QByteArray(
        "M288 64c0 17.7-14.3 32-32 32L32 96C14.3 96 0 81.7 0 64S14.3 32 32 32l224 0c17.7 0 32 14.3"
        " 32 32zm0 256c0 17.7-14.3 32-32 32L32 352c-17.7 0-32-14.3-32-32s14.3-32 32-32l224 0c17.7 "
        "0 32 14.3 32 32zM0 192c0-17.7 14.3-32 32-32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 32L32 "
        "224c-17.7 0-32-14.3-32-32zM448 448c0 17.7-14.3 32-32 32L32 480c-17.7 0-32-14.3-32-32s14.3"
        "-32 32-32l384 0c17.7 0 32 14.3 32 32z"
    );

    // align-center-solid.svg
    m_svgSize["align-center"] = QSize(448, 512);
    m_svgPath["align-center"] = QByteArray(
        "M352 64c0-17.7-14.3-32-32-32L128 32c-17.7 0-32 14.3-32 32s14.3 32 32 32l192 0c17.7 0 32-1"
        "4.3 32-32zm96 128c0-17.7-14.3-32-32-32L32 160c-17.7 0-32 14.3-32 32s14.3 32 32 32l384 0c1"
        "7.7 0 32-14.3 32-32zM0 448c0 17.7 14.3 32 32 32l384 0c17.7 0 32-14.3 32-32s-14.3-32-32-32"
        "L32 416c-17.7 0-32 14.3-32 32zM352 320c0-17.7-14.3-32-32-32l-192 0c-17.7 0-32 14.3-32 32s"
        "14.3 32 32 32l192 0c17.7 0 32-14.3 32-32z"
    );

    // align-right-solid.svg
    m_svgSize["align-right"] = QSize(448, 512);
    m_svgPath["align-right"] = QByteArray(
        "M448 64c0 17.7-14.3 32-32 32L192 96c-17.7 0-32-14.3-32-32s14.3-32 32-32l224 0c17.7 0 32 1"
        "4.3 32 32zm0 256c0 17.7-14.3 32-32 32l-224 0c-17.7 0-32-14.3-32-32s14.3-32 32-32l224 0c17"
        ".7 0 32 14.3 32 32zM0 192c0-17.7 14.3-32 32-32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 32L"
        "32 224c-17.7 0-32-14.3-32-32zM448 448c0 17.7-14.3 32-32 32L32 480c-17.7 0-32-14.3-32-32s1"
        "4.3-32 32-32l384 0c17.7 0 32 14.3 32 32z"
    );

    // align-justify-solid.svg
    m_svgSize["align-justify"] = QSize(448, 512);
    m_svgPath["align-justify"] = QByteArray(
        "M448 64c0-17.7-14.3-32-32-32L32 32C14.3 32 0 46.3 0 64S14.3 96 32 96l384 0c17.7 0 32-14.3"
        " 32-32zm0 256c0-17.7-14.3-32-32-32L32 288c-17.7 0-32 14.3-32 32s14.3 32 32 32l384 0c17.7 "
        "0 32-14.3 32-32zM0 192c0 17.7 14.3 32 32 32l384 0c17.7 0 32-14.3 32-32s-14.3-32-32-32L32 "
        "160c-17.7 0-32 14.3-32 32zM448 448c0-17.7-14.3-32-32-32L32 416c-17.7 0-32 14.3-32 32s14.3"
        " 32 32 32l384 0c17.7 0 32-14.3 32-32z"
    );

    // Block Format

    // line-indent-solid.svg
    m_svgSize["line-indent"] = QSize(448, 512);
    m_svgPath["line-indent"] = QByteArray(
        "m192 32c-17.7 0-32 14.3-32 32s14.3 32 32 32h224c17.7 0 32-14.3 32-32s-14.3-32-32-32h-224z"
        "m-160 128c-17.7 0-32 14.3-32 32s14.3 32 32 32h384c17.7 0 32-14.3 32-32s-14.3-32-32-32h-38"
        "4zm0 128c-17.7 0-32 14.3-32 32s14.3 32 32 32h384c17.7 0 32-14.3 32-32s-14.3-32-32-32h-384"
        "zm0 128c-17.7 0-32 14.3-32 32s14.3 32 32 32h384c17.7 0 32-14.3 32-32s-14.3-32-32-32h-384z"
    );

    // indent-solid.svg
    m_svgSize["indent"] = QSize(448, 512);
    m_svgPath["indent"] = QByteArray(
        "M0 64C0 46.3 14.3 32 32 32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 32L32 96C14.3 96 0 81.7"
        " 0 64zM192 192c0-17.7 14.3-32 32-32l192 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-192 0c-17."
        "7 0-32-14.3-32-32zm32 96l192 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-192 0c-17.7 0-32-14.3"
        "-32-32s14.3-32 32-32zM0 448c0-17.7 14.3-32 32-32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 3"
        "2L32 480c-17.7 0-32-14.3-32-32zM127.8 268.6L25.8 347.9C15.3 356.1 0 348.6 0 335.3L0 176.7"
        "c0-13.3 15.3-20.8 25.8-12.6l101.9 79.3c8.2 6.4 8.2 18.9 0 25.3z"
    );

    // outdent-solid.svg
    m_svgSize["outdent"] = QSize(448, 512);
    m_svgPath["outdent"] = QByteArray(
        "M0 64C0 46.3 14.3 32 32 32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 32L32 96C14.3 96 0 81.7"
        " 0 64zM192 192c0-17.7 14.3-32 32-32l192 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-192 0c-17."
        "7 0-32-14.3-32-32zm32 96l192 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-192 0c-17.7 0-32-14.3"
        "-32-32s14.3-32 32-32zM0 448c0-17.7 14.3-32 32-32l384 0c17.7 0 32 14.3 32 32s-14.3 32-32 3"
        "2L32 480c-17.7 0-32-14.3-32-32zM.2 268.6c-8.2-6.4-8.2-18.9 0-25.3l101.9-79.3c10.5-8.2 25."
        "8-.7 25.8 12.6l0 158.6c0 13.3-15.3 20.8-25.8 12.6L.2 268.6z"
    );

    // Text Tools

    // highlighter-solid.svg
    m_svgSize["highlighter"] = QSize(576, 512);
    m_svgPath["highlighter"] = QByteArray(
        "M315 315l158.4-215L444.1 70.6 229 229 315 315zm-187 5s0 0 0 0l0-71.7c0-15.3 7.2-29.6 19.5"
        "-38.6L420.6 8.4C428 2.9 437 0 446.2 0c11.4 0 22.4 4.5 30.5 12.6l54.8 54.8c8.1 8.1 12.6 19"
        " 12.6 30.5c0 9.2-2.9 18.2-8.4 25.6L334.4 396.5c-9 12.3-23.4 19.5-38.6 19.5L224 416l-25.4 "
        "25.4c-12.5 12.5-32.8 12.5-45.3 0l-50.7-50.7c-12.5-12.5-12.5-32.8 0-45.3L128 320zM7 466.3l"
        "63-63 70.6 70.6-31 31c-4.5 4.5-10.6 7-17 7L24 512c-13.3 0-24-10.7-24-24l0-4.7c0-6.4 2.5-1"
        "2.5 7-17z"
    );

    // spell-check-solid.svg
    m_svgSize["spell-check"] = QSize(576, 512);
    m_svgPath["spell-check"] = QByteArray(
        "M112 0C99.1 0 87.4 7.8 82.5 19.7l-66.7 160-13.3 32c-6.8 16.3 .9 35 17.2 41.8s35-.9 41.8-1"
        "7.2L66.7 224l90.7 0 5.1 12.3c6.8 16.3 25.5 24 41.8 17.2s24-25.5 17.2-41.8l-13.3-32-66.7-1"
        "60C136.6 7.8 124.9 0 112 0zm18.7 160l-37.3 0L112 115.2 130.7 160zM256 32l0 96 0 96c0 17.7"
        " 14.3 32 32 32l80 0c44.2 0 80-35.8 80-80c0-23.1-9.8-43.8-25.4-58.4c6-11.2 9.4-24 9.4-37.6"
        "c0-44.2-35.8-80-80-80L288 0c-17.7 0-32 14.3-32 32zm96 64l-32 0 0-32 32 0c8.8 0 16 7.2 16 "
        "16s-7.2 16-16 16zm-32 64l32 0 16 0c8.8 0 16 7.2 16 16s-7.2 16-16 16l-48 0 0-32zM566.6 310"
        ".6c12.5-12.5 12.5-32.8 0-45.3s-32.8-12.5-45.3 0L352 434.7l-73.4-73.4c-12.5-12.5-32.8-12.5"
        "-45.3 0s-12.5 32.8 0 45.3l96 96c12.5 12.5 32.8 12.5 45.3 0l192-192z"
    );

}

CollettIcons::~CollettIcons() {
    qDebug() << "Destructor: CollettIcons";
}

void CollettIcons::setIconStyle(const QColor &normal, const QColor &active) {
    m_svgNormal = QByteArray("<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 {size}' fill='")
        .append(normal.name(QColor::HexRgb).toLatin1())
        .append("' opacity='")
        .append(QByteArray().setNum(normal.alphaF()))
        .append("'><path d='{data}'/></svg>");

    m_svgActive = QByteArray("<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 {size}' fill='")
        .append(active.name(QColor::HexRgb).toLatin1())
        .append("' opacity='")
        .append(QByteArray().setNum(active.alphaF()))
        .append("'><path d='{data}'/></svg>");
}

QIcon CollettIcons::icon(const QString &name) {
    QByteArray path = m_svgPath[name];
    QSize size = m_svgSize[name];
    QByteArray box = QByteArray().setNum(size.width()).append(QByteArray().setNum(size.height()));
    return QIcon(
        new SVGIconEngine(
            QByteArray().append(m_svgNormal).replace("{data}", path).replace("{size}", box),
            QByteArray().append(m_svgActive).replace("{data}", path).replace("{size}", box)
        )
    );
}

bool CollettIcons::contains(const QString &name) {
    return m_svgPath.contains(name);
}

} // namespace Collett
