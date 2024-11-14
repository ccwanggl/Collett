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

#include "project.h"
#include "storage.h"

#include <QDateTime>
#include <QJsonObject>

namespace Collett {

/**
 * Class Constructor/Destructor
 * ============================
 */

Project::Project() {
    m_createdTime = QDateTime::currentDateTime().toString(Qt::ISODate);
}

Project::~Project() {
    qDebug() << "Destructor: Project";
}

/**
 * Class Methods
 * =============
 */

bool Project::openProject(const QString &path) {

    if (!m_document.isEmpty()) {
        qWarning() << "Project content already loaded";
        return false;
    }

    m_store = new Storage(path, false);
    qInfo() << "Loading Project:" << m_store->projectPath();
    if (!m_store->isValid()) {
        qWarning() << "Cannot load project from this path";
        return false;
    }

    QJsonObject jData;
    if (!m_store->readProject(jData)) {
        m_lastError = m_store->lastError();
        return false;
    }

    QJsonObject jMeta = jData.value(QLatin1String("c:meta")).toObject();
    QJsonObject jProject = jData.value(QLatin1String("c:project")).toObject();
    QJsonObject jSettings = jData.value(QLatin1String("c:settings")).toObject();

    // Project Meta
    m_createdTime = Storage::getJsonString(jMeta, QLatin1String("m:created"), "Unknown");

    // Project Settings
    m_projectName = Storage::getJsonString(jProject, QLatin1String("u:name"), tr("Unnamed Project"));

    // Project Content
    m_document = jData.value(QLatin1String("u:document")).toObject();
    m_isValid = true;

    if (!jMeta.isEmpty()) qDebug() << "Found meta section";
    if (!jProject.isEmpty()) qDebug() << "Found project section";
    if (!jSettings.isEmpty()) qDebug() << "Found settings section";
    if (!m_document.isEmpty()) qDebug() << "Found document section";

    return true;
}

bool Project::saveProject() {

    if (m_store == nullptr) {
        qWarning() << "Project storage not initialised, cannot save";
        return false;
    }

    qInfo() << "Saving Project:" << m_store->projectPath();
    if (!m_store->isValid()) {
        qWarning() << "Project storage invalid, cannot save";
        return false;
    }

    QJsonObject jData, jMeta, jProject, jSettings;

    // Project Meta
    jMeta[QLatin1String("m:version")] = QString(COL_VERSION_STR);
    jMeta[QLatin1String("m:created")] = m_createdTime;
    jMeta[QLatin1String("m:updated")] = QDateTime::currentDateTime().toString(Qt::ISODate);

    // Project Settings
    jProject[QLatin1String("u:name")] = m_projectName;

    // Root Object
    jData[QLatin1String("c:format")] = "CollettProject";
    jData[QLatin1String("c:meta")] = jMeta;
    jData[QLatin1String("c:project")] = jProject;
    jData[QLatin1String("c:settings")] = jSettings;
    jData[QLatin1String("u:document")] = m_document;

    if (!m_store->writeProject(jData)) {
        m_lastError = m_store->lastError();
        return false;
    }

    return true;
}

bool Project::saveProjectAs(const QString &path) {
    m_store = new Storage(path, false);
    m_isValid = true;
    return this->saveProject();
}

/**
 * Class Setters
 * =============
 */

void Project::setProjectName(const QString &name) {
    m_projectName = name.simplified();
}

/**
 * Class Getters
 * =============
 */

bool Project::isValid() const {
    return m_isValid;
}

QString Project::projectName() const {
    return m_projectName;
}

Storage *Project::store() {
    return m_store;
}

QJsonObject Project::document() const {
    return m_document;
}

/**
 * Error Handling
 * ==============
 */

bool Project::hasError() const {
    return !m_lastError.isEmpty();
}

QString Project::lastError() const {
    return m_lastError;
}

} // namespace Collett
