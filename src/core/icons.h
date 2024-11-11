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

#ifndef COLLETT_ICONS_H
#define COLLETT_ICONS_H

#include <QByteArray>
#include <QHash>
#include <QIcon>
#include <QObject>
#include <QSize>
#include <QString>

namespace Collett {

class CollettIcons : public QObject
{
    Q_OBJECT

public:
    static CollettIcons *instance();
    static void destroy();

    explicit CollettIcons();
    ~CollettIcons();

    void setIconStyle(const QColor &normal, const QColor &active);

    QIcon icon(const QString &name);
    bool contains(const QString &name);

private:
    static CollettIcons *staticInstance;

    QByteArray m_svgNormal = "<svg viewBox='0 0 512 512'><path d='{data}'/></svg>";
    QByteArray m_svgActive = "<svg viewBox='0 0 512 512'><path d='{data}'/></svg>";
    QHash<QString, QByteArray> m_svgPath;
    QHash<QString, QSize>      m_svgSize;

};
} // namespace Collett

#endif // COLLETT_ICONS_H
