/*
** Collett – Project Class
** =======================
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

#ifndef COLLETT_PROJECT_H
#define COLLETT_PROJECT_H

#include "collett.h"
#include "storage.h"

#include <QJsonObject>

namespace Collett {

class Project : public QObject
{
    Q_OBJECT

public:
    explicit Project();
    ~Project();

    // Class Methods

    bool openProject(const QString &path);
    bool saveProject();
    bool saveProjectAs(const QString &path);

    // Class Setters

    void setProjectName(const QString &name);

    // Class Getters

    bool isValid() const;

    QString projectName() const;
    Storage *store();

    QJsonObject document() const;

    // Error Handling

    bool hasError() const;
    QString lastError() const;

private:
    bool     m_isValid = false;
    QString  m_lastError = "";
    Storage *m_store = nullptr;

    // Project Meta

    QString m_collettVersion = "";
    QString m_projectVersion = "";
    QString m_createdTime = "";

    // Project Settings

    QString m_projectName = "New Project";

    // Project Content

    QJsonObject m_document;

    // File Load & Save

    bool loadProjectStructure();
    bool saveProjectStructure();

};
} // namespace Collett

#endif // COLLETT_PROJECT_H
